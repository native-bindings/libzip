import { getArgument } from "cli-argument-helper";
import { glob } from "glob";
import path from "path";
import fs from "fs";
import { PreprocessorParser, PreprocessorTokenizer } from "../core";
import Exception from "../core/Exception";

export async function nextGenerateConstants() {
    const headerFiles = await glob(path.resolve(__dirname, "../deps/**/*.h"));
    headerFiles.sort((a, b) => a.localeCompare(b));
    for (const file of headerFiles) {
        const fd = await fs.promises.open(file);
        const contents = await fd.readFile();
        const tokens = new PreprocessorTokenizer({
            contents,
            file
        }).tokenize();
        const nodes = new PreprocessorParser({
            file,
            contents,
            tokens
        }).parse();
        nodes;
        await fd.close();
    }
}

async function generateConstants() {
    const headerFiles = await glob(path.resolve(__dirname, "../deps/**/*.h"));
    headerFiles.sort((a, b) => a.localeCompare(b));
    for (const file of headerFiles) {
        const fd = await fs.promises.open(file);
        const contents = await fd.readFile();
        const tokens = new PreprocessorTokenizer({
            contents,
            file
        }).tokenize();
        new PreprocessorParser({
            file,
            contents,
            tokens
        }).parse();
        await fd.close();
    }
}

(async () => {
    const args = process.argv.slice(2);
    if (getArgument(args, "--generate-constants") !== null) {
        await generateConstants();
    }
})().catch((err) => {
    debugger;
    if (err instanceof Exception) {
        console.error(err.what);
    } else {
        console.error(err);
    }
    process.exitCode = 1;
});

// function createNanThrowCall(value: string) {
//     return `Nan::ThrowError(Nan::New(${value}).ToLocalChecked());`;
// }
