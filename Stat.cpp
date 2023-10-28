#include "Stat.h"
#include "Arguments.h"
#include "Constants.h"

//struct zip_stat {
//    zip_uint64_t valid;             /* which fields have valid values */
//    const char *_Nullable name;     /* name of the file */
//    zip_uint64_t index;             /* index within archive */
//    zip_uint64_t size;              /* size of file (uncompressed) */
//    zip_uint64_t comp_size;         /* size of file (compressed) */
//    time_t mtime;                   /* modification time */
//    zip_uint32_t crc;               /* crc of file data */
//    zip_uint16_t comp_method;       /* compression method used */
//    zip_uint16_t encryption_method; /* encryption method used */
//    zip_uint32_t flags;             /* reserved for future use */
//};

using namespace bindings::libzip;

Nan::Persistent<v8::Function> Stat::constructor;

void Stat::Init(v8::Local<v8::Object> target) {
    auto tpl = Nan::New<v8::FunctionTemplate>(New);
    tpl->SetClassName(Nan::New("Stat").ToLocalChecked());
    tpl->InstanceTemplate()->SetInternalFieldCount(1);

    Nan::SetPrototypeMethod(tpl, "valid", Valid);
    Nan::SetPrototypeMethod(tpl, "encryptionMethod", EncryptionMethod);
    Nan::SetPrototypeMethod(tpl, "crc", CyclicalRedundancyCheck);
    Nan::SetPrototypeMethod(tpl, "modificationTime", ModificationTime);
    Nan::SetPrototypeMethod(tpl, "compressedSize", CompressedSize);
    Nan::SetPrototypeMethod(tpl, "size", Size);
    Nan::SetPrototypeMethod(tpl, "index", Index);
    Nan::SetPrototypeMethod(tpl, "name", Name);

    constructor.Reset(Nan::GetFunction(tpl).ToLocalChecked());

    Nan::Set(target, Nan::New("Stat").ToLocalChecked(), Nan::GetFunction(tpl).ToLocalChecked());
}

NAN_METHOD(Stat::New) {
    auto stat = new Stat();
    stat->Wrap(info.This());
    info.GetReturnValue().Set(info.This());
}

NAN_METHOD(Stat::EncryptionMethod) {
    Arguments args("encryptionMethod", info);
    Stat* stat;
    if(!args.Unwrap(stat)) {
        return;
    }
    info.GetReturnValue().Set(Nan::New<v8::Uint32>(stat->value.encryption_method));
}

NAN_METHOD(Stat::Valid) {
    Arguments args("valid", info);
    Stat* stat;
    if(!args.Unwrap(stat)) {
        return;
    }
    v8::Local<v8::Uint32> valid;
    if(!GetBindingZipStatFlag(stat->value.valid, valid)) {
        return;
    }
    info.GetReturnValue().Set(valid);
}

NAN_METHOD(Stat::CyclicalRedundancyCheck) {
    Arguments args("crc", info);
    Stat* stat;
    if(!args.Unwrap(stat)) {
        return;
    }
    info.GetReturnValue().Set(Nan::New<v8::Uint32>(stat->value.crc));
}

NAN_METHOD(Stat::ModificationTime) {
    Arguments args("modificationTime", info);
    Stat* stat;
    if(!args.Unwrap(stat)) {
        return;
    }
    info.GetReturnValue().Set(Nan::New(std::to_string(stat->value.mtime)).ToLocalChecked());
}

NAN_METHOD(Stat::CompressedSize) {
    Arguments args("compressedSize", info);
    Stat* stat;
    if(!args.Unwrap(stat)) {
        return;
    }
    info.GetReturnValue().Set(Nan::New(std::to_string(stat->value.comp_size)).ToLocalChecked());
}

NAN_METHOD(Stat::Size) {
    Arguments args("size", info);
    Stat* stat;
    if(!args.Unwrap(stat)) {
        return;
    }
    info.GetReturnValue().Set(Nan::New(std::to_string(stat->value.size)).ToLocalChecked());
}

NAN_METHOD(Stat::Index) {
    Arguments args("index", info);
    Stat* stat;
    if(!args.Unwrap(stat)) {
        return;
    }
    info.GetReturnValue().Set(Nan::New(std::to_string(stat->value.index)).ToLocalChecked());
}

NAN_METHOD(Stat::Name) {
    Arguments args("name", info);
    Stat* stat;
    if(!args.Unwrap(stat)) {
        return;
    }
    info.GetReturnValue().Set(Nan::New(stat->value.name).ToLocalChecked());
}
