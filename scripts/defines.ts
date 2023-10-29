export enum DefineType {
    Flags,
    Constant
}

export const zipDefines = [
    {
        bitwise: true,
        constants: [
            "ZIP_FL_NOCASE",
            "ZIP_FL_RECOMPRESS",
            "ZIP_FL_NODIR",
            "ZIP_FL_COMPRESSED",
            "ZIP_FL_UNCHANGED",
            "ZIP_FL_ENCRYPTED",
            "ZIP_FL_ENC_GUESS",
            "ZIP_FL_ENC_RAW",
            "ZIP_FL_ENC_STRICT",
            "ZIP_FL_LOCAL",
            "ZIP_FL_CENTRAL",
            "ZIP_FL_ENC_UTF_8",
            "ZIP_FL_ENC_CP437",
            "ZIP_FL_OVERWRITE"
        ]
    },
    {
        constants: [
            "ZIP_AFL_RDONLY",
            "ZIP_AFL_IS_TORRENTZIP",
            "ZIP_AFL_WANT_TORRENTZIP",
            "ZIP_AFL_CREATE_OR_KEEP_FILE_FOR_EMPTY_ARCHIVE"
        ]
    },
    { constants: ["ZIP_EXTRA_FIELD_ALL", "ZIP_EXTRA_FIELD_NEW"] },
    /**
     * errors
     */
    {
        constants: [
            "ZIP_ER_OK",
            "ZIP_ER_MULTIDISK",
            "ZIP_ER_RENAME",
            "ZIP_ER_CLOSE",
            "ZIP_ER_SEEK",
            "ZIP_ER_READ",
            "ZIP_ER_WRITE",
            "ZIP_ER_CRC",
            "ZIP_ER_ZIPCLOSED",
            "ZIP_ER_NOENT",
            "ZIP_ER_EXISTS",
            "ZIP_ER_OPEN",
            "ZIP_ER_TMPOPEN",
            "ZIP_ER_ZLIB",
            "ZIP_ER_MEMORY",
            "ZIP_ER_CHANGED",
            "ZIP_ER_COMPNOTSUPP",
            "ZIP_ER_EOF",
            "ZIP_ER_INVAL",
            "ZIP_ER_NOZIP",
            "ZIP_ER_INTERNAL",
            "ZIP_ER_INCONS",
            "ZIP_ER_REMOVE",
            "ZIP_ER_DELETED",
            "ZIP_ER_ENCRNOTSUPP",
            "ZIP_ER_RDONLY",
            "ZIP_ER_NOPASSWD",
            "ZIP_ER_WRONGPASSWD",
            "ZIP_ER_OPNOTSUPP",
            "ZIP_ER_INUSE",
            "ZIP_ER_TELL",
            "ZIP_ER_COMPRESSED_DATA",
            "ZIP_ER_CANCELLED",
            "ZIP_ER_DATA_LENGTH",
            "ZIP_ER_NOT_ALLOWED"
        ]
    },
    /**
     * ZIP_ET_*
     */
    {
        constants: ["ZIP_ET_NONE", "ZIP_ET_SYS", "ZIP_ET_ZLIB", "ZIP_ET_LIBZIP"]
    },
    /**
     * ZIP_OPSYS_*
     */
    {
        constants: [
            "ZIP_OPSYS_DOS",
            "ZIP_OPSYS_AMIGA",
            "ZIP_OPSYS_OPENVMS",
            "ZIP_OPSYS_UNIX",
            "ZIP_OPSYS_VM_CMS",
            "ZIP_OPSYS_ATARI_ST",
            "ZIP_OPSYS_OS_2",
            "ZIP_OPSYS_MACINTOSH",
            "ZIP_OPSYS_Z_SYSTEM",
            "ZIP_OPSYS_CPM",
            "ZIP_OPSYS_WINDOWS_NTFS",
            "ZIP_OPSYS_MVS",
            "ZIP_OPSYS_VSE",
            "ZIP_OPSYS_ACORN_RISC",
            "ZIP_OPSYS_VFAT",
            "ZIP_OPSYS_ALTERNATE_MVS",
            "ZIP_OPSYS_BEOS",
            "ZIP_OPSYS_TANDEM",
            "ZIP_OPSYS_OS_400",
            "ZIP_OPSYS_OS_X",
            "ZIP_OPSYS_DEFAULT"
        ]
    },
    /**
     * ZIP_SOURCE_*
     */
    {
        constants: [
            "ZIP_SOURCE_SUPPORTS_READABLE",
            "ZIP_SOURCE_SUPPORTS_SEEKABLE",
            "ZIP_SOURCE_SUPPORTS_WRITABLE"
        ]
    },
    /**
     *
     */
    {
        constants: [
            "ZIP_FILE_ATTRIBUTES_HOST_SYSTEM",
            "ZIP_FILE_ATTRIBUTES_ASCII",
            "ZIP_FILE_ATTRIBUTES_VERSION_NEEDED",
            "ZIP_FILE_ATTRIBUTES_EXTERNAL_FILE_ATTRIBUTES",
            "ZIP_FILE_ATTRIBUTES_GENERAL_PURPOSE_BIT_FLAGS"
        ]
    },
    /**
     * enum zip_encoding_type
     */
    {
        constants: [
            "ZIP_ENCODING_UNKNOWN",
            "ZIP_ENCODING_ASCII",
            "ZIP_ENCODING_UTF8_KNOWN",
            "ZIP_ENCODING_UTF8_GUESSED",
            "ZIP_ENCODING_CP437",
            "ZIP_ENCODING_ERROR"
        ]
    },
    /**
     * enum zip_source_write_state
     */
    {
        constants: [
            "ZIP_SOURCE_WRITE_CLOSED",
            "ZIP_SOURCE_WRITE_OPEN",
            "ZIP_SOURCE_WRITE_FAILED",
            "ZIP_SOURCE_WRITE_REMOVED"
        ]
    }
];

export interface IUnprocessedDefine {
    constants: string[];
    bitwise?: boolean;
}

export function buildDefines(list: IUnprocessedDefine[]) {
    return list.reduce(
        (a, b) => {
            const define: Define | null = b.bitwise
                ? {
                      type: DefineType.Flags,
                      values: []
                  }
                : null;
            for (const name of b.constants) {
                if (define === null) {
                    a.defines.push({
                        type: DefineType.Constant,
                        name,
                        value: a.value
                    });
                } else {
                    define.values.push({
                        name,
                        value: a.value
                    });
                }
                /**
                 * for saving int32 max range, we use incremental enum values for enums that
                 * do not need bitwise operations, but we fix the last value to be divisible by 2
                 * when the enum is bitwise
                 *
                 * let's say we have
                 *
                 * A0
                 * A1
                 * A2
                 * A3
                 * A4
                 *
                 * that do not need bitwise operations, so their values will be
                 *
                 *
                 * A0 - 1
                 * A1 - 2
                 * A2 - 3
                 * A3 - 4
                 * A4 - 5
                 *
                 * then we have the following enums that support bitwise operations, so B0 will be fixed to 6
                 * so the bitwise assertions would work. their values would be incremented accordingly
                 *
                 * B0 - 6
                 * B1 - 12
                 * B2 - 24
                 */
                if (b.bitwise) {
                    while (a.value % 2) {
                        a.value++;
                    }
                    a.value <<= 1;
                } else {
                    a.value++;
                }
            }
            if (define !== null) {
                a.defines.push(define);
            }
            return a;
        },
        {
            defines: new Array<Define>(),
            value: 1
        }
    );
}

export interface IPair {
    value: number;
    name: string;
}

export interface IDefineConstant extends IPair {
    type: DefineType.Constant;
}

export type Define =
    | {
          type: DefineType.Flags;
          values: IPair[];
      }
    | IDefineConstant;
