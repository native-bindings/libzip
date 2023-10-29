#include "Constants.h"
#include "Arguments.h"

#include <zipint.h>

v8::Local<v8::Object> GetOrCreateConstants(v8::Local<v8::Object> target) {
    const auto key = Nan::New("constants").ToLocalChecked();
    v8::Local<v8::Object> constants;
    if(Nan::HasOwnProperty(target, key).FromJust()) {
        constants = Nan::To<v8::Object>(Nan::Get(target, key).ToLocalChecked()).ToLocalChecked();
    } else {
        constants = Nan::New<v8::Object>();
        Nan::Set(target, key, constants);
    }
    return constants;
}
void SetNativeConstants(v8::Local<v8::Object> exports) {
    auto constants = GetOrCreateConstants(exports);
    v8::Local<v8::String> key;
    key = Nan::New("SEEK_SET").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(1));
    key = Nan::New("SEEK_CUR").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(2));
    key = Nan::New("SEEK_END").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(3));
    Nan::Set(exports, Nan::New("constants").ToLocalChecked(), constants);
}
bool ConvertNativeConstant(Nan::NAN_METHOD_ARGS_TYPE& info, const int&& index, int& out) {
    Arguments args("libzipflags",info);
    if(!args.AssertArgumentType("Uint32", index, Arguments::IsUint32)) {
        return false;
    }
    auto val = Nan::To<v8::Uint32>(info[index]).ToLocalChecked()->Value();
    if(val == 1) {
        out = SEEK_SET;
        return true;
    }
    if(val == 2) {
        out = SEEK_CUR;
        return true;
    }
    if(val == 3) {
        out = SEEK_END;
        return true;
    }
    if(val != 0) {
        Nan::ThrowError(Nan::New("Failed to convert constant value to libzip constant: " + std::to_string(val)).ToLocalChecked());
        return false;
    }
    out = 0;
    return true;
}
bool GetBindingNativeConstant(const int& value, v8::Local<v8::Uint32>& out) {
    if(value == SEEK_SET) {
        out = Nan::New<v8::Uint32>(1);
        return true;
    }
    if(value == SEEK_CUR) {
        out = Nan::New<v8::Uint32>(2);
        return true;
    }
    if(value == SEEK_END) {
        out = Nan::New<v8::Uint32>(3);
        return true;
    }
    Nan::ThrowError(Nan::New("Failed to create binding value from original value: " + std::to_string(value)).ToLocalChecked());
    return false;
}
void SetZipEncryptionMethodFlags(v8::Local<v8::Object> exports) {
    auto constants = GetOrCreateConstants(exports);
    v8::Local<v8::String> key;
    key = Nan::New("ZIP_EM_NONE").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(1));
    key = Nan::New("ZIP_EM_TRAD_PKWARE").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(2));
    key = Nan::New("ZIP_EM_AES_128").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(3));
    key = Nan::New("ZIP_EM_AES_192").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(4));
    key = Nan::New("ZIP_EM_AES_256").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(5));
    key = Nan::New("ZIP_EM_UNKNOWN").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(6));
    Nan::Set(exports, Nan::New("constants").ToLocalChecked(), constants);
}
bool ConvertZipEncryptionMethodFlag(Nan::NAN_METHOD_ARGS_TYPE& info, const int&& index, zip_uint16_t& out) {
    Arguments args("libzipflags",info);
    if(!args.AssertArgumentType("Uint32", index, Arguments::IsUint32)) {
        return false;
    }
    auto val = Nan::To<v8::Uint32>(info[index]).ToLocalChecked()->Value();
    if(val == 1) {
        out = ZIP_EM_NONE;
        return true;
    }
    if(val == 2) {
        out = ZIP_EM_TRAD_PKWARE;
        return true;
    }
    if(val == 3) {
        out = ZIP_EM_AES_128;
        return true;
    }
    if(val == 4) {
        out = ZIP_EM_AES_192;
        return true;
    }
    if(val == 5) {
        out = ZIP_EM_AES_256;
        return true;
    }
    if(val == 6) {
        out = ZIP_EM_UNKNOWN;
        return true;
    }
    if(val != 0) {
        Nan::ThrowError(Nan::New("Failed to convert constant value to libzip constant: " + std::to_string(val)).ToLocalChecked());
        return false;
    }
    out = 0;
    return true;
}
bool GetBindingZipEncryptionMethodFlag(const zip_uint16_t& value, v8::Local<v8::Uint32>& out) {
    if(value == ZIP_EM_NONE) {
        out = Nan::New<v8::Uint32>(1);
        return true;
    }
    if(value == ZIP_EM_TRAD_PKWARE) {
        out = Nan::New<v8::Uint32>(2);
        return true;
    }
    if(value == ZIP_EM_AES_128) {
        out = Nan::New<v8::Uint32>(3);
        return true;
    }
    if(value == ZIP_EM_AES_192) {
        out = Nan::New<v8::Uint32>(4);
        return true;
    }
    if(value == ZIP_EM_AES_256) {
        out = Nan::New<v8::Uint32>(5);
        return true;
    }
    if(value == ZIP_EM_UNKNOWN) {
        out = Nan::New<v8::Uint32>(6);
        return true;
    }
    Nan::ThrowError(Nan::New("Failed to create binding value from original value: " + std::to_string(value)).ToLocalChecked());
    return false;
}
void SetZipCompressionMethodFlags(v8::Local<v8::Object> exports) {
    auto constants = GetOrCreateConstants(exports);
    v8::Local<v8::String> key;
    key = Nan::New("ZIP_CM_DEFAULT").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(1));
    key = Nan::New("ZIP_CM_STORE").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(2));
    key = Nan::New("ZIP_CM_SHRINK").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(3));
    key = Nan::New("ZIP_CM_REDUCE_1").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(4));
    key = Nan::New("ZIP_CM_REDUCE_2").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(5));
    key = Nan::New("ZIP_CM_REDUCE_3").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(6));
    key = Nan::New("ZIP_CM_REDUCE_4").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(7));
    key = Nan::New("ZIP_CM_IMPLODE").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(8));
    key = Nan::New("ZIP_CM_DEFLATE").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(9));
    key = Nan::New("ZIP_CM_DEFLATE64").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(10));
    key = Nan::New("ZIP_CM_PKWARE_IMPLODE").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(11));
    key = Nan::New("ZIP_CM_BZIP2").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(12));
    key = Nan::New("ZIP_CM_LZMA").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(13));
    key = Nan::New("ZIP_CM_TERSE").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(14));
    key = Nan::New("ZIP_CM_LZ77").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(15));
    key = Nan::New("ZIP_CM_LZMA2").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(16));
    key = Nan::New("ZIP_CM_ZSTD").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(17));
    key = Nan::New("ZIP_CM_XZ").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(18));
    key = Nan::New("ZIP_CM_JPEG").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(19));
    key = Nan::New("ZIP_CM_WAVPACK").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(20));
    key = Nan::New("ZIP_CM_PPMD").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(21));
    Nan::Set(exports, Nan::New("constants").ToLocalChecked(), constants);
}
bool ConvertZipCompressionMethodFlag(Nan::NAN_METHOD_ARGS_TYPE& info, const int&& index, zip_int32_t& out) {
    Arguments args("libzipflags",info);
    if(!args.AssertArgumentType("Int32", index, Arguments::IsInt32)) {
        return false;
    }
    auto val = Nan::To<v8::Int32>(info[index]).ToLocalChecked()->Value();
    if(val == 1) {
        out = ZIP_CM_DEFAULT;
        return true;
    }
    if(val == 2) {
        out = ZIP_CM_STORE;
        return true;
    }
    if(val == 3) {
        out = ZIP_CM_SHRINK;
        return true;
    }
    if(val == 4) {
        out = ZIP_CM_REDUCE_1;
        return true;
    }
    if(val == 5) {
        out = ZIP_CM_REDUCE_2;
        return true;
    }
    if(val == 6) {
        out = ZIP_CM_REDUCE_3;
        return true;
    }
    if(val == 7) {
        out = ZIP_CM_REDUCE_4;
        return true;
    }
    if(val == 8) {
        out = ZIP_CM_IMPLODE;
        return true;
    }
    if(val == 9) {
        out = ZIP_CM_DEFLATE;
        return true;
    }
    if(val == 10) {
        out = ZIP_CM_DEFLATE64;
        return true;
    }
    if(val == 11) {
        out = ZIP_CM_PKWARE_IMPLODE;
        return true;
    }
    if(val == 12) {
        out = ZIP_CM_BZIP2;
        return true;
    }
    if(val == 13) {
        out = ZIP_CM_LZMA;
        return true;
    }
    if(val == 14) {
        out = ZIP_CM_TERSE;
        return true;
    }
    if(val == 15) {
        out = ZIP_CM_LZ77;
        return true;
    }
    if(val == 16) {
        out = ZIP_CM_LZMA2;
        return true;
    }
    if(val == 17) {
        out = ZIP_CM_ZSTD;
        return true;
    }
    if(val == 18) {
        out = ZIP_CM_XZ;
        return true;
    }
    if(val == 19) {
        out = ZIP_CM_JPEG;
        return true;
    }
    if(val == 20) {
        out = ZIP_CM_WAVPACK;
        return true;
    }
    if(val == 21) {
        out = ZIP_CM_PPMD;
        return true;
    }
    if(val != 0) {
        Nan::ThrowError(Nan::New("Failed to convert constant value to libzip constant: " + std::to_string(val)).ToLocalChecked());
        return false;
    }
    out = 0;
    return true;
}
bool GetBindingZipCompressionMethodFlag(const zip_int32_t& value, v8::Local<v8::Int32>& out) {
    if(value == ZIP_CM_DEFAULT) {
        out = Nan::New<v8::Int32>(1);
        return true;
    }
    if(value == ZIP_CM_STORE) {
        out = Nan::New<v8::Int32>(2);
        return true;
    }
    if(value == ZIP_CM_SHRINK) {
        out = Nan::New<v8::Int32>(3);
        return true;
    }
    if(value == ZIP_CM_REDUCE_1) {
        out = Nan::New<v8::Int32>(4);
        return true;
    }
    if(value == ZIP_CM_REDUCE_2) {
        out = Nan::New<v8::Int32>(5);
        return true;
    }
    if(value == ZIP_CM_REDUCE_3) {
        out = Nan::New<v8::Int32>(6);
        return true;
    }
    if(value == ZIP_CM_REDUCE_4) {
        out = Nan::New<v8::Int32>(7);
        return true;
    }
    if(value == ZIP_CM_IMPLODE) {
        out = Nan::New<v8::Int32>(8);
        return true;
    }
    if(value == ZIP_CM_DEFLATE) {
        out = Nan::New<v8::Int32>(9);
        return true;
    }
    if(value == ZIP_CM_DEFLATE64) {
        out = Nan::New<v8::Int32>(10);
        return true;
    }
    if(value == ZIP_CM_PKWARE_IMPLODE) {
        out = Nan::New<v8::Int32>(11);
        return true;
    }
    if(value == ZIP_CM_BZIP2) {
        out = Nan::New<v8::Int32>(12);
        return true;
    }
    if(value == ZIP_CM_LZMA) {
        out = Nan::New<v8::Int32>(13);
        return true;
    }
    if(value == ZIP_CM_TERSE) {
        out = Nan::New<v8::Int32>(14);
        return true;
    }
    if(value == ZIP_CM_LZ77) {
        out = Nan::New<v8::Int32>(15);
        return true;
    }
    if(value == ZIP_CM_LZMA2) {
        out = Nan::New<v8::Int32>(16);
        return true;
    }
    if(value == ZIP_CM_ZSTD) {
        out = Nan::New<v8::Int32>(17);
        return true;
    }
    if(value == ZIP_CM_XZ) {
        out = Nan::New<v8::Int32>(18);
        return true;
    }
    if(value == ZIP_CM_JPEG) {
        out = Nan::New<v8::Int32>(19);
        return true;
    }
    if(value == ZIP_CM_WAVPACK) {
        out = Nan::New<v8::Int32>(20);
        return true;
    }
    if(value == ZIP_CM_PPMD) {
        out = Nan::New<v8::Int32>(21);
        return true;
    }
    Nan::ThrowError(Nan::New("Failed to create binding value from original value: " + std::to_string(value)).ToLocalChecked());
    return false;
}
void SetZipConstants(v8::Local<v8::Object> exports) {
    auto constants = GetOrCreateConstants(exports);
    v8::Local<v8::String> key;
    key = Nan::New("ZIP_FL_NOCASE").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(1));
    key = Nan::New("ZIP_FL_RECOMPRESS").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(4));
    key = Nan::New("ZIP_FL_NODIR").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(8));
    key = Nan::New("ZIP_FL_COMPRESSED").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(16));
    key = Nan::New("ZIP_FL_UNCHANGED").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(32));
    key = Nan::New("ZIP_FL_ENCRYPTED").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(64));
    key = Nan::New("ZIP_FL_ENC_GUESS").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(128));
    key = Nan::New("ZIP_FL_ENC_RAW").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(256));
    key = Nan::New("ZIP_FL_ENC_STRICT").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(512));
    key = Nan::New("ZIP_FL_LOCAL").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(1024));
    key = Nan::New("ZIP_FL_CENTRAL").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(2048));
    key = Nan::New("ZIP_FL_ENC_UTF_8").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(4096));
    key = Nan::New("ZIP_FL_ENC_CP437").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(8192));
    key = Nan::New("ZIP_FL_OVERWRITE").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(16384));
    key = Nan::New("ZIP_AFL_RDONLY").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(32768));
    key = Nan::New("ZIP_AFL_IS_TORRENTZIP").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(32769));
    key = Nan::New("ZIP_AFL_WANT_TORRENTZIP").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(32770));
    key = Nan::New("ZIP_AFL_CREATE_OR_KEEP_FILE_FOR_EMPTY_ARCHIVE").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(32771));
    key = Nan::New("ZIP_EXTRA_FIELD_ALL").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(32772));
    key = Nan::New("ZIP_EXTRA_FIELD_NEW").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(32773));
    key = Nan::New("ZIP_ER_OK").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(32774));
    key = Nan::New("ZIP_ER_MULTIDISK").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(32775));
    key = Nan::New("ZIP_ER_RENAME").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(32776));
    key = Nan::New("ZIP_ER_CLOSE").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(32777));
    key = Nan::New("ZIP_ER_SEEK").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(32778));
    key = Nan::New("ZIP_ER_READ").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(32779));
    key = Nan::New("ZIP_ER_WRITE").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(32780));
    key = Nan::New("ZIP_ER_CRC").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(32781));
    key = Nan::New("ZIP_ER_ZIPCLOSED").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(32782));
    key = Nan::New("ZIP_ER_NOENT").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(32783));
    key = Nan::New("ZIP_ER_EXISTS").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(32784));
    key = Nan::New("ZIP_ER_OPEN").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(32785));
    key = Nan::New("ZIP_ER_TMPOPEN").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(32786));
    key = Nan::New("ZIP_ER_ZLIB").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(32787));
    key = Nan::New("ZIP_ER_MEMORY").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(32788));
    key = Nan::New("ZIP_ER_CHANGED").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(32789));
    key = Nan::New("ZIP_ER_COMPNOTSUPP").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(32790));
    key = Nan::New("ZIP_ER_EOF").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(32791));
    key = Nan::New("ZIP_ER_INVAL").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(32792));
    key = Nan::New("ZIP_ER_NOZIP").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(32793));
    key = Nan::New("ZIP_ER_INTERNAL").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(32794));
    key = Nan::New("ZIP_ER_INCONS").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(32795));
    key = Nan::New("ZIP_ER_REMOVE").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(32796));
    key = Nan::New("ZIP_ER_DELETED").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(32797));
    key = Nan::New("ZIP_ER_ENCRNOTSUPP").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(32798));
    key = Nan::New("ZIP_ER_RDONLY").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(32799));
    key = Nan::New("ZIP_ER_NOPASSWD").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(32800));
    key = Nan::New("ZIP_ER_WRONGPASSWD").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(32801));
    key = Nan::New("ZIP_ER_OPNOTSUPP").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(32802));
    key = Nan::New("ZIP_ER_INUSE").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(32803));
    key = Nan::New("ZIP_ER_TELL").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(32804));
    key = Nan::New("ZIP_ER_COMPRESSED_DATA").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(32805));
    key = Nan::New("ZIP_ER_CANCELLED").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(32806));
    key = Nan::New("ZIP_ER_DATA_LENGTH").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(32807));
    key = Nan::New("ZIP_ER_NOT_ALLOWED").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(32808));
    key = Nan::New("ZIP_ET_NONE").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(32809));
    key = Nan::New("ZIP_ET_SYS").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(32810));
    key = Nan::New("ZIP_ET_ZLIB").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(32811));
    key = Nan::New("ZIP_ET_LIBZIP").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(32812));
    key = Nan::New("ZIP_OPSYS_DOS").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(32813));
    key = Nan::New("ZIP_OPSYS_AMIGA").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(32814));
    key = Nan::New("ZIP_OPSYS_OPENVMS").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(32815));
    key = Nan::New("ZIP_OPSYS_UNIX").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(32816));
    key = Nan::New("ZIP_OPSYS_VM_CMS").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(32817));
    key = Nan::New("ZIP_OPSYS_ATARI_ST").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(32818));
    key = Nan::New("ZIP_OPSYS_OS_2").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(32819));
    key = Nan::New("ZIP_OPSYS_MACINTOSH").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(32820));
    key = Nan::New("ZIP_OPSYS_Z_SYSTEM").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(32821));
    key = Nan::New("ZIP_OPSYS_CPM").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(32822));
    key = Nan::New("ZIP_OPSYS_WINDOWS_NTFS").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(32823));
    key = Nan::New("ZIP_OPSYS_MVS").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(32824));
    key = Nan::New("ZIP_OPSYS_VSE").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(32825));
    key = Nan::New("ZIP_OPSYS_ACORN_RISC").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(32826));
    key = Nan::New("ZIP_OPSYS_VFAT").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(32827));
    key = Nan::New("ZIP_OPSYS_ALTERNATE_MVS").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(32828));
    key = Nan::New("ZIP_OPSYS_BEOS").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(32829));
    key = Nan::New("ZIP_OPSYS_TANDEM").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(32830));
    key = Nan::New("ZIP_OPSYS_OS_400").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(32831));
    key = Nan::New("ZIP_OPSYS_OS_X").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(32832));
    key = Nan::New("ZIP_OPSYS_DEFAULT").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(32833));
    key = Nan::New("ZIP_SOURCE_SUPPORTS_READABLE").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(32834));
    key = Nan::New("ZIP_SOURCE_SUPPORTS_SEEKABLE").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(32835));
    key = Nan::New("ZIP_SOURCE_SUPPORTS_WRITABLE").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(32836));
    key = Nan::New("ZIP_FILE_ATTRIBUTES_HOST_SYSTEM").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(32837));
    key = Nan::New("ZIP_FILE_ATTRIBUTES_ASCII").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(32838));
    key = Nan::New("ZIP_FILE_ATTRIBUTES_VERSION_NEEDED").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(32839));
    key = Nan::New("ZIP_FILE_ATTRIBUTES_EXTERNAL_FILE_ATTRIBUTES").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(32840));
    key = Nan::New("ZIP_FILE_ATTRIBUTES_GENERAL_PURPOSE_BIT_FLAGS").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(32841));
    key = Nan::New("ZIP_ENCODING_UNKNOWN").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(32842));
    key = Nan::New("ZIP_ENCODING_ASCII").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(32843));
    key = Nan::New("ZIP_ENCODING_UTF8_KNOWN").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(32844));
    key = Nan::New("ZIP_ENCODING_UTF8_GUESSED").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(32845));
    key = Nan::New("ZIP_ENCODING_CP437").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(32846));
    key = Nan::New("ZIP_ENCODING_ERROR").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(32847));
    key = Nan::New("ZIP_SOURCE_WRITE_CLOSED").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(32848));
    key = Nan::New("ZIP_SOURCE_WRITE_OPEN").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(32849));
    key = Nan::New("ZIP_SOURCE_WRITE_FAILED").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(32850));
    key = Nan::New("ZIP_SOURCE_WRITE_REMOVED").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(32851));
    Nan::Set(exports, Nan::New("constants").ToLocalChecked(), constants);
}
bool ConvertZipConstant(Nan::NAN_METHOD_ARGS_TYPE& info, const int&& index, zip_flags_t& out) {
    Arguments args("libzipflags",info);
    if(!args.AssertArgumentType("Uint32", index, Arguments::IsUint32)) {
        return false;
    }
    auto val = Nan::To<v8::Uint32>(info[index]).ToLocalChecked()->Value();
    // ZIP_FL_NOCASE
    // ZIP_FL_RECOMPRESS
    // ZIP_FL_NODIR
    // ZIP_FL_COMPRESSED
    // ZIP_FL_UNCHANGED
    // ZIP_FL_ENCRYPTED
    // ZIP_FL_ENC_GUESS
    // ZIP_FL_ENC_RAW
    // ZIP_FL_ENC_STRICT
    // ZIP_FL_LOCAL
    // ZIP_FL_CENTRAL
    // ZIP_FL_ENC_UTF_8
    // ZIP_FL_ENC_CP437
    // ZIP_FL_OVERWRITE
    if(val & 1 || val & 4 || val & 8 || val & 16 || val & 32 || val & 64 || val & 128 || val & 256 || val & 512 || val & 1024 || val & 2048 || val & 4096 || val & 8192 || val & 16384) {
        out = 0;
        if(val & 1) {
            out |= ZIP_FL_NOCASE;
            val &= ~1;
        }
        if(val & 4) {
            out |= ZIP_FL_RECOMPRESS;
            val &= ~4;
        }
        if(val & 8) {
            out |= ZIP_FL_NODIR;
            val &= ~8;
        }
        if(val & 16) {
            out |= ZIP_FL_COMPRESSED;
            val &= ~16;
        }
        if(val & 32) {
            out |= ZIP_FL_UNCHANGED;
            val &= ~32;
        }
        if(val & 64) {
            out |= ZIP_FL_ENCRYPTED;
            val &= ~64;
        }
        if(val & 128) {
            out |= ZIP_FL_ENC_GUESS;
            val &= ~128;
        }
        if(val & 256) {
            out |= ZIP_FL_ENC_RAW;
            val &= ~256;
        }
        if(val & 512) {
            out |= ZIP_FL_ENC_STRICT;
            val &= ~512;
        }
        if(val & 1024) {
            out |= ZIP_FL_LOCAL;
            val &= ~1024;
        }
        if(val & 2048) {
            out |= ZIP_FL_CENTRAL;
            val &= ~2048;
        }
        if(val & 4096) {
            out |= ZIP_FL_ENC_UTF_8;
            val &= ~4096;
        }
        if(val & 8192) {
            out |= ZIP_FL_ENC_CP437;
            val &= ~8192;
        }
        if(val & 16384) {
            out |= ZIP_FL_OVERWRITE;
            val &= ~16384;
        }
        if(val != 0) {
            Nan::ThrowError(Nan::New("Failed to convert constant value to libzip constant due to invalid remaining flags: " + std::to_string(val)).ToLocalChecked());
            return false;
        }
        return true;
    }
    if(val == 32768) {
        out = ZIP_AFL_RDONLY;
        return true;
    }
    if(val == 32769) {
        out = ZIP_AFL_IS_TORRENTZIP;
        return true;
    }
    if(val == 32770) {
        out = ZIP_AFL_WANT_TORRENTZIP;
        return true;
    }
    if(val == 32771) {
        out = ZIP_AFL_CREATE_OR_KEEP_FILE_FOR_EMPTY_ARCHIVE;
        return true;
    }
    if(val == 32772) {
        out = ZIP_EXTRA_FIELD_ALL;
        return true;
    }
    if(val == 32773) {
        out = ZIP_EXTRA_FIELD_NEW;
        return true;
    }
    if(val == 32774) {
        out = ZIP_ER_OK;
        return true;
    }
    if(val == 32775) {
        out = ZIP_ER_MULTIDISK;
        return true;
    }
    if(val == 32776) {
        out = ZIP_ER_RENAME;
        return true;
    }
    if(val == 32777) {
        out = ZIP_ER_CLOSE;
        return true;
    }
    if(val == 32778) {
        out = ZIP_ER_SEEK;
        return true;
    }
    if(val == 32779) {
        out = ZIP_ER_READ;
        return true;
    }
    if(val == 32780) {
        out = ZIP_ER_WRITE;
        return true;
    }
    if(val == 32781) {
        out = ZIP_ER_CRC;
        return true;
    }
    if(val == 32782) {
        out = ZIP_ER_ZIPCLOSED;
        return true;
    }
    if(val == 32783) {
        out = ZIP_ER_NOENT;
        return true;
    }
    if(val == 32784) {
        out = ZIP_ER_EXISTS;
        return true;
    }
    if(val == 32785) {
        out = ZIP_ER_OPEN;
        return true;
    }
    if(val == 32786) {
        out = ZIP_ER_TMPOPEN;
        return true;
    }
    if(val == 32787) {
        out = ZIP_ER_ZLIB;
        return true;
    }
    if(val == 32788) {
        out = ZIP_ER_MEMORY;
        return true;
    }
    if(val == 32789) {
        out = ZIP_ER_CHANGED;
        return true;
    }
    if(val == 32790) {
        out = ZIP_ER_COMPNOTSUPP;
        return true;
    }
    if(val == 32791) {
        out = ZIP_ER_EOF;
        return true;
    }
    if(val == 32792) {
        out = ZIP_ER_INVAL;
        return true;
    }
    if(val == 32793) {
        out = ZIP_ER_NOZIP;
        return true;
    }
    if(val == 32794) {
        out = ZIP_ER_INTERNAL;
        return true;
    }
    if(val == 32795) {
        out = ZIP_ER_INCONS;
        return true;
    }
    if(val == 32796) {
        out = ZIP_ER_REMOVE;
        return true;
    }
    if(val == 32797) {
        out = ZIP_ER_DELETED;
        return true;
    }
    if(val == 32798) {
        out = ZIP_ER_ENCRNOTSUPP;
        return true;
    }
    if(val == 32799) {
        out = ZIP_ER_RDONLY;
        return true;
    }
    if(val == 32800) {
        out = ZIP_ER_NOPASSWD;
        return true;
    }
    if(val == 32801) {
        out = ZIP_ER_WRONGPASSWD;
        return true;
    }
    if(val == 32802) {
        out = ZIP_ER_OPNOTSUPP;
        return true;
    }
    if(val == 32803) {
        out = ZIP_ER_INUSE;
        return true;
    }
    if(val == 32804) {
        out = ZIP_ER_TELL;
        return true;
    }
    if(val == 32805) {
        out = ZIP_ER_COMPRESSED_DATA;
        return true;
    }
    if(val == 32806) {
        out = ZIP_ER_CANCELLED;
        return true;
    }
    if(val == 32807) {
        out = ZIP_ER_DATA_LENGTH;
        return true;
    }
    if(val == 32808) {
        out = ZIP_ER_NOT_ALLOWED;
        return true;
    }
    if(val == 32809) {
        out = ZIP_ET_NONE;
        return true;
    }
    if(val == 32810) {
        out = ZIP_ET_SYS;
        return true;
    }
    if(val == 32811) {
        out = ZIP_ET_ZLIB;
        return true;
    }
    if(val == 32812) {
        out = ZIP_ET_LIBZIP;
        return true;
    }
    if(val == 32813) {
        out = ZIP_OPSYS_DOS;
        return true;
    }
    if(val == 32814) {
        out = ZIP_OPSYS_AMIGA;
        return true;
    }
    if(val == 32815) {
        out = ZIP_OPSYS_OPENVMS;
        return true;
    }
    if(val == 32816) {
        out = ZIP_OPSYS_UNIX;
        return true;
    }
    if(val == 32817) {
        out = ZIP_OPSYS_VM_CMS;
        return true;
    }
    if(val == 32818) {
        out = ZIP_OPSYS_ATARI_ST;
        return true;
    }
    if(val == 32819) {
        out = ZIP_OPSYS_OS_2;
        return true;
    }
    if(val == 32820) {
        out = ZIP_OPSYS_MACINTOSH;
        return true;
    }
    if(val == 32821) {
        out = ZIP_OPSYS_Z_SYSTEM;
        return true;
    }
    if(val == 32822) {
        out = ZIP_OPSYS_CPM;
        return true;
    }
    if(val == 32823) {
        out = ZIP_OPSYS_WINDOWS_NTFS;
        return true;
    }
    if(val == 32824) {
        out = ZIP_OPSYS_MVS;
        return true;
    }
    if(val == 32825) {
        out = ZIP_OPSYS_VSE;
        return true;
    }
    if(val == 32826) {
        out = ZIP_OPSYS_ACORN_RISC;
        return true;
    }
    if(val == 32827) {
        out = ZIP_OPSYS_VFAT;
        return true;
    }
    if(val == 32828) {
        out = ZIP_OPSYS_ALTERNATE_MVS;
        return true;
    }
    if(val == 32829) {
        out = ZIP_OPSYS_BEOS;
        return true;
    }
    if(val == 32830) {
        out = ZIP_OPSYS_TANDEM;
        return true;
    }
    if(val == 32831) {
        out = ZIP_OPSYS_OS_400;
        return true;
    }
    if(val == 32832) {
        out = ZIP_OPSYS_OS_X;
        return true;
    }
    if(val == 32833) {
        out = ZIP_OPSYS_DEFAULT;
        return true;
    }
    if(val == 32834) {
        out = ZIP_SOURCE_SUPPORTS_READABLE;
        return true;
    }
    if(val == 32835) {
        out = ZIP_SOURCE_SUPPORTS_SEEKABLE;
        return true;
    }
    if(val == 32836) {
        out = ZIP_SOURCE_SUPPORTS_WRITABLE;
        return true;
    }
    if(val == 32837) {
        out = ZIP_FILE_ATTRIBUTES_HOST_SYSTEM;
        return true;
    }
    if(val == 32838) {
        out = ZIP_FILE_ATTRIBUTES_ASCII;
        return true;
    }
    if(val == 32839) {
        out = ZIP_FILE_ATTRIBUTES_VERSION_NEEDED;
        return true;
    }
    if(val == 32840) {
        out = ZIP_FILE_ATTRIBUTES_EXTERNAL_FILE_ATTRIBUTES;
        return true;
    }
    if(val == 32841) {
        out = ZIP_FILE_ATTRIBUTES_GENERAL_PURPOSE_BIT_FLAGS;
        return true;
    }
    if(val == 32842) {
        out = ZIP_ENCODING_UNKNOWN;
        return true;
    }
    if(val == 32843) {
        out = ZIP_ENCODING_ASCII;
        return true;
    }
    if(val == 32844) {
        out = ZIP_ENCODING_UTF8_KNOWN;
        return true;
    }
    if(val == 32845) {
        out = ZIP_ENCODING_UTF8_GUESSED;
        return true;
    }
    if(val == 32846) {
        out = ZIP_ENCODING_CP437;
        return true;
    }
    if(val == 32847) {
        out = ZIP_ENCODING_ERROR;
        return true;
    }
    if(val == 32848) {
        out = ZIP_SOURCE_WRITE_CLOSED;
        return true;
    }
    if(val == 32849) {
        out = ZIP_SOURCE_WRITE_OPEN;
        return true;
    }
    if(val == 32850) {
        out = ZIP_SOURCE_WRITE_FAILED;
        return true;
    }
    if(val == 32851) {
        out = ZIP_SOURCE_WRITE_REMOVED;
        return true;
    }
    if(val != 0) {
        Nan::ThrowError(Nan::New("Failed to convert constant value to libzip constant: " + std::to_string(val)).ToLocalChecked());
        return false;
    }
    out = 0;
    return true;
}
bool GetBindingZipConstant(const zip_flags_t& value, v8::Local<v8::Uint32>& out) {
    uint32_t v;
    if(
        (value & ZIP_FL_NOCASE) ||
        (value & ZIP_FL_RECOMPRESS) ||
        (value & ZIP_FL_NODIR) ||
        (value & ZIP_FL_COMPRESSED) ||
        (value & ZIP_FL_UNCHANGED) ||
        (value & ZIP_FL_ENCRYPTED) ||
        (value & ZIP_FL_ENC_GUESS) ||
        (value & ZIP_FL_ENC_RAW) ||
        (value & ZIP_FL_ENC_STRICT) ||
        (value & ZIP_FL_LOCAL) ||
        (value & ZIP_FL_CENTRAL) ||
        (value & ZIP_FL_ENC_UTF_8) ||
        (value & ZIP_FL_ENC_CP437) ||
        (value & ZIP_FL_OVERWRITE)
    ) {
        v = 0;
        if(value & ZIP_FL_NOCASE) {
            v |= 1;
        }
        if(value & ZIP_FL_RECOMPRESS) {
            v |= 4;
        }
        if(value & ZIP_FL_NODIR) {
            v |= 8;
        }
        if(value & ZIP_FL_COMPRESSED) {
            v |= 16;
        }
        if(value & ZIP_FL_UNCHANGED) {
            v |= 32;
        }
        if(value & ZIP_FL_ENCRYPTED) {
            v |= 64;
        }
        if(value & ZIP_FL_ENC_GUESS) {
            v |= 128;
        }
        if(value & ZIP_FL_ENC_RAW) {
            v |= 256;
        }
        if(value & ZIP_FL_ENC_STRICT) {
            v |= 512;
        }
        if(value & ZIP_FL_LOCAL) {
            v |= 1024;
        }
        if(value & ZIP_FL_CENTRAL) {
            v |= 2048;
        }
        if(value & ZIP_FL_ENC_UTF_8) {
            v |= 4096;
        }
        if(value & ZIP_FL_ENC_CP437) {
            v |= 8192;
        }
        if(value & ZIP_FL_OVERWRITE) {
            v |= 16384;
        }
        out = Nan::New<v8::Uint32>(v);
        return true;
    }
    if(value == ZIP_AFL_RDONLY) {
        out = Nan::New<v8::Uint32>(32768);
        return true;
    }
    if(value == ZIP_AFL_IS_TORRENTZIP) {
        out = Nan::New<v8::Uint32>(32769);
        return true;
    }
    if(value == ZIP_AFL_WANT_TORRENTZIP) {
        out = Nan::New<v8::Uint32>(32770);
        return true;
    }
    if(value == ZIP_AFL_CREATE_OR_KEEP_FILE_FOR_EMPTY_ARCHIVE) {
        out = Nan::New<v8::Uint32>(32771);
        return true;
    }
    if(value == ZIP_EXTRA_FIELD_ALL) {
        out = Nan::New<v8::Uint32>(32772);
        return true;
    }
    if(value == ZIP_EXTRA_FIELD_NEW) {
        out = Nan::New<v8::Uint32>(32773);
        return true;
    }
    if(value == ZIP_ER_OK) {
        out = Nan::New<v8::Uint32>(32774);
        return true;
    }
    if(value == ZIP_ER_MULTIDISK) {
        out = Nan::New<v8::Uint32>(32775);
        return true;
    }
    if(value == ZIP_ER_RENAME) {
        out = Nan::New<v8::Uint32>(32776);
        return true;
    }
    if(value == ZIP_ER_CLOSE) {
        out = Nan::New<v8::Uint32>(32777);
        return true;
    }
    if(value == ZIP_ER_SEEK) {
        out = Nan::New<v8::Uint32>(32778);
        return true;
    }
    if(value == ZIP_ER_READ) {
        out = Nan::New<v8::Uint32>(32779);
        return true;
    }
    if(value == ZIP_ER_WRITE) {
        out = Nan::New<v8::Uint32>(32780);
        return true;
    }
    if(value == ZIP_ER_CRC) {
        out = Nan::New<v8::Uint32>(32781);
        return true;
    }
    if(value == ZIP_ER_ZIPCLOSED) {
        out = Nan::New<v8::Uint32>(32782);
        return true;
    }
    if(value == ZIP_ER_NOENT) {
        out = Nan::New<v8::Uint32>(32783);
        return true;
    }
    if(value == ZIP_ER_EXISTS) {
        out = Nan::New<v8::Uint32>(32784);
        return true;
    }
    if(value == ZIP_ER_OPEN) {
        out = Nan::New<v8::Uint32>(32785);
        return true;
    }
    if(value == ZIP_ER_TMPOPEN) {
        out = Nan::New<v8::Uint32>(32786);
        return true;
    }
    if(value == ZIP_ER_ZLIB) {
        out = Nan::New<v8::Uint32>(32787);
        return true;
    }
    if(value == ZIP_ER_MEMORY) {
        out = Nan::New<v8::Uint32>(32788);
        return true;
    }
    if(value == ZIP_ER_CHANGED) {
        out = Nan::New<v8::Uint32>(32789);
        return true;
    }
    if(value == ZIP_ER_COMPNOTSUPP) {
        out = Nan::New<v8::Uint32>(32790);
        return true;
    }
    if(value == ZIP_ER_EOF) {
        out = Nan::New<v8::Uint32>(32791);
        return true;
    }
    if(value == ZIP_ER_INVAL) {
        out = Nan::New<v8::Uint32>(32792);
        return true;
    }
    if(value == ZIP_ER_NOZIP) {
        out = Nan::New<v8::Uint32>(32793);
        return true;
    }
    if(value == ZIP_ER_INTERNAL) {
        out = Nan::New<v8::Uint32>(32794);
        return true;
    }
    if(value == ZIP_ER_INCONS) {
        out = Nan::New<v8::Uint32>(32795);
        return true;
    }
    if(value == ZIP_ER_REMOVE) {
        out = Nan::New<v8::Uint32>(32796);
        return true;
    }
    if(value == ZIP_ER_DELETED) {
        out = Nan::New<v8::Uint32>(32797);
        return true;
    }
    if(value == ZIP_ER_ENCRNOTSUPP) {
        out = Nan::New<v8::Uint32>(32798);
        return true;
    }
    if(value == ZIP_ER_RDONLY) {
        out = Nan::New<v8::Uint32>(32799);
        return true;
    }
    if(value == ZIP_ER_NOPASSWD) {
        out = Nan::New<v8::Uint32>(32800);
        return true;
    }
    if(value == ZIP_ER_WRONGPASSWD) {
        out = Nan::New<v8::Uint32>(32801);
        return true;
    }
    if(value == ZIP_ER_OPNOTSUPP) {
        out = Nan::New<v8::Uint32>(32802);
        return true;
    }
    if(value == ZIP_ER_INUSE) {
        out = Nan::New<v8::Uint32>(32803);
        return true;
    }
    if(value == ZIP_ER_TELL) {
        out = Nan::New<v8::Uint32>(32804);
        return true;
    }
    if(value == ZIP_ER_COMPRESSED_DATA) {
        out = Nan::New<v8::Uint32>(32805);
        return true;
    }
    if(value == ZIP_ER_CANCELLED) {
        out = Nan::New<v8::Uint32>(32806);
        return true;
    }
    if(value == ZIP_ER_DATA_LENGTH) {
        out = Nan::New<v8::Uint32>(32807);
        return true;
    }
    if(value == ZIP_ER_NOT_ALLOWED) {
        out = Nan::New<v8::Uint32>(32808);
        return true;
    }
    if(value == ZIP_ET_NONE) {
        out = Nan::New<v8::Uint32>(32809);
        return true;
    }
    if(value == ZIP_ET_SYS) {
        out = Nan::New<v8::Uint32>(32810);
        return true;
    }
    if(value == ZIP_ET_ZLIB) {
        out = Nan::New<v8::Uint32>(32811);
        return true;
    }
    if(value == ZIP_ET_LIBZIP) {
        out = Nan::New<v8::Uint32>(32812);
        return true;
    }
    if(value == ZIP_OPSYS_DOS) {
        out = Nan::New<v8::Uint32>(32813);
        return true;
    }
    if(value == ZIP_OPSYS_AMIGA) {
        out = Nan::New<v8::Uint32>(32814);
        return true;
    }
    if(value == ZIP_OPSYS_OPENVMS) {
        out = Nan::New<v8::Uint32>(32815);
        return true;
    }
    if(value == ZIP_OPSYS_UNIX) {
        out = Nan::New<v8::Uint32>(32816);
        return true;
    }
    if(value == ZIP_OPSYS_VM_CMS) {
        out = Nan::New<v8::Uint32>(32817);
        return true;
    }
    if(value == ZIP_OPSYS_ATARI_ST) {
        out = Nan::New<v8::Uint32>(32818);
        return true;
    }
    if(value == ZIP_OPSYS_OS_2) {
        out = Nan::New<v8::Uint32>(32819);
        return true;
    }
    if(value == ZIP_OPSYS_MACINTOSH) {
        out = Nan::New<v8::Uint32>(32820);
        return true;
    }
    if(value == ZIP_OPSYS_Z_SYSTEM) {
        out = Nan::New<v8::Uint32>(32821);
        return true;
    }
    if(value == ZIP_OPSYS_CPM) {
        out = Nan::New<v8::Uint32>(32822);
        return true;
    }
    if(value == ZIP_OPSYS_WINDOWS_NTFS) {
        out = Nan::New<v8::Uint32>(32823);
        return true;
    }
    if(value == ZIP_OPSYS_MVS) {
        out = Nan::New<v8::Uint32>(32824);
        return true;
    }
    if(value == ZIP_OPSYS_VSE) {
        out = Nan::New<v8::Uint32>(32825);
        return true;
    }
    if(value == ZIP_OPSYS_ACORN_RISC) {
        out = Nan::New<v8::Uint32>(32826);
        return true;
    }
    if(value == ZIP_OPSYS_VFAT) {
        out = Nan::New<v8::Uint32>(32827);
        return true;
    }
    if(value == ZIP_OPSYS_ALTERNATE_MVS) {
        out = Nan::New<v8::Uint32>(32828);
        return true;
    }
    if(value == ZIP_OPSYS_BEOS) {
        out = Nan::New<v8::Uint32>(32829);
        return true;
    }
    if(value == ZIP_OPSYS_TANDEM) {
        out = Nan::New<v8::Uint32>(32830);
        return true;
    }
    if(value == ZIP_OPSYS_OS_400) {
        out = Nan::New<v8::Uint32>(32831);
        return true;
    }
    if(value == ZIP_OPSYS_OS_X) {
        out = Nan::New<v8::Uint32>(32832);
        return true;
    }
    if(value == ZIP_OPSYS_DEFAULT) {
        out = Nan::New<v8::Uint32>(32833);
        return true;
    }
    if(value == ZIP_SOURCE_SUPPORTS_READABLE) {
        out = Nan::New<v8::Uint32>(32834);
        return true;
    }
    if(value == ZIP_SOURCE_SUPPORTS_SEEKABLE) {
        out = Nan::New<v8::Uint32>(32835);
        return true;
    }
    if(value == ZIP_SOURCE_SUPPORTS_WRITABLE) {
        out = Nan::New<v8::Uint32>(32836);
        return true;
    }
    if(value == ZIP_FILE_ATTRIBUTES_HOST_SYSTEM) {
        out = Nan::New<v8::Uint32>(32837);
        return true;
    }
    if(value == ZIP_FILE_ATTRIBUTES_ASCII) {
        out = Nan::New<v8::Uint32>(32838);
        return true;
    }
    if(value == ZIP_FILE_ATTRIBUTES_VERSION_NEEDED) {
        out = Nan::New<v8::Uint32>(32839);
        return true;
    }
    if(value == ZIP_FILE_ATTRIBUTES_EXTERNAL_FILE_ATTRIBUTES) {
        out = Nan::New<v8::Uint32>(32840);
        return true;
    }
    if(value == ZIP_FILE_ATTRIBUTES_GENERAL_PURPOSE_BIT_FLAGS) {
        out = Nan::New<v8::Uint32>(32841);
        return true;
    }
    if(value == ZIP_ENCODING_UNKNOWN) {
        out = Nan::New<v8::Uint32>(32842);
        return true;
    }
    if(value == ZIP_ENCODING_ASCII) {
        out = Nan::New<v8::Uint32>(32843);
        return true;
    }
    if(value == ZIP_ENCODING_UTF8_KNOWN) {
        out = Nan::New<v8::Uint32>(32844);
        return true;
    }
    if(value == ZIP_ENCODING_UTF8_GUESSED) {
        out = Nan::New<v8::Uint32>(32845);
        return true;
    }
    if(value == ZIP_ENCODING_CP437) {
        out = Nan::New<v8::Uint32>(32846);
        return true;
    }
    if(value == ZIP_ENCODING_ERROR) {
        out = Nan::New<v8::Uint32>(32847);
        return true;
    }
    if(value == ZIP_SOURCE_WRITE_CLOSED) {
        out = Nan::New<v8::Uint32>(32848);
        return true;
    }
    if(value == ZIP_SOURCE_WRITE_OPEN) {
        out = Nan::New<v8::Uint32>(32849);
        return true;
    }
    if(value == ZIP_SOURCE_WRITE_FAILED) {
        out = Nan::New<v8::Uint32>(32850);
        return true;
    }
    if(value == ZIP_SOURCE_WRITE_REMOVED) {
        out = Nan::New<v8::Uint32>(32851);
        return true;
    }
    Nan::ThrowError(Nan::New("Failed to create binding value from original value: " + std::to_string(value)).ToLocalChecked());
    return false;
}
void SetZipOpenModeFlags(v8::Local<v8::Object> exports) {
    auto constants = GetOrCreateConstants(exports);
    v8::Local<v8::String> key;
    key = Nan::New("ZIP_CREATE").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(1));
    key = Nan::New("ZIP_EXCL").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(4));
    key = Nan::New("ZIP_CHECKCONS").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(8));
    key = Nan::New("ZIP_TRUNCATE").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(16));
    key = Nan::New("ZIP_RDONLY").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(32));
    Nan::Set(exports, Nan::New("constants").ToLocalChecked(), constants);
}
bool ConvertZipOpenModeFlag(Nan::NAN_METHOD_ARGS_TYPE& info, const int&& index, int& out) {
    Arguments args("libzipflags",info);
    if(!args.AssertArgumentType("Uint32", index, Arguments::IsUint32)) {
        return false;
    }
    auto val = Nan::To<v8::Uint32>(info[index]).ToLocalChecked()->Value();
    // ZIP_CREATE
    // ZIP_EXCL
    // ZIP_CHECKCONS
    // ZIP_TRUNCATE
    // ZIP_RDONLY
    if(val & 1 || val & 4 || val & 8 || val & 16 || val & 32) {
        out = 0;
        if(val & 1) {
            out |= ZIP_CREATE;
            val &= ~1;
        }
        if(val & 4) {
            out |= ZIP_EXCL;
            val &= ~4;
        }
        if(val & 8) {
            out |= ZIP_CHECKCONS;
            val &= ~8;
        }
        if(val & 16) {
            out |= ZIP_TRUNCATE;
            val &= ~16;
        }
        if(val & 32) {
            out |= ZIP_RDONLY;
            val &= ~32;
        }
        if(val != 0) {
            Nan::ThrowError(Nan::New("Failed to convert constant value to libzip constant due to invalid remaining flags: " + std::to_string(val)).ToLocalChecked());
            return false;
        }
        return true;
    }
    if(val != 0) {
        Nan::ThrowError(Nan::New("Failed to convert constant value to libzip constant: " + std::to_string(val)).ToLocalChecked());
        return false;
    }
    out = 0;
    return true;
}
bool GetBindingZipOpenModeFlag(const int& value, v8::Local<v8::Uint32>& out) {
    uint32_t v;
    if(
        (value & ZIP_CREATE) ||
        (value & ZIP_EXCL) ||
        (value & ZIP_CHECKCONS) ||
        (value & ZIP_TRUNCATE) ||
        (value & ZIP_RDONLY)
    ) {
        v = 0;
        if(value & ZIP_CREATE) {
            v |= 1;
        }
        if(value & ZIP_EXCL) {
            v |= 4;
        }
        if(value & ZIP_CHECKCONS) {
            v |= 8;
        }
        if(value & ZIP_TRUNCATE) {
            v |= 16;
        }
        if(value & ZIP_RDONLY) {
            v |= 32;
        }
        out = Nan::New<v8::Uint32>(v);
        return true;
    }
    Nan::ThrowError(Nan::New("Failed to create binding value from original value: " + std::to_string(value)).ToLocalChecked());
    return false;
}
void SetZipLengthConstants(v8::Local<v8::Object> exports) {
    auto constants = GetOrCreateConstants(exports);
    v8::Local<v8::String> key;
    key = Nan::New("ZIP_LENGTH_TO_END").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(1));
    key = Nan::New("ZIP_LENGTH_UNCHECKED").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(2));
    Nan::Set(exports, Nan::New("constants").ToLocalChecked(), constants);
}
bool ConvertZipLengthConstant(Nan::NAN_METHOD_ARGS_TYPE& info, const int&& index, zip_int32_t& out) {
    Arguments args("libzipflags",info);
    if(!args.AssertArgumentType("Int32", index, Arguments::IsInt32)) {
        return false;
    }
    auto val = Nan::To<v8::Int32>(info[index]).ToLocalChecked()->Value();
    if(val == 1) {
        out = ZIP_LENGTH_TO_END;
        return true;
    }
    if(val == 2) {
        out = ZIP_LENGTH_UNCHECKED;
        return true;
    }
    if(val != 0) {
        Nan::ThrowError(Nan::New("Failed to convert constant value to libzip constant: " + std::to_string(val)).ToLocalChecked());
        return false;
    }
    out = 0;
    return true;
}
bool GetBindingZipLengthConstant(const zip_int32_t& value, v8::Local<v8::Int32>& out) {
    if(value == ZIP_LENGTH_TO_END) {
        out = Nan::New<v8::Int32>(1);
        return true;
    }
    if(value == ZIP_LENGTH_UNCHECKED) {
        out = Nan::New<v8::Int32>(2);
        return true;
    }
    Nan::ThrowError(Nan::New("Failed to create binding value from original value: " + std::to_string(value)).ToLocalChecked());
    return false;
}
void SetZipStatFlags(v8::Local<v8::Object> exports) {
    auto constants = GetOrCreateConstants(exports);
    v8::Local<v8::String> key;
    key = Nan::New("ZIP_STAT_NAME").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(1));
    key = Nan::New("ZIP_STAT_INDEX").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(4));
    key = Nan::New("ZIP_STAT_SIZE").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(8));
    key = Nan::New("ZIP_STAT_COMP_SIZE").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(16));
    key = Nan::New("ZIP_STAT_MTIME").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(32));
    key = Nan::New("ZIP_STAT_CRC").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(64));
    key = Nan::New("ZIP_STAT_COMP_METHOD").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(128));
    key = Nan::New("ZIP_STAT_ENCRYPTION_METHOD").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(256));
    key = Nan::New("ZIP_STAT_FLAGS").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(512));
    Nan::Set(exports, Nan::New("constants").ToLocalChecked(), constants);
}
bool ConvertZipStatFlag(Nan::NAN_METHOD_ARGS_TYPE& info, const int&& index, zip_flags_t& out) {
    Arguments args("libzipflags",info);
    if(!args.AssertArgumentType("Uint32", index, Arguments::IsUint32)) {
        return false;
    }
    auto val = Nan::To<v8::Uint32>(info[index]).ToLocalChecked()->Value();
    // ZIP_STAT_NAME
    // ZIP_STAT_INDEX
    // ZIP_STAT_SIZE
    // ZIP_STAT_COMP_SIZE
    // ZIP_STAT_MTIME
    // ZIP_STAT_CRC
    // ZIP_STAT_COMP_METHOD
    // ZIP_STAT_ENCRYPTION_METHOD
    // ZIP_STAT_FLAGS
    if(val & 1 || val & 4 || val & 8 || val & 16 || val & 32 || val & 64 || val & 128 || val & 256 || val & 512) {
        out = 0;
        if(val & 1) {
            out |= ZIP_STAT_NAME;
            val &= ~1;
        }
        if(val & 4) {
            out |= ZIP_STAT_INDEX;
            val &= ~4;
        }
        if(val & 8) {
            out |= ZIP_STAT_SIZE;
            val &= ~8;
        }
        if(val & 16) {
            out |= ZIP_STAT_COMP_SIZE;
            val &= ~16;
        }
        if(val & 32) {
            out |= ZIP_STAT_MTIME;
            val &= ~32;
        }
        if(val & 64) {
            out |= ZIP_STAT_CRC;
            val &= ~64;
        }
        if(val & 128) {
            out |= ZIP_STAT_COMP_METHOD;
            val &= ~128;
        }
        if(val & 256) {
            out |= ZIP_STAT_ENCRYPTION_METHOD;
            val &= ~256;
        }
        if(val & 512) {
            out |= ZIP_STAT_FLAGS;
            val &= ~512;
        }
        if(val != 0) {
            Nan::ThrowError(Nan::New("Failed to convert constant value to libzip constant due to invalid remaining flags: " + std::to_string(val)).ToLocalChecked());
            return false;
        }
        return true;
    }
    if(val != 0) {
        Nan::ThrowError(Nan::New("Failed to convert constant value to libzip constant: " + std::to_string(val)).ToLocalChecked());
        return false;
    }
    out = 0;
    return true;
}
bool GetBindingZipStatFlag(const zip_flags_t& value, v8::Local<v8::Uint32>& out) {
    uint32_t v;
    if(
        (value & ZIP_STAT_NAME) ||
        (value & ZIP_STAT_INDEX) ||
        (value & ZIP_STAT_SIZE) ||
        (value & ZIP_STAT_COMP_SIZE) ||
        (value & ZIP_STAT_MTIME) ||
        (value & ZIP_STAT_CRC) ||
        (value & ZIP_STAT_COMP_METHOD) ||
        (value & ZIP_STAT_ENCRYPTION_METHOD) ||
        (value & ZIP_STAT_FLAGS)
    ) {
        v = 0;
        if(value & ZIP_STAT_NAME) {
            v |= 1;
        }
        if(value & ZIP_STAT_INDEX) {
            v |= 4;
        }
        if(value & ZIP_STAT_SIZE) {
            v |= 8;
        }
        if(value & ZIP_STAT_COMP_SIZE) {
            v |= 16;
        }
        if(value & ZIP_STAT_MTIME) {
            v |= 32;
        }
        if(value & ZIP_STAT_CRC) {
            v |= 64;
        }
        if(value & ZIP_STAT_COMP_METHOD) {
            v |= 128;
        }
        if(value & ZIP_STAT_ENCRYPTION_METHOD) {
            v |= 256;
        }
        if(value & ZIP_STAT_FLAGS) {
            v |= 512;
        }
        out = Nan::New<v8::Uint32>(v);
        return true;
    }
    Nan::ThrowError(Nan::New("Failed to create binding value from original value: " + std::to_string(value)).ToLocalChecked());
    return false;
}
