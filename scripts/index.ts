import fs from "fs";
import path from "path";
import CodeStream from "textstreamjs";
import { Define, DefineType, IPair, buildDefines, zipDefines } from "./defines";

(async () => {
    const cs = new CodeStream();
    cs.write('#include "Constants.h"\n');
    cs.write('#include "Arguments.h"\n\n');
    cs.write("#include <zipint.h>\n\n");
    const defineSet = [
        {
            defines: buildDefines([
                {
                    constants: ["SEEK_SET", "SEEK_CUR", "SEEK_END"]
                }
            ]).defines,
            name: "NativeConstant",
            outputVariableType: "int"
        },
        {
            defines: buildDefines(zipDefines).defines,
            name: "ZipConstant",
            outputVariableType: "zip_flags_t"
        },
        {
            defines: buildDefines([
                /**
                 * ZIP_STAT_*
                 */
                {
                    bitwise: true,
                    constants: [
                        "ZIP_STAT_NAME",
                        "ZIP_STAT_INDEX",
                        "ZIP_STAT_SIZE",
                        "ZIP_STAT_COMP_SIZE",
                        "ZIP_STAT_MTIME",
                        "ZIP_STAT_CRC",
                        "ZIP_STAT_COMP_METHOD",
                        "ZIP_STAT_ENCRYPTION_METHOD",
                        "ZIP_STAT_FLAGS"
                    ]
                }
            ]).defines,
            name: "ZipStatFlag",
            outputVariableType: "zip_flags_t"
        }
    ].map(({ name, ...props }) => ({
        ...props,
        name,
        setFunctionName: `Set${name}s`,
        convertFunctionName: `Convert${name}`,
        getBindingValueFunctionName: `GetBinding${name}`
    }));
    cs.write(
        "v8::Local<v8::Object> GetOrCreateConstants(v8::Local<v8::Object> target) {\n",
        () => {
            cs.write(
                'const auto key = Nan::New("constants").ToLocalChecked();\n'
            );
            cs.write("v8::Local<v8::Object> constants;\n");
            cs.write(
                "if(Nan::HasOwnProperty(target, key).FromJust()) {\n",
                () => {
                    cs.write(
                        "constants = Nan::To<v8::Object>(Nan::Get(target, key).ToLocalChecked()).ToLocalChecked();\n"
                    );
                },
                "} else {\n"
            );
            cs.indentBlock(() => {
                cs.write("constants = Nan::New<v8::Object>();\n");
                cs.write("Nan::Set(target, key, constants);\n");
            });
            cs.write("}\n");
            cs.write("return constants;\n");
        },
        "}\n"
    );
    for (const def of defineSet) {
        const {
            setFunctionName,
            convertFunctionName,
            getBindingValueFunctionName,
            defines,
            outputVariableType
        } = def;
        const pairs = createPairArray(defines);
        cs.write(
            `void ${setFunctionName}(v8::Local<v8::Object> exports) {\n`,
            () => {
                cs.write("auto constants = GetOrCreateConstants(exports);\n");
                cs.write("v8::Local<v8::String> key;\n");
                for (const pair of pairs) {
                    cs.write(
                        `key = Nan::New("${pair.name}").ToLocalChecked();\n`
                    );
                    cs.write(
                        "if(Nan::HasOwnProperty(constants, key).FromJust()) {\n",
                        () => {
                            cs.write(
                                `${createNanThrowCall(
                                    '"Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))'
                                )}\n`
                            );
                            cs.write("return;\n");
                        },
                        "}\n"
                    );
                    cs.write(
                        `Nan::Set(constants, key, Nan::New<v8::Uint32>(${pair.value}));\n`
                    );
                }
                cs.write(
                    `Nan::Set(exports, Nan::New("constants").ToLocalChecked(), constants);\n`
                );
            },
            "}\n"
        );
        cs.write(
            `bool ${convertFunctionName}(Nan::NAN_METHOD_ARGS_TYPE& info, const int&& index, ${outputVariableType}& out) {\n`,
            () => {
                cs.write('Arguments args("libzipflags",info);\n');
                cs.write(
                    'if(!args.AssertArgumentType("Uint32", index, Arguments::IsUint32)) {\n',
                    () => {
                        cs.write("return false;\n");
                    },
                    "}\n"
                );
                cs.write(
                    "uint32_t val = Nan::To<v8::Uint32>(info[index]).ToLocalChecked()->Value();\n"
                );
                for (const d of defines) {
                    switch (d.type) {
                        case DefineType.Flags:
                            for (const v of d.values) {
                                cs.write(`// ${v.name}\n`);
                            }
                            cs.write("if(");
                            for (const v of d.values) {
                                cs.append(`val & ${v.value}`);
                                if (v !== d.values[d.values.length - 1]) {
                                    cs.append(" || ");
                                }
                            }
                            cs.append(") {\n");
                            cs.indentBlock(() => {
                                cs.write("out = 0;\n");
                                for (const f of d.values) {
                                    cs.write(
                                        `if(val & ${f.value}) {\n`,
                                        () => {
                                            cs.write(`out |= ${f.name};\n`);
                                            cs.write(`val &= ~${f.value};\n`);
                                        },
                                        "}\n"
                                    );
                                }
                                cs.write(
                                    "if(val != 0) {\n",
                                    () => {
                                        cs.write(
                                            `${createNanThrowCall(
                                                '"Failed to convert constant value to libzip constant due to invalid remaining flags: " + std::to_string(val)'
                                            )}\n`
                                        );
                                        cs.write("return false;\n");
                                    },
                                    "}\n"
                                );
                                cs.write("return true;\n");
                            });
                            cs.write("}\n");
                            break;
                        case DefineType.Constant:
                            cs.write(
                                `if(val == ${d.value}) {\n`,
                                () => {
                                    cs.write(`out = ${d.name};\n`);
                                    cs.write("return true;\n");
                                },
                                "}\n"
                            );
                            break;
                    }
                }
                cs.write(
                    "if(val != 0) {\n",
                    () => {
                        cs.write(
                            `${createNanThrowCall(
                                '"Failed to convert constant value to libzip constant: " + std::to_string(val)'
                            )}\n`
                        );
                        cs.write("return false;\n");
                    },
                    "}\n"
                );
                cs.write("out = 0;\n");
                cs.write("return true;\n");
            },
            "}\n"
        );
        cs.write(
            `bool ${getBindingValueFunctionName}(const ${outputVariableType}& value, v8::Local<v8::Uint32>& out) {\n`,
            () => {
                if (defines.some((d) => d.type === DefineType.Flags)) {
                    cs.write("uint32_t v;\n");
                }
                for (const d of defines) {
                    switch (d.type) {
                        case DefineType.Flags:
                            cs.write(
                                "if(\n",
                                () => {
                                    for (const v of d.values) {
                                        cs.write(`(value & ${v.name})`);
                                        if (
                                            v !== d.values[d.values.length - 1]
                                        ) {
                                            cs.append(" ||");
                                        }
                                        cs.append("\n");
                                    }
                                },
                                ") {\n"
                            );
                            cs.indentBlock(() => {
                                cs.write("v = 0;\n");
                                for (const v of d.values) {
                                    cs.write(
                                        `if(value & ${v.name}) {\n`,
                                        () => {
                                            cs.write(`v |= ${v.value};\n`);
                                        },
                                        "}\n"
                                    );
                                }
                                cs.write("out = Nan::New<v8::Uint32>(v);\n");
                                cs.write("return true;\n");
                            });
                            cs.write("}\n");
                            break;
                        case DefineType.Constant:
                            cs.write(
                                `if(value == ${d.name}) {\n`,
                                () => {
                                    cs.write(
                                        `out = Nan::New<v8::Uint32>(${d.value});\n`
                                    );
                                    cs.write("return true;\n");
                                },
                                "}\n"
                            );
                            break;
                    }
                }
                cs.write(
                    `${createNanThrowCall(
                        '"Failed to create binding value from original value: " + std::to_string(value)'
                    )}\n`
                );
                cs.write("return false;\n");
            },
            "}\n"
        );
    }
    await fs.promises.writeFile(
        path.resolve(__dirname, "../Constants.cpp"),
        cs.value()
    );

    cs.write("#ifndef NODELIBZIP_H_\n");
    cs.write("#define NODELIBZIP_H_\n\n");
    cs.write("#include <nan.h>\n");
    cs.write("#include <zip.h>\n\n");
    for (const d of defineSet) {
        cs.write(
            `bool ${d.convertFunctionName}(Nan::NAN_METHOD_ARGS_TYPE& info, const int&& index, ${d.outputVariableType}& out);\n`
        );
        cs.write(
            `bool ${d.getBindingValueFunctionName}(const ${d.outputVariableType}& value, v8::Local<v8::Uint32>& out);\n`
        );
        cs.write(`void ${d.setFunctionName}(v8::Local<v8::Object>);\n`);
    }
    cs.write("\n");
    cs.write("#endif // NODELIBZIP_H_\n");
    await fs.promises.writeFile(
        path.resolve(__dirname, "../Constants.h"),
        cs.value()
    );

    cs.write(
        "export interface IConstants {\n",
        () => {
            for (const d of defineSet) {
                for (const p of createPairArray(d.defines)) {
                    cs.write(`${p.name}: number;\n`);
                }
            }
        },
        "}\n"
    );
    await fs.promises.writeFile(
        path.resolve(__dirname, "../constants.d.ts"),
        cs.value()
    );
})().catch((err) => {
    console.error(err);
    process.exitCode = 1;
});

function createNanThrowCall(value: string) {
    return `Nan::ThrowError(Nan::New(${value}).ToLocalChecked());`;
}

function createPairArray(defines: Define[]): IPair[] {
    return defines.reduce(
        (a, b) => [...a, ...(b.type === DefineType.Flags ? b.values : [b])],
        new Array<IPair>()
    );
}
