import path from "path";
import zip from "..";
import test from "ava";
import crypto from "crypto";
import JSBI from "jsbi";

test("that it reads through the entire archive", (t) => {
    const archive = new zip.Archive();
    archive.open(
        path.resolve(__dirname, "./test1.zip"),
        zip.constants.ZIP_RDONLY
    );
    let i = JSBI.BigInt(0);
    const numEntries = JSBI.BigInt(
        archive.getNumEntries(zip.constants.ZIP_FL_UNCHANGED)
    );
    const list = new Array<string>();
    while (JSBI.LT(i, numEntries)) {
        const name = archive.getName(
            i.toString(),
            zip.constants.ZIP_FL_UNCHANGED
        );
        list.push(name);
        i = JSBI.add(i, JSBI.BigInt(1));
    }
    t.deepEqual(list, ["index.d.ts", "constants.d.ts"]);
});

test("it should open a zip file", async (t) => {
    const archive = new zip.Archive();
    archive.open(
        path.resolve(__dirname, "./test1.zip"),
        zip.constants.ZIP_RDONLY
    );
    t.pass();
});

test("it should return the index of a specific file in the archive", (t) => {
    const archive = new zip.Archive();
    archive.open(
        path.resolve(__dirname, "./test1.zip"),
        zip.constants.ZIP_RDONLY
    );
    t.deepEqual(
        archive.nameLocate("index.d.ts", zip.constants.ZIP_FL_NOCASE),
        "0"
    );
    t.deepEqual(
        archive.nameLocate("constants.d.ts", zip.constants.ZIP_FL_NOCASE),
        "1"
    );
});

test("Archive#nameLocate: should return the -1 if the specified file does not exist", (t) => {
    const archive = new zip.Archive();
    archive.open(
        path.resolve(__dirname, "./test1.zip"),
        zip.constants.ZIP_RDONLY
    );
    t.deepEqual(archive.nameLocate("x", zip.constants.ZIP_FL_NOCASE), "-1");
});

test("Archive#open: should throw if the file does not exist", (t) => {
    const archive = new zip.Archive();
    t.throws(
        () => {
            archive.open(
                path.resolve(__dirname, "./this-test-should-never-exist.zip"),
                zip.constants.ZIP_RDONLY
            );
        },
        undefined,
        "Failed to open zip archive"
    );
});

test("Archive#getNumEntries: should return the number of entries", (t) => {
    const archive = new zip.Archive();
    archive.open(
        path.resolve(__dirname, "./test1.zip"),
        zip.constants.ZIP_RDONLY
    );
    t.deepEqual(archive.getNumEntries(zip.constants.ZIP_FL_UNCHANGED), "2");
});

test("that it should add a directory", (t) => {
    const archive = new zip.Archive();
    archive.open(path.resolve(__dirname, "./test1.zip"), 0);
    t.deepEqual(
        archive.addDirectory("test", zip.constants.ZIP_FL_ENC_UTF_8),
        "2"
    );
});

test("that it should throw an error if we try to add a directory in a read-only archive", (t) => {
    const archive = new zip.Archive();
    archive.open(
        path.resolve(__dirname, "./test1.zip"),
        zip.constants.ZIP_RDONLY
    );
    t.throws(
        () => {
            archive.addDirectory("test", zip.constants.ZIP_FL_ENC_UTF_8);
        },
        undefined,
        "Failed to add directory with error code 25: Read-only archive"
    );
});

test("that it should open and close a file", (t) => {
    const archive = new zip.Archive();
    archive.open(
        path.resolve(__dirname, "./test1.zip"),
        zip.constants.ZIP_CREATE
    );
    const f = archive.openFile("index.d.ts", zip.constants.ZIP_FL_ENC_UTF_8);
    f.close();
    t.pass();
});

test("that it should support calling close() many times", (t) => {
    const archive = new zip.Archive();
    archive.open(
        path.resolve(__dirname, "./test1.zip"),
        zip.constants.ZIP_CREATE
    );
    const f = archive.openFile("index.d.ts", zip.constants.ZIP_FL_ENC_UTF_8);
    f.close();
    t.throws(
        () => {
            f.close();
        },
        undefined,
        "File is already closed"
    );
});

test("that it should tell what is the current file reading position", (t) => {
    const archive = new zip.Archive();
    archive.open(
        path.resolve(__dirname, "./test1.zip"),
        zip.constants.ZIP_CREATE
    );
    const f = archive.openFile("index.d.ts", zip.constants.ZIP_FL_ENC_UTF_8);
    const buf = new Uint8Array(8);
    f.read(buf, "8");
    t.deepEqual(f.tell(), "8");
});

test("that it should read a file contents", (t) => {
    const archive = new zip.Archive();
    archive.open(
        path.resolve(__dirname, "./test1.zip"),
        zip.constants.ZIP_CREATE
    );
    const f = archive.openFile("index.d.ts", zip.constants.ZIP_FL_ENC_UTF_8);
    const buf = Buffer.allocUnsafe(8);
    f.read(buf, "8");
    t.deepEqual(buf.toString("utf8"), "declare ");
});

test("that it should tell what reading position we are at now", (t) => {
    const archive = new zip.Archive();
    archive.open(
        path.resolve(__dirname, "./test1.zip"),
        zip.constants.ZIP_CREATE
    );
    const f = archive.openFile("index.d.ts", zip.constants.ZIP_FL_ENC_UTF_8);
    t.deepEqual(f.tell(), "0");
    f.read(Buffer.allocUnsafe(8), "8");
    t.deepEqual(f.tell(), "8");
});

test("that it should file stat name", (t) => {
    const archive = new zip.Archive();
    archive.open(
        path.resolve(__dirname, "./test1.zip"),
        zip.constants.ZIP_CREATE
    );
    const stat = new zip.Stat();
    archive.stat(
        "index.d.ts",
        zip.constants.ZIP_STAT_NAME | zip.constants.ZIP_STAT_INDEX,
        stat
    );
    t.deepEqual(stat.name(), "index.d.ts");
});

test("that it should return file stat size", (t) => {
    const archive = new zip.Archive();
    archive.open(
        path.resolve(__dirname, "./test1.zip"),
        zip.constants.ZIP_CREATE
    );
    const stat = new zip.Stat();
    archive.stat("index.d.ts", 0, stat);
    t.deepEqual(stat.size(), "109");
});

test("that it should file stat valid flags", (t) => {
    const archive = new zip.Archive();
    archive.open(
        path.resolve(__dirname, "./test1.zip"),
        zip.constants.ZIP_CREATE
    );
    const stat = new zip.Stat();
    archive.stat("index.d.ts", 0, stat);
    t.deepEqual(
        stat.valid(),
        zip.constants.ZIP_STAT_NAME |
            zip.constants.ZIP_STAT_INDEX |
            zip.constants.ZIP_STAT_SIZE |
            zip.constants.ZIP_STAT_COMP_SIZE |
            zip.constants.ZIP_STAT_MTIME |
            zip.constants.ZIP_STAT_CRC |
            zip.constants.ZIP_STAT_COMP_METHOD |
            zip.constants.ZIP_STAT_ENCRYPTION_METHOD
    );
});

test("it should return the full path of the file in the archive", (t) => {
    const archive = new zip.Archive();
    archive.open(
        path.resolve(__dirname, "./test3.zip"),
        zip.constants.ZIP_CREATE
    );
    const entryCount = JSBI.BigInt(archive.getNumEntries(0));
    let i: JSBI;
    const stat = new zip.Stat();
    const list = new Array<string>();
    for (
        i = JSBI.BigInt(0);
        JSBI.LT(i, entryCount);
        i = JSBI.add(i, JSBI.BigInt(1))
    ) {
        archive.statIndex(i.toString(), 0, stat);
        list.push(stat.name());
    }
    t.deepEqual(list, [
        "test/",
        "test/index.js.map",
        "test/test1.zip",
        "test/index.d.ts",
        "test/test2.zip",
        "test/index.js",
        "test/index.ts",
        "test/index.d.ts.map"
    ]);
});

test("that it should add a file from a buffer", (t) => {
    const archive = new zip.Archive();
    const createdZipFile = path.resolve(__dirname, "./test4.zip");
    archive.open(
        createdZipFile,
        zip.constants.ZIP_CREATE | zip.constants.ZIP_TRUNCATE
    );
    const expectedData = crypto.randomFillSync(new Uint8Array(1024 * 1024 * 1));
    const src = archive.sourceBuffer(expectedData);
    t.deepEqual(
        archive.addFile("test.bin", src, zip.constants.ZIP_FL_ENC_UTF_8),
        "0"
    );
    archive.close();

    archive.open(createdZipFile, zip.constants.ZIP_RDONLY);
    t.deepEqual(archive.getNumEntries(zip.constants.ZIP_FL_UNCHANGED), "1");
    t.deepEqual(archive.getName("0", 0), "test.bin");
    const f = archive.openFile("test.bin", zip.constants.ZIP_FL_ENC_UTF_8);
    const givenData = new Uint8Array(1024 * 1024 * 1);
    f.read(givenData, "1048576");
    t.deepEqual(givenData, expectedData);
    archive.discard();
});
