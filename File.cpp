#include "File.h"
#include "Arguments.h"
#include "Constants.h"

Nan::Persistent<v8::Function> File::constructor;

void File::Init(v8::Local<v8::Object> target) {
    auto tpl = Nan::New<v8::FunctionTemplate>(New);
    tpl->SetClassName(Nan::New("File").ToLocalChecked());
    tpl->InstanceTemplate()->SetInternalFieldCount(1);

    Nan::SetPrototypeMethod(tpl,"close", Close);
    Nan::SetPrototypeMethod(tpl,"isSeekable", IsSeekable);
    Nan::SetPrototypeMethod(tpl,"seek", Seek);
    Nan::SetPrototypeMethod(tpl,"tell", Tell);
    Nan::SetPrototypeMethod(tpl,"read", Read);

    constructor.Reset(Nan::GetFunction(tpl).ToLocalChecked());

    Nan::Set(target, Nan::New("File").ToLocalChecked(), Nan::GetFunction(tpl).ToLocalChecked());
}

NAN_METHOD(File::New) {
    auto file = new File();
    file->Wrap(info.This());
    info.GetReturnValue().Set(info.This());
}

NAN_METHOD(File::IsSeekable) {
    Arguments args("isSeekable", info);
    File* file;
    if(!args.Unwrap(file)) {
        return;
    }
    if(!file->Assert("isSeekable")) {
        return;
    }
    auto result = zip_file_is_seekable(file->value);
    if(result < 0 || (result != 0 && result != 1)) {
        Nan::ThrowError("Failed to check if file is seekable");
        return;
    }
    info.GetReturnValue().Set(result == 0 ? Nan::False() : Nan::True());
}

NAN_METHOD(File::Seek) {
    Arguments args("seek", info);
    File* file;
    if(!args.Unwrap(file)) {
        return;
    }
    if(!file->Assert("seek")) {
        return;
    }
    zip_int64_t offset;
    int whence;
    if(!args.Convert(0, offset) || !ConvertNativeConstant(info, 1, whence)) {
        return;
    }
    auto result = zip_fseek(file->value, offset, whence);
    if(result == 0) {
        return;
    }
    file->Fail("seek");
}

NAN_METHOD(File::Tell) {
    Arguments args("tell", info);
    File* file;
    if(!args.Unwrap(file)) {
        return;
    }
    if(!file->Assert("tell")) {
        return;
    }
    auto result = zip_ftell(file->value);
    if(result == -1) {
        Nan::ThrowError("Failed to tell");
        return;
    }
    info.GetReturnValue().Set(Nan::New(std::to_string(result)).ToLocalChecked());
}

NAN_METHOD(File::Close) {
    Arguments args("close", info);
    File* file;
    if(!args.Unwrap(file)) {
        return;
    }
    if(!file->value) {
        Nan::ThrowError(Nan::New("File is already closed.").ToLocalChecked());
        return;
    }
    auto result = zip_fclose(file->value);
    if(result == 0) {
        file->value = nullptr;
        return;
    }
    zip_error_t err;
    zip_error_init_with_code(&err, result);
    Nan::ThrowError(
        Nan::New(
            "Failed to close file with error " + std::to_string(result) + ": " + zip_error_strerror(&err)
        ).ToLocalChecked()
    );
    zip_error_fini(&err);
}

NAN_METHOD(File::Read) {
    Arguments args("read", info);
    File* file;
    if(!args.Unwrap(file)) {
        return;
    }
    if(!file->Assert("read")) {
        return;
    }
    auto contents = Nan::TypedArrayContents<uint8_t>(info[0]);
    zip_uint64_t bytesToRead;
    if(!args.Convert(1, bytesToRead)) {
        return;
    }
    zip_int64_t readBytes = zip_fread(file->value, contents.operator*(), bytesToRead);
    if(readBytes == -1){
        file->Fail("read");
        return;
    }
    info.GetReturnValue().Set(Nan::New(std::to_string(readBytes)).ToLocalChecked());
}

bool File::Assert(std::string&& prefix) const {
    if(!value) {
        Nan::ThrowError(Nan::New("Failed to " + prefix + ": File is not open.").ToLocalChecked());
        return false;
    }
    return true;
}

void File::Fail(std::string&& prefix) const {
    Nan::ThrowError(Nan::New("Failed to " + prefix + ": " + std::string(zip_file_strerror(value))).ToLocalChecked());
}

File::~File() {
    if(value) {
        zip_fclose(value);
        value = nullptr;
    }
}
