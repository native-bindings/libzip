# @native-bindings/libzip

## Installation

```bash
npm install @native-bindings/libzip
```

## 64-bit integers

libzip uses 64-bit integers types in the native code. In the Node.js side, these are represented as a strings. I decided to keep them, because 32-bit integers cannot go over a certain length. In case of file size, an unsigned 32-bit integer can represent up to 4 GB file size, above that, we would have imprecision issues, not only for file sizes, but for file indices as well.

Using unsigned 64-bit integers, gives us the possibility to handle files up to 17.2 EB (or 17.2 million terabytes) in size, which is more than enough for the foreseeable future.

To circumvent that, you can use the `jsbi` or other library of your choice to deal with these numbers.

## Usage

The API is very similar to the original API of libzip. The only difference is that the functions are in camelCase, and some functions like `dirAdd` were renamed to `addDirectory`, `fileAdd` to `addFile`, etc.

## Examples

### Creating an archive and adding a file to it

```typescript
import * as zip from "@native-bindings/libzip";
import JSBI from "jsbi";

export default async function () {
    const file1 = path.resolve(__dirname, "test.txt");

    const archive = new zip.Archive();
    // it will throw if the file exists
    archive.open(path.resolve(__dirname, "test.zip"), zip.constants.ZIP_CREATE);
    // if the file exists, it will it when we call archive.close(), otherwise it will create it
    // archive.open(path.resolve(__dirname, 'test.zip'), zip.constants.ZIP_CREATE | zip.constants.ZIP_TRUNCATE);
    const src: zip.Source = archive.sourceFile(
        file1,
        "0",
        (await fs.promises.stat(file1)).size
    );
    // returns the index of the added file as a signed 64-bit integer, represented as a string as stated above
    const index = a.addFile(f.path, src, zip.constants.ZIP_FL_ENC_UTF_8);
}
```

### Iterating over the files in an archive

```typescript
import * as zip from "@native-bindings/libzip";
import JSBI from "jsbi";

export default async function () {
    const archive = new zip.Archive();
    archive.open(path.resolve(__dirname, "test.zip"), zip.constants.ZIP_RDONLY);
    const length = archive.getNumEntries(0);
    // we create a single Stat class instance to be reused in the loop, avoiding memory waste
    const stat = new zip.Stat();
    for (
        let i = JSBI.BigInt(0); // i = 0
        JSBI.LT(i, entryCount); // i < entryCount
        i = JSBI.add(i, JSBI.BigInt(1)) // i++
    ) {
        // will return the name of the file as a string
        const fileName = archive.getName(i.toString());
        // will fill the stat instance with the information about the file (size, compression method, encryption algorithm etc.)
        archive.statIndex(i.toString(), 0, stat);
        const file: zip.File = archive.openFileByIndex(i.toString(), 0);
        const buf = new Uint8Array(JSBI.toNumber(JSBI.BigInt(stat.size())));
        file.read(buf, stat.size());
    }
}
```
