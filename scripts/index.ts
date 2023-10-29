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
            jsType: "Uint32",
            outputVariableType: "int"
        },
        {
            defines: buildDefines([
                /**
                 * ZIP_EM_*
                 */
                {
                    constants: [
                        "ZIP_EM_NONE",
                        "ZIP_EM_TRAD_PKWARE",
                        // ! see zip.h at line 198
                        // "ZIP_EM_DES",
                        // "ZIP_EM_RC2_OLD",
                        // "ZIP_EM_3DES_168",
                        // "ZIP_EM_3DES_112",
                        // "ZIP_EM_PKZIP_AES_128",
                        // "ZIP_EM_PKZIP_AES_192",
                        // "ZIP_EM_PKZIP_AES_256",
                        // "ZIP_EM_RC2",
                        // "ZIP_EM_RC4",
                        "ZIP_EM_AES_128",
                        "ZIP_EM_AES_192",
                        "ZIP_EM_AES_256",
                        "ZIP_EM_UNKNOWN"
                    ]
                }
            ]).defines,
            name: "ZipEncryptionMethodFlag",
            jsType: "Uint32",
            outputVariableType: "zip_uint16_t"
        },
        {
            defines: buildDefines([
                /**
                 * ZIP_CM_*
                 */
                {
                    constants: [
                        "ZIP_CM_DEFAULT",
                        "ZIP_CM_STORE",
                        "ZIP_CM_SHRINK",
                        "ZIP_CM_REDUCE_1",
                        "ZIP_CM_REDUCE_2",
                        "ZIP_CM_REDUCE_3",
                        "ZIP_CM_REDUCE_4",
                        "ZIP_CM_IMPLODE",
                        "ZIP_CM_DEFLATE",
                        "ZIP_CM_DEFLATE64",
                        "ZIP_CM_PKWARE_IMPLODE",
                        "ZIP_CM_BZIP2",
                        "ZIP_CM_LZMA",
                        "ZIP_CM_TERSE",
                        "ZIP_CM_LZ77",
                        "ZIP_CM_LZMA2",
                        "ZIP_CM_ZSTD",
                        "ZIP_CM_XZ",
                        "ZIP_CM_JPEG",
                        "ZIP_CM_WAVPACK",
                        "ZIP_CM_PPMD"
                    ]
                }
            ]).defines,
            name: "ZipCompressionMethodFlag",
            jsType: "Int32",
            outputVariableType: "zip_int32_t"
        },
        {
            defines: buildDefines(zipDefines).defines,
            jsType: "Uint32",
            name: "ZipConstant",
            outputVariableType: "zip_flags_t"
        },
        {
            defines: buildDefines([
                {
                    bitwise: true,
                    constants: [
                        "ZIP_CREATE",
                        "ZIP_EXCL",
                        "ZIP_CHECKCONS",
                        "ZIP_TRUNCATE",
                        "ZIP_RDONLY"
                    ]
                }
            ]).defines,
            name: "ZipOpenModeFlag",
            jsType: "Uint32",
            outputVariableType: "int"
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
            jsType: "Uint32",
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
            jsType,
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
                    `if(!args.AssertArgumentType("${jsType}", index, Arguments::Is${jsType})) {\n`,
                    () => {
                        cs.write("return false;\n");
                    },
                    "}\n"
                );
                cs.write(
                    `auto val = Nan::To<v8::${jsType}>(info[index]).ToLocalChecked()->Value();\n`
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
            `bool ${getBindingValueFunctionName}(const ${outputVariableType}& value, v8::Local<v8::${jsType}>& out) {\n`,
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
                                cs.write(`out = Nan::New<v8::${jsType}>(v);\n`);
                                cs.write("return true;\n");
                            });
                            cs.write("}\n");
                            break;
                        case DefineType.Constant:
                            cs.write(
                                `if(value == ${d.name}) {\n`,
                                () => {
                                    cs.write(
                                        `out = Nan::New<v8::${jsType}>(${d.value});\n`
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
        path.resolve(__dirname, "../src/Constants.cpp"),
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
        path.resolve(__dirname, "../src/Constants.h"),
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
