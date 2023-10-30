#include "Archive.h"
#include "File.h"
#include "Constants.h"
#include "Stat.h"
#include "Arguments.h"
#include "Source.h"

#include <nan.h>
#include <zip.h>

NAN_METHOD(CompressionMethodSupported) {
    Arguments args("compressionMethodSupported", info);
    zip_int32_t method;
    int compress;
    if(!ConvertZipCompressionMethodFlag(info, 0, method) || !args.Convert(1, compress)) {
        return;
    }
    info.GetReturnValue().Set(zip_compression_method_supported(method, compress) == 1 ? Nan::True() : Nan::False());
}

NAN_METHOD(EncryptionMethodSupported) {
    Arguments args("encryptionMethodSupported", info);
    zip_int32_t method;
    int compress;
    if(!ConvertZipCompressionMethodFlag(info, 0, method) || !args.Convert(1, compress)) {
        return;
    }
    info.GetReturnValue().Set(zip_encryption_method_supported(method, compress) == 1 ? Nan::True() : Nan::False());
}

NAN_MODULE_INIT(Init) {
    SetNativeConstants(target);
    SetZipLengthConstants(target);
    SetZipConstants(target);
    SetZipStatFlags(target);
    SetZipEncryptionMethodFlags(target);
    SetZipCompressionMethodFlags(target);
    SetZipOpenModeFlags(target);
    bindings::libzip::Stat::Init(target);
    File::Init(target);
    Archive::Init(target);
    Source::Init(target);
    Nan::SetMethod(target, "compressionMethodSupported", CompressionMethodSupported);
    Nan::SetMethod(target, "encryptionMethodSupported", EncryptionMethodSupported);
}

NODE_MODULE(libzip, Init)
