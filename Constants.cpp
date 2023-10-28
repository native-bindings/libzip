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
    uint32_t val = Nan::To<v8::Uint32>(info[index]).ToLocalChecked()->Value();
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
void SetZipConstants(v8::Local<v8::Object> exports) {
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
    key = Nan::New("ZIP_FL_NOCASE").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(64));
    key = Nan::New("ZIP_FL_RECOMPRESS").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(128));
    key = Nan::New("ZIP_FL_NODIR").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(256));
    key = Nan::New("ZIP_FL_COMPRESSED").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(512));
    key = Nan::New("ZIP_FL_UNCHANGED").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(1024));
    key = Nan::New("ZIP_FL_ENCRYPTED").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(2048));
    key = Nan::New("ZIP_FL_ENC_GUESS").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(4096));
    key = Nan::New("ZIP_FL_ENC_RAW").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(8192));
    key = Nan::New("ZIP_FL_ENC_STRICT").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(16384));
    key = Nan::New("ZIP_FL_LOCAL").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(32768));
    key = Nan::New("ZIP_FL_CENTRAL").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(65536));
    key = Nan::New("ZIP_FL_ENC_UTF_8").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(131072));
    key = Nan::New("ZIP_FL_ENC_CP437").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(262144));
    key = Nan::New("ZIP_FL_OVERWRITE").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(524288));
    key = Nan::New("ZIP_AFL_RDONLY").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(1048576));
    key = Nan::New("ZIP_AFL_IS_TORRENTZIP").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(1048577));
    key = Nan::New("ZIP_AFL_WANT_TORRENTZIP").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(1048578));
    key = Nan::New("ZIP_AFL_CREATE_OR_KEEP_FILE_FOR_EMPTY_ARCHIVE").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(1048579));
    key = Nan::New("ZIP_EXTRA_FIELD_ALL").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(1048580));
    key = Nan::New("ZIP_EXTRA_FIELD_NEW").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(1048581));
    key = Nan::New("ZIP_LENGTH_TO_END").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(1048582));
    key = Nan::New("ZIP_LENGTH_UNCHECKED").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(1048583));
    key = Nan::New("ZIP_ER_OK").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(1048584));
    key = Nan::New("ZIP_ER_MULTIDISK").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(1048585));
    key = Nan::New("ZIP_ER_RENAME").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(1048586));
    key = Nan::New("ZIP_ER_CLOSE").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(1048587));
    key = Nan::New("ZIP_ER_SEEK").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(1048588));
    key = Nan::New("ZIP_ER_READ").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(1048589));
    key = Nan::New("ZIP_ER_WRITE").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(1048590));
    key = Nan::New("ZIP_ER_CRC").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(1048591));
    key = Nan::New("ZIP_ER_ZIPCLOSED").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(1048592));
    key = Nan::New("ZIP_ER_NOENT").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(1048593));
    key = Nan::New("ZIP_ER_EXISTS").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(1048594));
    key = Nan::New("ZIP_ER_OPEN").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(1048595));
    key = Nan::New("ZIP_ER_TMPOPEN").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(1048596));
    key = Nan::New("ZIP_ER_ZLIB").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(1048597));
    key = Nan::New("ZIP_ER_MEMORY").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(1048598));
    key = Nan::New("ZIP_ER_CHANGED").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(1048599));
    key = Nan::New("ZIP_ER_COMPNOTSUPP").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(1048600));
    key = Nan::New("ZIP_ER_EOF").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(1048601));
    key = Nan::New("ZIP_ER_INVAL").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(1048602));
    key = Nan::New("ZIP_ER_NOZIP").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(1048603));
    key = Nan::New("ZIP_ER_INTERNAL").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(1048604));
    key = Nan::New("ZIP_ER_INCONS").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(1048605));
    key = Nan::New("ZIP_ER_REMOVE").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(1048606));
    key = Nan::New("ZIP_ER_DELETED").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(1048607));
    key = Nan::New("ZIP_ER_ENCRNOTSUPP").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(1048608));
    key = Nan::New("ZIP_ER_RDONLY").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(1048609));
    key = Nan::New("ZIP_ER_NOPASSWD").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(1048610));
    key = Nan::New("ZIP_ER_WRONGPASSWD").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(1048611));
    key = Nan::New("ZIP_ER_OPNOTSUPP").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(1048612));
    key = Nan::New("ZIP_ER_INUSE").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(1048613));
    key = Nan::New("ZIP_ER_TELL").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(1048614));
    key = Nan::New("ZIP_ER_COMPRESSED_DATA").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(1048615));
    key = Nan::New("ZIP_ER_CANCELLED").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(1048616));
    key = Nan::New("ZIP_ER_DATA_LENGTH").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(1048617));
    key = Nan::New("ZIP_ER_NOT_ALLOWED").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(1048618));
    key = Nan::New("ZIP_ET_NONE").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(1048619));
    key = Nan::New("ZIP_ET_SYS").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(1048620));
    key = Nan::New("ZIP_ET_ZLIB").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(1048621));
    key = Nan::New("ZIP_ET_LIBZIP").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(1048622));
    key = Nan::New("ZIP_CM_DEFAULT").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(1048623));
    key = Nan::New("ZIP_CM_STORE").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(1048624));
    key = Nan::New("ZIP_CM_SHRINK").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(1048625));
    key = Nan::New("ZIP_CM_REDUCE_1").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(1048626));
    key = Nan::New("ZIP_CM_REDUCE_2").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(1048627));
    key = Nan::New("ZIP_CM_REDUCE_3").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(1048628));
    key = Nan::New("ZIP_CM_REDUCE_4").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(1048629));
    key = Nan::New("ZIP_CM_IMPLODE").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(1048630));
    key = Nan::New("ZIP_CM_DEFLATE").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(1048631));
    key = Nan::New("ZIP_CM_DEFLATE64").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(1048632));
    key = Nan::New("ZIP_CM_PKWARE_IMPLODE").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(1048633));
    key = Nan::New("ZIP_CM_BZIP2").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(1048634));
    key = Nan::New("ZIP_CM_LZMA").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(1048635));
    key = Nan::New("ZIP_CM_TERSE").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(1048636));
    key = Nan::New("ZIP_CM_LZ77").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(1048637));
    key = Nan::New("ZIP_CM_LZMA2").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(1048638));
    key = Nan::New("ZIP_CM_ZSTD").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(1048639));
    key = Nan::New("ZIP_CM_XZ").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(1048640));
    key = Nan::New("ZIP_CM_JPEG").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(1048641));
    key = Nan::New("ZIP_CM_WAVPACK").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(1048642));
    key = Nan::New("ZIP_CM_PPMD").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(1048643));
    key = Nan::New("ZIP_EM_NONE").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(1048644));
    key = Nan::New("ZIP_EM_TRAD_PKWARE").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(1048645));
    key = Nan::New("ZIP_EM_AES_128").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(1048646));
    key = Nan::New("ZIP_EM_AES_192").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(1048647));
    key = Nan::New("ZIP_EM_AES_256").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(1048648));
    key = Nan::New("ZIP_EM_UNKNOWN").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(1048649));
    key = Nan::New("ZIP_OPSYS_DOS").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(1048650));
    key = Nan::New("ZIP_OPSYS_AMIGA").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(1048651));
    key = Nan::New("ZIP_OPSYS_OPENVMS").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(1048652));
    key = Nan::New("ZIP_OPSYS_UNIX").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(1048653));
    key = Nan::New("ZIP_OPSYS_VM_CMS").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(1048654));
    key = Nan::New("ZIP_OPSYS_ATARI_ST").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(1048655));
    key = Nan::New("ZIP_OPSYS_OS_2").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(1048656));
    key = Nan::New("ZIP_OPSYS_MACINTOSH").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(1048657));
    key = Nan::New("ZIP_OPSYS_Z_SYSTEM").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(1048658));
    key = Nan::New("ZIP_OPSYS_CPM").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(1048659));
    key = Nan::New("ZIP_OPSYS_WINDOWS_NTFS").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(1048660));
    key = Nan::New("ZIP_OPSYS_MVS").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(1048661));
    key = Nan::New("ZIP_OPSYS_VSE").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(1048662));
    key = Nan::New("ZIP_OPSYS_ACORN_RISC").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(1048663));
    key = Nan::New("ZIP_OPSYS_VFAT").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(1048664));
    key = Nan::New("ZIP_OPSYS_ALTERNATE_MVS").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(1048665));
    key = Nan::New("ZIP_OPSYS_BEOS").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(1048666));
    key = Nan::New("ZIP_OPSYS_TANDEM").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(1048667));
    key = Nan::New("ZIP_OPSYS_OS_400").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(1048668));
    key = Nan::New("ZIP_OPSYS_OS_X").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(1048669));
    key = Nan::New("ZIP_OPSYS_DEFAULT").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(1048670));
    key = Nan::New("ZIP_SOURCE_SUPPORTS_READABLE").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(1048671));
    key = Nan::New("ZIP_SOURCE_SUPPORTS_SEEKABLE").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(1048672));
    key = Nan::New("ZIP_SOURCE_SUPPORTS_WRITABLE").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(1048673));
    key = Nan::New("ZIP_FILE_ATTRIBUTES_HOST_SYSTEM").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(1048674));
    key = Nan::New("ZIP_FILE_ATTRIBUTES_ASCII").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(1048675));
    key = Nan::New("ZIP_FILE_ATTRIBUTES_VERSION_NEEDED").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(1048676));
    key = Nan::New("ZIP_FILE_ATTRIBUTES_EXTERNAL_FILE_ATTRIBUTES").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(1048677));
    key = Nan::New("ZIP_FILE_ATTRIBUTES_GENERAL_PURPOSE_BIT_FLAGS").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(1048678));
    key = Nan::New("ZIP_ENCODING_UNKNOWN").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(1048679));
    key = Nan::New("ZIP_ENCODING_ASCII").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(1048680));
    key = Nan::New("ZIP_ENCODING_UTF8_KNOWN").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(1048681));
    key = Nan::New("ZIP_ENCODING_UTF8_GUESSED").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(1048682));
    key = Nan::New("ZIP_ENCODING_CP437").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(1048683));
    key = Nan::New("ZIP_ENCODING_ERROR").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(1048684));
    key = Nan::New("ZIP_SOURCE_WRITE_CLOSED").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(1048685));
    key = Nan::New("ZIP_SOURCE_WRITE_OPEN").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(1048686));
    key = Nan::New("ZIP_SOURCE_WRITE_FAILED").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(1048687));
    key = Nan::New("ZIP_SOURCE_WRITE_REMOVED").ToLocalChecked();
    if(Nan::HasOwnProperty(constants, key).FromJust()) {
        Nan::ThrowError(Nan::New("Failed to set constant value due to duplicate key: " + std::string(*Nan::Utf8String(key))).ToLocalChecked());
        return;
    }
    Nan::Set(constants, key, Nan::New<v8::Uint32>(1048688));
    Nan::Set(exports, Nan::New("constants").ToLocalChecked(), constants);
}
bool ConvertZipConstant(Nan::NAN_METHOD_ARGS_TYPE& info, const int&& index, zip_flags_t& out) {
    Arguments args("libzipflags",info);
    if(!args.AssertArgumentType("Uint32", index, Arguments::IsUint32)) {
        return false;
    }
    uint32_t val = Nan::To<v8::Uint32>(info[index]).ToLocalChecked()->Value();
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
    if(val & 64 || val & 128 || val & 256 || val & 512 || val & 1024 || val & 2048 || val & 4096 || val & 8192 || val & 16384 || val & 32768 || val & 65536 || val & 131072 || val & 262144 || val & 524288) {
        out = 0;
        if(val & 64) {
            out |= ZIP_FL_NOCASE;
            val &= ~64;
        }
        if(val & 128) {
            out |= ZIP_FL_RECOMPRESS;
            val &= ~128;
        }
        if(val & 256) {
            out |= ZIP_FL_NODIR;
            val &= ~256;
        }
        if(val & 512) {
            out |= ZIP_FL_COMPRESSED;
            val &= ~512;
        }
        if(val & 1024) {
            out |= ZIP_FL_UNCHANGED;
            val &= ~1024;
        }
        if(val & 2048) {
            out |= ZIP_FL_ENCRYPTED;
            val &= ~2048;
        }
        if(val & 4096) {
            out |= ZIP_FL_ENC_GUESS;
            val &= ~4096;
        }
        if(val & 8192) {
            out |= ZIP_FL_ENC_RAW;
            val &= ~8192;
        }
        if(val & 16384) {
            out |= ZIP_FL_ENC_STRICT;
            val &= ~16384;
        }
        if(val & 32768) {
            out |= ZIP_FL_LOCAL;
            val &= ~32768;
        }
        if(val & 65536) {
            out |= ZIP_FL_CENTRAL;
            val &= ~65536;
        }
        if(val & 131072) {
            out |= ZIP_FL_ENC_UTF_8;
            val &= ~131072;
        }
        if(val & 262144) {
            out |= ZIP_FL_ENC_CP437;
            val &= ~262144;
        }
        if(val & 524288) {
            out |= ZIP_FL_OVERWRITE;
            val &= ~524288;
        }
        if(val != 0) {
            Nan::ThrowError(Nan::New("Failed to convert constant value to libzip constant due to invalid remaining flags: " + std::to_string(val)).ToLocalChecked());
            return false;
        }
        return true;
    }
    if(val == 1048576) {
        out = ZIP_AFL_RDONLY;
        return true;
    }
    if(val == 1048577) {
        out = ZIP_AFL_IS_TORRENTZIP;
        return true;
    }
    if(val == 1048578) {
        out = ZIP_AFL_WANT_TORRENTZIP;
        return true;
    }
    if(val == 1048579) {
        out = ZIP_AFL_CREATE_OR_KEEP_FILE_FOR_EMPTY_ARCHIVE;
        return true;
    }
    if(val == 1048580) {
        out = ZIP_EXTRA_FIELD_ALL;
        return true;
    }
    if(val == 1048581) {
        out = ZIP_EXTRA_FIELD_NEW;
        return true;
    }
    if(val == 1048582) {
        out = ZIP_LENGTH_TO_END;
        return true;
    }
    if(val == 1048583) {
        out = ZIP_LENGTH_UNCHECKED;
        return true;
    }
    if(val == 1048584) {
        out = ZIP_ER_OK;
        return true;
    }
    if(val == 1048585) {
        out = ZIP_ER_MULTIDISK;
        return true;
    }
    if(val == 1048586) {
        out = ZIP_ER_RENAME;
        return true;
    }
    if(val == 1048587) {
        out = ZIP_ER_CLOSE;
        return true;
    }
    if(val == 1048588) {
        out = ZIP_ER_SEEK;
        return true;
    }
    if(val == 1048589) {
        out = ZIP_ER_READ;
        return true;
    }
    if(val == 1048590) {
        out = ZIP_ER_WRITE;
        return true;
    }
    if(val == 1048591) {
        out = ZIP_ER_CRC;
        return true;
    }
    if(val == 1048592) {
        out = ZIP_ER_ZIPCLOSED;
        return true;
    }
    if(val == 1048593) {
        out = ZIP_ER_NOENT;
        return true;
    }
    if(val == 1048594) {
        out = ZIP_ER_EXISTS;
        return true;
    }
    if(val == 1048595) {
        out = ZIP_ER_OPEN;
        return true;
    }
    if(val == 1048596) {
        out = ZIP_ER_TMPOPEN;
        return true;
    }
    if(val == 1048597) {
        out = ZIP_ER_ZLIB;
        return true;
    }
    if(val == 1048598) {
        out = ZIP_ER_MEMORY;
        return true;
    }
    if(val == 1048599) {
        out = ZIP_ER_CHANGED;
        return true;
    }
    if(val == 1048600) {
        out = ZIP_ER_COMPNOTSUPP;
        return true;
    }
    if(val == 1048601) {
        out = ZIP_ER_EOF;
        return true;
    }
    if(val == 1048602) {
        out = ZIP_ER_INVAL;
        return true;
    }
    if(val == 1048603) {
        out = ZIP_ER_NOZIP;
        return true;
    }
    if(val == 1048604) {
        out = ZIP_ER_INTERNAL;
        return true;
    }
    if(val == 1048605) {
        out = ZIP_ER_INCONS;
        return true;
    }
    if(val == 1048606) {
        out = ZIP_ER_REMOVE;
        return true;
    }
    if(val == 1048607) {
        out = ZIP_ER_DELETED;
        return true;
    }
    if(val == 1048608) {
        out = ZIP_ER_ENCRNOTSUPP;
        return true;
    }
    if(val == 1048609) {
        out = ZIP_ER_RDONLY;
        return true;
    }
    if(val == 1048610) {
        out = ZIP_ER_NOPASSWD;
        return true;
    }
    if(val == 1048611) {
        out = ZIP_ER_WRONGPASSWD;
        return true;
    }
    if(val == 1048612) {
        out = ZIP_ER_OPNOTSUPP;
        return true;
    }
    if(val == 1048613) {
        out = ZIP_ER_INUSE;
        return true;
    }
    if(val == 1048614) {
        out = ZIP_ER_TELL;
        return true;
    }
    if(val == 1048615) {
        out = ZIP_ER_COMPRESSED_DATA;
        return true;
    }
    if(val == 1048616) {
        out = ZIP_ER_CANCELLED;
        return true;
    }
    if(val == 1048617) {
        out = ZIP_ER_DATA_LENGTH;
        return true;
    }
    if(val == 1048618) {
        out = ZIP_ER_NOT_ALLOWED;
        return true;
    }
    if(val == 1048619) {
        out = ZIP_ET_NONE;
        return true;
    }
    if(val == 1048620) {
        out = ZIP_ET_SYS;
        return true;
    }
    if(val == 1048621) {
        out = ZIP_ET_ZLIB;
        return true;
    }
    if(val == 1048622) {
        out = ZIP_ET_LIBZIP;
        return true;
    }
    if(val == 1048623) {
        out = ZIP_CM_DEFAULT;
        return true;
    }
    if(val == 1048624) {
        out = ZIP_CM_STORE;
        return true;
    }
    if(val == 1048625) {
        out = ZIP_CM_SHRINK;
        return true;
    }
    if(val == 1048626) {
        out = ZIP_CM_REDUCE_1;
        return true;
    }
    if(val == 1048627) {
        out = ZIP_CM_REDUCE_2;
        return true;
    }
    if(val == 1048628) {
        out = ZIP_CM_REDUCE_3;
        return true;
    }
    if(val == 1048629) {
        out = ZIP_CM_REDUCE_4;
        return true;
    }
    if(val == 1048630) {
        out = ZIP_CM_IMPLODE;
        return true;
    }
    if(val == 1048631) {
        out = ZIP_CM_DEFLATE;
        return true;
    }
    if(val == 1048632) {
        out = ZIP_CM_DEFLATE64;
        return true;
    }
    if(val == 1048633) {
        out = ZIP_CM_PKWARE_IMPLODE;
        return true;
    }
    if(val == 1048634) {
        out = ZIP_CM_BZIP2;
        return true;
    }
    if(val == 1048635) {
        out = ZIP_CM_LZMA;
        return true;
    }
    if(val == 1048636) {
        out = ZIP_CM_TERSE;
        return true;
    }
    if(val == 1048637) {
        out = ZIP_CM_LZ77;
        return true;
    }
    if(val == 1048638) {
        out = ZIP_CM_LZMA2;
        return true;
    }
    if(val == 1048639) {
        out = ZIP_CM_ZSTD;
        return true;
    }
    if(val == 1048640) {
        out = ZIP_CM_XZ;
        return true;
    }
    if(val == 1048641) {
        out = ZIP_CM_JPEG;
        return true;
    }
    if(val == 1048642) {
        out = ZIP_CM_WAVPACK;
        return true;
    }
    if(val == 1048643) {
        out = ZIP_CM_PPMD;
        return true;
    }
    if(val == 1048644) {
        out = ZIP_EM_NONE;
        return true;
    }
    if(val == 1048645) {
        out = ZIP_EM_TRAD_PKWARE;
        return true;
    }
    if(val == 1048646) {
        out = ZIP_EM_AES_128;
        return true;
    }
    if(val == 1048647) {
        out = ZIP_EM_AES_192;
        return true;
    }
    if(val == 1048648) {
        out = ZIP_EM_AES_256;
        return true;
    }
    if(val == 1048649) {
        out = ZIP_EM_UNKNOWN;
        return true;
    }
    if(val == 1048650) {
        out = ZIP_OPSYS_DOS;
        return true;
    }
    if(val == 1048651) {
        out = ZIP_OPSYS_AMIGA;
        return true;
    }
    if(val == 1048652) {
        out = ZIP_OPSYS_OPENVMS;
        return true;
    }
    if(val == 1048653) {
        out = ZIP_OPSYS_UNIX;
        return true;
    }
    if(val == 1048654) {
        out = ZIP_OPSYS_VM_CMS;
        return true;
    }
    if(val == 1048655) {
        out = ZIP_OPSYS_ATARI_ST;
        return true;
    }
    if(val == 1048656) {
        out = ZIP_OPSYS_OS_2;
        return true;
    }
    if(val == 1048657) {
        out = ZIP_OPSYS_MACINTOSH;
        return true;
    }
    if(val == 1048658) {
        out = ZIP_OPSYS_Z_SYSTEM;
        return true;
    }
    if(val == 1048659) {
        out = ZIP_OPSYS_CPM;
        return true;
    }
    if(val == 1048660) {
        out = ZIP_OPSYS_WINDOWS_NTFS;
        return true;
    }
    if(val == 1048661) {
        out = ZIP_OPSYS_MVS;
        return true;
    }
    if(val == 1048662) {
        out = ZIP_OPSYS_VSE;
        return true;
    }
    if(val == 1048663) {
        out = ZIP_OPSYS_ACORN_RISC;
        return true;
    }
    if(val == 1048664) {
        out = ZIP_OPSYS_VFAT;
        return true;
    }
    if(val == 1048665) {
        out = ZIP_OPSYS_ALTERNATE_MVS;
        return true;
    }
    if(val == 1048666) {
        out = ZIP_OPSYS_BEOS;
        return true;
    }
    if(val == 1048667) {
        out = ZIP_OPSYS_TANDEM;
        return true;
    }
    if(val == 1048668) {
        out = ZIP_OPSYS_OS_400;
        return true;
    }
    if(val == 1048669) {
        out = ZIP_OPSYS_OS_X;
        return true;
    }
    if(val == 1048670) {
        out = ZIP_OPSYS_DEFAULT;
        return true;
    }
    if(val == 1048671) {
        out = ZIP_SOURCE_SUPPORTS_READABLE;
        return true;
    }
    if(val == 1048672) {
        out = ZIP_SOURCE_SUPPORTS_SEEKABLE;
        return true;
    }
    if(val == 1048673) {
        out = ZIP_SOURCE_SUPPORTS_WRITABLE;
        return true;
    }
    if(val == 1048674) {
        out = ZIP_FILE_ATTRIBUTES_HOST_SYSTEM;
        return true;
    }
    if(val == 1048675) {
        out = ZIP_FILE_ATTRIBUTES_ASCII;
        return true;
    }
    if(val == 1048676) {
        out = ZIP_FILE_ATTRIBUTES_VERSION_NEEDED;
        return true;
    }
    if(val == 1048677) {
        out = ZIP_FILE_ATTRIBUTES_EXTERNAL_FILE_ATTRIBUTES;
        return true;
    }
    if(val == 1048678) {
        out = ZIP_FILE_ATTRIBUTES_GENERAL_PURPOSE_BIT_FLAGS;
        return true;
    }
    if(val == 1048679) {
        out = ZIP_ENCODING_UNKNOWN;
        return true;
    }
    if(val == 1048680) {
        out = ZIP_ENCODING_ASCII;
        return true;
    }
    if(val == 1048681) {
        out = ZIP_ENCODING_UTF8_KNOWN;
        return true;
    }
    if(val == 1048682) {
        out = ZIP_ENCODING_UTF8_GUESSED;
        return true;
    }
    if(val == 1048683) {
        out = ZIP_ENCODING_CP437;
        return true;
    }
    if(val == 1048684) {
        out = ZIP_ENCODING_ERROR;
        return true;
    }
    if(val == 1048685) {
        out = ZIP_SOURCE_WRITE_CLOSED;
        return true;
    }
    if(val == 1048686) {
        out = ZIP_SOURCE_WRITE_OPEN;
        return true;
    }
    if(val == 1048687) {
        out = ZIP_SOURCE_WRITE_FAILED;
        return true;
    }
    if(val == 1048688) {
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
            v |= 64;
        }
        if(value & ZIP_FL_RECOMPRESS) {
            v |= 128;
        }
        if(value & ZIP_FL_NODIR) {
            v |= 256;
        }
        if(value & ZIP_FL_COMPRESSED) {
            v |= 512;
        }
        if(value & ZIP_FL_UNCHANGED) {
            v |= 1024;
        }
        if(value & ZIP_FL_ENCRYPTED) {
            v |= 2048;
        }
        if(value & ZIP_FL_ENC_GUESS) {
            v |= 4096;
        }
        if(value & ZIP_FL_ENC_RAW) {
            v |= 8192;
        }
        if(value & ZIP_FL_ENC_STRICT) {
            v |= 16384;
        }
        if(value & ZIP_FL_LOCAL) {
            v |= 32768;
        }
        if(value & ZIP_FL_CENTRAL) {
            v |= 65536;
        }
        if(value & ZIP_FL_ENC_UTF_8) {
            v |= 131072;
        }
        if(value & ZIP_FL_ENC_CP437) {
            v |= 262144;
        }
        if(value & ZIP_FL_OVERWRITE) {
            v |= 524288;
        }
        out = Nan::New<v8::Uint32>(v);
        return true;
    }
    if(value == ZIP_AFL_RDONLY) {
        out = Nan::New<v8::Uint32>(1048576);
        return true;
    }
    if(value == ZIP_AFL_IS_TORRENTZIP) {
        out = Nan::New<v8::Uint32>(1048577);
        return true;
    }
    if(value == ZIP_AFL_WANT_TORRENTZIP) {
        out = Nan::New<v8::Uint32>(1048578);
        return true;
    }
    if(value == ZIP_AFL_CREATE_OR_KEEP_FILE_FOR_EMPTY_ARCHIVE) {
        out = Nan::New<v8::Uint32>(1048579);
        return true;
    }
    if(value == ZIP_EXTRA_FIELD_ALL) {
        out = Nan::New<v8::Uint32>(1048580);
        return true;
    }
    if(value == ZIP_EXTRA_FIELD_NEW) {
        out = Nan::New<v8::Uint32>(1048581);
        return true;
    }
    if(value == ZIP_LENGTH_TO_END) {
        out = Nan::New<v8::Uint32>(1048582);
        return true;
    }
    if(value == ZIP_LENGTH_UNCHECKED) {
        out = Nan::New<v8::Uint32>(1048583);
        return true;
    }
    if(value == ZIP_ER_OK) {
        out = Nan::New<v8::Uint32>(1048584);
        return true;
    }
    if(value == ZIP_ER_MULTIDISK) {
        out = Nan::New<v8::Uint32>(1048585);
        return true;
    }
    if(value == ZIP_ER_RENAME) {
        out = Nan::New<v8::Uint32>(1048586);
        return true;
    }
    if(value == ZIP_ER_CLOSE) {
        out = Nan::New<v8::Uint32>(1048587);
        return true;
    }
    if(value == ZIP_ER_SEEK) {
        out = Nan::New<v8::Uint32>(1048588);
        return true;
    }
    if(value == ZIP_ER_READ) {
        out = Nan::New<v8::Uint32>(1048589);
        return true;
    }
    if(value == ZIP_ER_WRITE) {
        out = Nan::New<v8::Uint32>(1048590);
        return true;
    }
    if(value == ZIP_ER_CRC) {
        out = Nan::New<v8::Uint32>(1048591);
        return true;
    }
    if(value == ZIP_ER_ZIPCLOSED) {
        out = Nan::New<v8::Uint32>(1048592);
        return true;
    }
    if(value == ZIP_ER_NOENT) {
        out = Nan::New<v8::Uint32>(1048593);
        return true;
    }
    if(value == ZIP_ER_EXISTS) {
        out = Nan::New<v8::Uint32>(1048594);
        return true;
    }
    if(value == ZIP_ER_OPEN) {
        out = Nan::New<v8::Uint32>(1048595);
        return true;
    }
    if(value == ZIP_ER_TMPOPEN) {
        out = Nan::New<v8::Uint32>(1048596);
        return true;
    }
    if(value == ZIP_ER_ZLIB) {
        out = Nan::New<v8::Uint32>(1048597);
        return true;
    }
    if(value == ZIP_ER_MEMORY) {
        out = Nan::New<v8::Uint32>(1048598);
        return true;
    }
    if(value == ZIP_ER_CHANGED) {
        out = Nan::New<v8::Uint32>(1048599);
        return true;
    }
    if(value == ZIP_ER_COMPNOTSUPP) {
        out = Nan::New<v8::Uint32>(1048600);
        return true;
    }
    if(value == ZIP_ER_EOF) {
        out = Nan::New<v8::Uint32>(1048601);
        return true;
    }
    if(value == ZIP_ER_INVAL) {
        out = Nan::New<v8::Uint32>(1048602);
        return true;
    }
    if(value == ZIP_ER_NOZIP) {
        out = Nan::New<v8::Uint32>(1048603);
        return true;
    }
    if(value == ZIP_ER_INTERNAL) {
        out = Nan::New<v8::Uint32>(1048604);
        return true;
    }
    if(value == ZIP_ER_INCONS) {
        out = Nan::New<v8::Uint32>(1048605);
        return true;
    }
    if(value == ZIP_ER_REMOVE) {
        out = Nan::New<v8::Uint32>(1048606);
        return true;
    }
    if(value == ZIP_ER_DELETED) {
        out = Nan::New<v8::Uint32>(1048607);
        return true;
    }
    if(value == ZIP_ER_ENCRNOTSUPP) {
        out = Nan::New<v8::Uint32>(1048608);
        return true;
    }
    if(value == ZIP_ER_RDONLY) {
        out = Nan::New<v8::Uint32>(1048609);
        return true;
    }
    if(value == ZIP_ER_NOPASSWD) {
        out = Nan::New<v8::Uint32>(1048610);
        return true;
    }
    if(value == ZIP_ER_WRONGPASSWD) {
        out = Nan::New<v8::Uint32>(1048611);
        return true;
    }
    if(value == ZIP_ER_OPNOTSUPP) {
        out = Nan::New<v8::Uint32>(1048612);
        return true;
    }
    if(value == ZIP_ER_INUSE) {
        out = Nan::New<v8::Uint32>(1048613);
        return true;
    }
    if(value == ZIP_ER_TELL) {
        out = Nan::New<v8::Uint32>(1048614);
        return true;
    }
    if(value == ZIP_ER_COMPRESSED_DATA) {
        out = Nan::New<v8::Uint32>(1048615);
        return true;
    }
    if(value == ZIP_ER_CANCELLED) {
        out = Nan::New<v8::Uint32>(1048616);
        return true;
    }
    if(value == ZIP_ER_DATA_LENGTH) {
        out = Nan::New<v8::Uint32>(1048617);
        return true;
    }
    if(value == ZIP_ER_NOT_ALLOWED) {
        out = Nan::New<v8::Uint32>(1048618);
        return true;
    }
    if(value == ZIP_ET_NONE) {
        out = Nan::New<v8::Uint32>(1048619);
        return true;
    }
    if(value == ZIP_ET_SYS) {
        out = Nan::New<v8::Uint32>(1048620);
        return true;
    }
    if(value == ZIP_ET_ZLIB) {
        out = Nan::New<v8::Uint32>(1048621);
        return true;
    }
    if(value == ZIP_ET_LIBZIP) {
        out = Nan::New<v8::Uint32>(1048622);
        return true;
    }
    if(value == ZIP_CM_DEFAULT) {
        out = Nan::New<v8::Uint32>(1048623);
        return true;
    }
    if(value == ZIP_CM_STORE) {
        out = Nan::New<v8::Uint32>(1048624);
        return true;
    }
    if(value == ZIP_CM_SHRINK) {
        out = Nan::New<v8::Uint32>(1048625);
        return true;
    }
    if(value == ZIP_CM_REDUCE_1) {
        out = Nan::New<v8::Uint32>(1048626);
        return true;
    }
    if(value == ZIP_CM_REDUCE_2) {
        out = Nan::New<v8::Uint32>(1048627);
        return true;
    }
    if(value == ZIP_CM_REDUCE_3) {
        out = Nan::New<v8::Uint32>(1048628);
        return true;
    }
    if(value == ZIP_CM_REDUCE_4) {
        out = Nan::New<v8::Uint32>(1048629);
        return true;
    }
    if(value == ZIP_CM_IMPLODE) {
        out = Nan::New<v8::Uint32>(1048630);
        return true;
    }
    if(value == ZIP_CM_DEFLATE) {
        out = Nan::New<v8::Uint32>(1048631);
        return true;
    }
    if(value == ZIP_CM_DEFLATE64) {
        out = Nan::New<v8::Uint32>(1048632);
        return true;
    }
    if(value == ZIP_CM_PKWARE_IMPLODE) {
        out = Nan::New<v8::Uint32>(1048633);
        return true;
    }
    if(value == ZIP_CM_BZIP2) {
        out = Nan::New<v8::Uint32>(1048634);
        return true;
    }
    if(value == ZIP_CM_LZMA) {
        out = Nan::New<v8::Uint32>(1048635);
        return true;
    }
    if(value == ZIP_CM_TERSE) {
        out = Nan::New<v8::Uint32>(1048636);
        return true;
    }
    if(value == ZIP_CM_LZ77) {
        out = Nan::New<v8::Uint32>(1048637);
        return true;
    }
    if(value == ZIP_CM_LZMA2) {
        out = Nan::New<v8::Uint32>(1048638);
        return true;
    }
    if(value == ZIP_CM_ZSTD) {
        out = Nan::New<v8::Uint32>(1048639);
        return true;
    }
    if(value == ZIP_CM_XZ) {
        out = Nan::New<v8::Uint32>(1048640);
        return true;
    }
    if(value == ZIP_CM_JPEG) {
        out = Nan::New<v8::Uint32>(1048641);
        return true;
    }
    if(value == ZIP_CM_WAVPACK) {
        out = Nan::New<v8::Uint32>(1048642);
        return true;
    }
    if(value == ZIP_CM_PPMD) {
        out = Nan::New<v8::Uint32>(1048643);
        return true;
    }
    if(value == ZIP_EM_NONE) {
        out = Nan::New<v8::Uint32>(1048644);
        return true;
    }
    if(value == ZIP_EM_TRAD_PKWARE) {
        out = Nan::New<v8::Uint32>(1048645);
        return true;
    }
    if(value == ZIP_EM_AES_128) {
        out = Nan::New<v8::Uint32>(1048646);
        return true;
    }
    if(value == ZIP_EM_AES_192) {
        out = Nan::New<v8::Uint32>(1048647);
        return true;
    }
    if(value == ZIP_EM_AES_256) {
        out = Nan::New<v8::Uint32>(1048648);
        return true;
    }
    if(value == ZIP_EM_UNKNOWN) {
        out = Nan::New<v8::Uint32>(1048649);
        return true;
    }
    if(value == ZIP_OPSYS_DOS) {
        out = Nan::New<v8::Uint32>(1048650);
        return true;
    }
    if(value == ZIP_OPSYS_AMIGA) {
        out = Nan::New<v8::Uint32>(1048651);
        return true;
    }
    if(value == ZIP_OPSYS_OPENVMS) {
        out = Nan::New<v8::Uint32>(1048652);
        return true;
    }
    if(value == ZIP_OPSYS_UNIX) {
        out = Nan::New<v8::Uint32>(1048653);
        return true;
    }
    if(value == ZIP_OPSYS_VM_CMS) {
        out = Nan::New<v8::Uint32>(1048654);
        return true;
    }
    if(value == ZIP_OPSYS_ATARI_ST) {
        out = Nan::New<v8::Uint32>(1048655);
        return true;
    }
    if(value == ZIP_OPSYS_OS_2) {
        out = Nan::New<v8::Uint32>(1048656);
        return true;
    }
    if(value == ZIP_OPSYS_MACINTOSH) {
        out = Nan::New<v8::Uint32>(1048657);
        return true;
    }
    if(value == ZIP_OPSYS_Z_SYSTEM) {
        out = Nan::New<v8::Uint32>(1048658);
        return true;
    }
    if(value == ZIP_OPSYS_CPM) {
        out = Nan::New<v8::Uint32>(1048659);
        return true;
    }
    if(value == ZIP_OPSYS_WINDOWS_NTFS) {
        out = Nan::New<v8::Uint32>(1048660);
        return true;
    }
    if(value == ZIP_OPSYS_MVS) {
        out = Nan::New<v8::Uint32>(1048661);
        return true;
    }
    if(value == ZIP_OPSYS_VSE) {
        out = Nan::New<v8::Uint32>(1048662);
        return true;
    }
    if(value == ZIP_OPSYS_ACORN_RISC) {
        out = Nan::New<v8::Uint32>(1048663);
        return true;
    }
    if(value == ZIP_OPSYS_VFAT) {
        out = Nan::New<v8::Uint32>(1048664);
        return true;
    }
    if(value == ZIP_OPSYS_ALTERNATE_MVS) {
        out = Nan::New<v8::Uint32>(1048665);
        return true;
    }
    if(value == ZIP_OPSYS_BEOS) {
        out = Nan::New<v8::Uint32>(1048666);
        return true;
    }
    if(value == ZIP_OPSYS_TANDEM) {
        out = Nan::New<v8::Uint32>(1048667);
        return true;
    }
    if(value == ZIP_OPSYS_OS_400) {
        out = Nan::New<v8::Uint32>(1048668);
        return true;
    }
    if(value == ZIP_OPSYS_OS_X) {
        out = Nan::New<v8::Uint32>(1048669);
        return true;
    }
    if(value == ZIP_OPSYS_DEFAULT) {
        out = Nan::New<v8::Uint32>(1048670);
        return true;
    }
    if(value == ZIP_SOURCE_SUPPORTS_READABLE) {
        out = Nan::New<v8::Uint32>(1048671);
        return true;
    }
    if(value == ZIP_SOURCE_SUPPORTS_SEEKABLE) {
        out = Nan::New<v8::Uint32>(1048672);
        return true;
    }
    if(value == ZIP_SOURCE_SUPPORTS_WRITABLE) {
        out = Nan::New<v8::Uint32>(1048673);
        return true;
    }
    if(value == ZIP_FILE_ATTRIBUTES_HOST_SYSTEM) {
        out = Nan::New<v8::Uint32>(1048674);
        return true;
    }
    if(value == ZIP_FILE_ATTRIBUTES_ASCII) {
        out = Nan::New<v8::Uint32>(1048675);
        return true;
    }
    if(value == ZIP_FILE_ATTRIBUTES_VERSION_NEEDED) {
        out = Nan::New<v8::Uint32>(1048676);
        return true;
    }
    if(value == ZIP_FILE_ATTRIBUTES_EXTERNAL_FILE_ATTRIBUTES) {
        out = Nan::New<v8::Uint32>(1048677);
        return true;
    }
    if(value == ZIP_FILE_ATTRIBUTES_GENERAL_PURPOSE_BIT_FLAGS) {
        out = Nan::New<v8::Uint32>(1048678);
        return true;
    }
    if(value == ZIP_ENCODING_UNKNOWN) {
        out = Nan::New<v8::Uint32>(1048679);
        return true;
    }
    if(value == ZIP_ENCODING_ASCII) {
        out = Nan::New<v8::Uint32>(1048680);
        return true;
    }
    if(value == ZIP_ENCODING_UTF8_KNOWN) {
        out = Nan::New<v8::Uint32>(1048681);
        return true;
    }
    if(value == ZIP_ENCODING_UTF8_GUESSED) {
        out = Nan::New<v8::Uint32>(1048682);
        return true;
    }
    if(value == ZIP_ENCODING_CP437) {
        out = Nan::New<v8::Uint32>(1048683);
        return true;
    }
    if(value == ZIP_ENCODING_ERROR) {
        out = Nan::New<v8::Uint32>(1048684);
        return true;
    }
    if(value == ZIP_SOURCE_WRITE_CLOSED) {
        out = Nan::New<v8::Uint32>(1048685);
        return true;
    }
    if(value == ZIP_SOURCE_WRITE_OPEN) {
        out = Nan::New<v8::Uint32>(1048686);
        return true;
    }
    if(value == ZIP_SOURCE_WRITE_FAILED) {
        out = Nan::New<v8::Uint32>(1048687);
        return true;
    }
    if(value == ZIP_SOURCE_WRITE_REMOVED) {
        out = Nan::New<v8::Uint32>(1048688);
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
    uint32_t val = Nan::To<v8::Uint32>(info[index]).ToLocalChecked()->Value();
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
