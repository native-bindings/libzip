/**
 * signed 64-bit integer
 */
export type Index = string;

/**
 * unsigned 32-bit integer
 */
export type Flag = number;

/**
 * unsigned 64-bit integer
 */
export type Uint64 = string;

export class File {
    close(): void;
    read(buffer: Uint8Array, length: Uint64): void;
    seek(offset: Index, whence: number): void;
    tell(): Index;
    isSeekable(): boolean;
}

export class Stat {
    name(): string;
    size(): number;
    compressedSize(): string;
    crc(): number;
    encryptionMethod(): number;
    modificationTime(): string;
    index(): Index;
    valid(): Flag;
}

export class Archive {
    /**
     * @see {@link https://libzip.org/documentation/zip_open.html}
     */
    open(path: string, flags: Flag): void;
    /**
     * @see {@link https://libzip.org/documentation/zip_fopen.html}
     */
    openFile(fname: string, flags: Flag): File;
    /**
     * @see {@link https://libzip.org/documentation/zip_fopen_index.html}
     */
    openFileByIndex(index: Index, flags: Flag): File;
    /**
     * @see {@link https://libzip.org/documentation/zip_close.html}
     */
    close(): void;
    /**
     * @see {@link https://libzip.org/documentation/zip_delete.html}
     */
    delete(index: Index);
    /**
     * @see {@link https://libzip.org/documentation/zip_file_name.html}
     */
    renameFile(index: Index, newName: string, flags: Flag): void;
    stat(fname: string, flags: Flag, stat: Stat): void;
    /**
     * @see {@link https://libzip.org/documentation/zip_stat_index.html}
     */
    statIndex(index: Index, flags: Flag, stat: Stat): void;
    nameLocate(path: string, flags: Flag): Index;
    getNumEntries(flags: Flag): Index;
    getName(index: Index, flags: Flag): Index;
    /**
     * @see {@link https://libzip.org/documentation/zip_dir_add.html}
     */
    dirAdd(path: string, flags: Flags): Index;
    discard(): void;
}

export const constants: import("./constants").IConstants;
