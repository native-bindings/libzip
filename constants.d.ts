export interface IConstants {
    SEEK_SET: number;
    SEEK_CUR: number;
    SEEK_END: number;
    ZIP_CREATE: number;
    ZIP_EXCL: number;
    ZIP_CHECKCONS: number;
    ZIP_TRUNCATE: number;
    ZIP_RDONLY: number;
    ZIP_FL_NOCASE: number;
    ZIP_FL_RECOMPRESS: number;
    ZIP_FL_NODIR: number;
    ZIP_FL_COMPRESSED: number;
    ZIP_FL_UNCHANGED: number;
    ZIP_FL_ENCRYPTED: number;
    ZIP_FL_ENC_GUESS: number;
    ZIP_FL_ENC_RAW: number;
    ZIP_FL_ENC_STRICT: number;
    ZIP_FL_LOCAL: number;
    ZIP_FL_CENTRAL: number;
    ZIP_FL_ENC_UTF_8: number;
    ZIP_FL_ENC_CP437: number;
    ZIP_FL_OVERWRITE: number;
    ZIP_AFL_RDONLY: number;
    ZIP_AFL_IS_TORRENTZIP: number;
    ZIP_AFL_WANT_TORRENTZIP: number;
    ZIP_AFL_CREATE_OR_KEEP_FILE_FOR_EMPTY_ARCHIVE: number;
    ZIP_EXTRA_FIELD_ALL: number;
    ZIP_EXTRA_FIELD_NEW: number;
    ZIP_LENGTH_TO_END: number;
    ZIP_LENGTH_UNCHECKED: number;
    ZIP_ER_OK: number;
    ZIP_ER_MULTIDISK: number;
    ZIP_ER_RENAME: number;
    ZIP_ER_CLOSE: number;
    ZIP_ER_SEEK: number;
    ZIP_ER_READ: number;
    ZIP_ER_WRITE: number;
    ZIP_ER_CRC: number;
    ZIP_ER_ZIPCLOSED: number;
    ZIP_ER_NOENT: number;
    ZIP_ER_EXISTS: number;
    ZIP_ER_OPEN: number;
    ZIP_ER_TMPOPEN: number;
    ZIP_ER_ZLIB: number;
    ZIP_ER_MEMORY: number;
    ZIP_ER_CHANGED: number;
    ZIP_ER_COMPNOTSUPP: number;
    ZIP_ER_EOF: number;
    ZIP_ER_INVAL: number;
    ZIP_ER_NOZIP: number;
    ZIP_ER_INTERNAL: number;
    ZIP_ER_INCONS: number;
    ZIP_ER_REMOVE: number;
    ZIP_ER_DELETED: number;
    ZIP_ER_ENCRNOTSUPP: number;
    ZIP_ER_RDONLY: number;
    ZIP_ER_NOPASSWD: number;
    ZIP_ER_WRONGPASSWD: number;
    ZIP_ER_OPNOTSUPP: number;
    ZIP_ER_INUSE: number;
    ZIP_ER_TELL: number;
    ZIP_ER_COMPRESSED_DATA: number;
    ZIP_ER_CANCELLED: number;
    ZIP_ER_DATA_LENGTH: number;
    ZIP_ER_NOT_ALLOWED: number;
    ZIP_ET_NONE: number;
    ZIP_ET_SYS: number;
    ZIP_ET_ZLIB: number;
    ZIP_ET_LIBZIP: number;
    ZIP_CM_DEFAULT: number;
    ZIP_CM_STORE: number;
    ZIP_CM_SHRINK: number;
    ZIP_CM_REDUCE_1: number;
    ZIP_CM_REDUCE_2: number;
    ZIP_CM_REDUCE_3: number;
    ZIP_CM_REDUCE_4: number;
    ZIP_CM_IMPLODE: number;
    ZIP_CM_DEFLATE: number;
    ZIP_CM_DEFLATE64: number;
    ZIP_CM_PKWARE_IMPLODE: number;
    ZIP_CM_BZIP2: number;
    ZIP_CM_LZMA: number;
    ZIP_CM_TERSE: number;
    ZIP_CM_LZ77: number;
    ZIP_CM_LZMA2: number;
    ZIP_CM_ZSTD: number;
    ZIP_CM_XZ: number;
    ZIP_CM_JPEG: number;
    ZIP_CM_WAVPACK: number;
    ZIP_CM_PPMD: number;
    ZIP_EM_NONE: number;
    ZIP_EM_TRAD_PKWARE: number;
    ZIP_EM_AES_128: number;
    ZIP_EM_AES_192: number;
    ZIP_EM_AES_256: number;
    ZIP_EM_UNKNOWN: number;
    ZIP_OPSYS_DOS: number;
    ZIP_OPSYS_AMIGA: number;
    ZIP_OPSYS_OPENVMS: number;
    ZIP_OPSYS_UNIX: number;
    ZIP_OPSYS_VM_CMS: number;
    ZIP_OPSYS_ATARI_ST: number;
    ZIP_OPSYS_OS_2: number;
    ZIP_OPSYS_MACINTOSH: number;
    ZIP_OPSYS_Z_SYSTEM: number;
    ZIP_OPSYS_CPM: number;
    ZIP_OPSYS_WINDOWS_NTFS: number;
    ZIP_OPSYS_MVS: number;
    ZIP_OPSYS_VSE: number;
    ZIP_OPSYS_ACORN_RISC: number;
    ZIP_OPSYS_VFAT: number;
    ZIP_OPSYS_ALTERNATE_MVS: number;
    ZIP_OPSYS_BEOS: number;
    ZIP_OPSYS_TANDEM: number;
    ZIP_OPSYS_OS_400: number;
    ZIP_OPSYS_OS_X: number;
    ZIP_OPSYS_DEFAULT: number;
    ZIP_SOURCE_SUPPORTS_READABLE: number;
    ZIP_SOURCE_SUPPORTS_SEEKABLE: number;
    ZIP_SOURCE_SUPPORTS_WRITABLE: number;
    ZIP_FILE_ATTRIBUTES_HOST_SYSTEM: number;
    ZIP_FILE_ATTRIBUTES_ASCII: number;
    ZIP_FILE_ATTRIBUTES_VERSION_NEEDED: number;
    ZIP_FILE_ATTRIBUTES_EXTERNAL_FILE_ATTRIBUTES: number;
    ZIP_FILE_ATTRIBUTES_GENERAL_PURPOSE_BIT_FLAGS: number;
    ZIP_ENCODING_UNKNOWN: number;
    ZIP_ENCODING_ASCII: number;
    ZIP_ENCODING_UTF8_KNOWN: number;
    ZIP_ENCODING_UTF8_GUESSED: number;
    ZIP_ENCODING_CP437: number;
    ZIP_ENCODING_ERROR: number;
    ZIP_SOURCE_WRITE_CLOSED: number;
    ZIP_SOURCE_WRITE_OPEN: number;
    ZIP_SOURCE_WRITE_FAILED: number;
    ZIP_SOURCE_WRITE_REMOVED: number;
    ZIP_STAT_NAME: number;
    ZIP_STAT_INDEX: number;
    ZIP_STAT_SIZE: number;
    ZIP_STAT_COMP_SIZE: number;
    ZIP_STAT_MTIME: number;
    ZIP_STAT_CRC: number;
    ZIP_STAT_COMP_METHOD: number;
    ZIP_STAT_ENCRYPTION_METHOD: number;
    ZIP_STAT_FLAGS: number;
}
