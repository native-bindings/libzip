import { getArgument } from "cli-argument-helper";
import { glob } from "glob";
import path from "path";
import fs from "fs";
import { PreprocessorTokenizer } from "../core";

async function generateConstants() {
    const headerFiles = await glob(path.resolve(__dirname, "../deps/**/*.h"));
    headerFiles.sort((a, b) => a.localeCompare(b));
    for (const file of headerFiles) {
        const fd = await fs.promises.open(file);
        const buf = await fd.readFile();
        new PreprocessorTokenizer({
            contents: buf,
            file
        }).tokenize();
        await fd.close();
    }
}

(async () => {
    const args = process.argv.slice(2);
    if (getArgument(args, "--generate-constants") !== null) {
        await generateConstants();
    }
})().catch((err) => {
    console.error(err);
    process.exitCode = 1;
});

// function createNanThrowCall(value: string) {
//     return `Nan::ThrowError(Nan::New(${value}).ToLocalChecked());`;
// }
