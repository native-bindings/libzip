#include "Archive.h"
#include "Arguments.h"
#include "Constants.h"
#include "File.h"
#include "Stat.h"
#include "Source.h"

Nan::Persistent<v8::Function> Archive::constructor;

void Archive::Init(v8::Local<v8::Object> target) {
    auto tpl = Nan::New<v8::FunctionTemplate>(New);
    tpl->SetClassName(Nan::New("Archive").ToLocalChecked());
    tpl->InstanceTemplate()->SetInternalFieldCount(1);

    Nan::SetPrototypeMethod(tpl, "open", Open);
    Nan::SetPrototypeMethod(tpl, "openFile", OpenFile);
    Nan::SetPrototypeMethod(tpl, "openFileByIndex", OpenFileByIndex);
    Nan::SetPrototypeMethod(tpl, "getName", GetName);
    Nan::SetPrototypeMethod(tpl, "getNumEntries", GetNumEntries);
    Nan::SetPrototypeMethod(tpl, "discard", Discard);
    Nan::SetPrototypeMethod(tpl, "addDirectory", AddDirectory);
    Nan::SetPrototypeMethod(tpl, "sourceBuffer", SourceBuffer);
    Nan::SetPrototypeMethod(tpl, "sourceFile", SourceFile);
    Nan::SetPrototypeMethod(tpl, "addFile", AddFile);
    Nan::SetPrototypeMethod(tpl, "stat", Stat);
    Nan::SetPrototypeMethod(tpl, "statIndex", StatIndex);
    Nan::SetPrototypeMethod(tpl, "delete", Delete);
    Nan::SetPrototypeMethod(tpl, "close", Close);
    Nan::SetPrototypeMethod(tpl, "nameLocate", NameLocate);

    constructor.Reset(Nan::GetFunction(tpl).ToLocalChecked());

    Nan::Set(target, Nan::New("Archive").ToLocalChecked(), Nan::GetFunction(tpl).ToLocalChecked());
}

NAN_METHOD(Archive::RenameFile) {
    Arguments args("renameFile", info);
    Archive* archive;
    zip_uint64_t index;
    std::string newName;
    zip_flags_t flags;
    if(
        !args.Unwrap(archive) || !args.Convert(0, index) ||
        !args.Convert(1, newName) ||
        !ConvertZipConstant(info, 2, flags)
    ) {
        return;
    }
    if(zip_file_rename(archive->value, index, newName.c_str(), flags) == 0) {
        return;
    }
    archive->ThrowError("rename file");
}

NAN_METHOD(Archive::Delete) {
    Arguments args("delete", info);
    Archive* archive;
    zip_uint64_t index;
    if(!args.Unwrap(archive)) {
        return;
    }
    if(!args.Convert(0, index)) {
        return;
    }
    if(zip_delete(archive->value, index) == 0) {
        return;
    }
    archive->ThrowError("delete file");
}

NAN_METHOD(Archive::New){
    auto archive = new Archive();
    archive->Wrap(info.This());
    info.GetReturnValue().Set(info.This());
}

NAN_METHOD(Archive::GetName) {
    Arguments args("getName", info);
    Archive* archive;
    zip_uint64_t index;
    zip_flags_t flags;
    if(!args.Unwrap(archive)) {
        return;
    }
    if(!args.Convert(0, index)) {
        return;
    }
    if(!ConvertZipConstant(info, 1, flags)) {
        return;
    }
    auto fileName = zip_get_name(archive->value, index, flags);
    if(archive->HasError("get file name")) {
        return;
    }
    info.GetReturnValue().Set(Nan::New(fileName).ToLocalChecked());
}

NAN_METHOD(Archive::OpenFile) {
    Arguments args("openFile", info);
    Archive* archive;
    std::string fname;
    zip_flags_t flags;
    if(!args.Unwrap(archive)) {
        return;
    }
    if(!args.Convert(0, fname) || !ConvertZipConstant(info, 1, flags)) {
        return;
    }
    zip_file_t* file = zip_fopen(archive->value, fname.c_str(), flags);
    auto result = Nan::NewInstance(Nan::New(File::constructor), 0, nullptr).ToLocalChecked();
    File* instance;
    if(!args.Unwrap(result, instance)) {
        return;
    }
    instance->value = file;
    info.GetReturnValue().Set(result);
}

NAN_METHOD(Archive::OpenFileByIndex) {
    Arguments args("openFileByIndex", info);
    Archive* archive;
    zip_uint64_t index;
    zip_flags_t flags;
    if(!args.Unwrap(archive)) {
        return;
    }
    if(!args.Convert(0, index) || !ConvertZipConstant(info, 1, flags)) {
        return;
    }
    zip_file_t* file = zip_fopen_index(archive->value, index, flags);
    auto result = Nan::NewInstance(Nan::New(File::constructor), 0, nullptr).ToLocalChecked();
    File* instance;
    if(!args.Unwrap(result, instance)) {
        return;
    }
    instance->value = file;
    info.GetReturnValue().Set(result);
}

NAN_METHOD(Archive::NameLocate) {
    Arguments args("nameLocate", info);
    Archive* archive;
    std::string path;
    zip_flags_t flags;
    if(!args.Unwrap(archive)) {
        return;
    }
    if(!args.Convert(0, path)) {
        return;
    }
    if(!ConvertZipConstant(info, 1, flags)) {
        return;
    }
    zip_int64_t index = zip_name_locate(archive->value, path.c_str(), flags);
    info.GetReturnValue().Set(Nan::New(std::to_string(index)).ToLocalChecked());
}

NAN_METHOD(Archive::Close) {
    Arguments args("close", info);
    Archive* archive;
    if(!args.Unwrap(archive)) {
        return;
    }
    if(archive->value == nullptr) {
        Nan::ThrowError(Nan::New("Archive is not open").ToLocalChecked());
        return;
    }
    if(zip_close(archive->value) == 0) {
        archive->value = nullptr;
        return;
    }
    archive->ThrowError("close the archive");
}

NAN_METHOD(Archive::AddFile) {
    Arguments args("addFile", info);
    Archive* archive;
    std::string fname;
    zip_flags_t flags;
    Source* src;
    if(!args.Unwrap(archive)) {
        return;
    }
    if(!args.Convert(0, fname) || !args.Unwrap(1, src) || !ConvertZipConstant(info, 2, flags)) {
        return;
    }
    zip_int64_t index = zip_file_add(archive->value, fname.c_str(), src->value, flags);
    if(index < 0) {
        archive->ThrowError("add file");
        return;
    }
    info.GetReturnValue().Set(Nan::New(std::to_string(index)).ToLocalChecked());
}

NAN_METHOD(Archive::AddDirectory) {
    Arguments args("dirAdd", info);
    Archive* archive;
    if(!args.Unwrap(archive)) {
        return;
    }
    std::string name;
    zip_flags_t flags;
    if(!args.Convert(0, name) || !ConvertZipConstant(info, 1, flags)) {
        return;
    }
    zip_int64_t index = zip_dir_add(archive->value, name.c_str(), flags);
    if(archive->HasError("add directory")) {
        return;
    }
    info.GetReturnValue().Set(Nan::New(std::to_string(index)).ToLocalChecked());
}

NAN_METHOD(Archive::GetNumEntries) {
    Arguments args("getNumEntries", info);
    Archive* archive;
    zip_flags_t flags;
    if(!args.Unwrap(archive)) {
        return;
    }
    if(!ConvertZipConstant(info, 0, flags)) {
        return;
    }
    zip_int64_t index = zip_get_num_entries(archive->value, flags);
    if(archive->HasError("get number of entries")) {
        return;
    }
    info.GetReturnValue().Set(Nan::New(std::to_string(index)).ToLocalChecked());
}

NAN_METHOD(Archive::StatIndex) {
    Arguments args("stat", info);
    bindings::libzip::Stat* stat;
    Archive* archive;
    zip_uint64_t index;
    zip_flags_t flags;
    if(!args.Unwrap(archive)) {
        return;
    }
    if(!args.Convert(0, index)) {
        return;
    }
    if(
        !ConvertZipConstant(info, 1, flags) ||
        !args.Unwrap(2, stat)
    ) {
        return;
    }
    if(zip_stat_index(archive->value, index, flags, &stat->value) == 0) {
        return;
    }
    archive->ThrowError("stat file by index");
}


NAN_METHOD(Archive::Stat) {
    Arguments args("stat", info);
    bindings::libzip::Stat* stat;
    Archive* archive;
    std::string fname;
    zip_flags_t flags;
    if(!args.Unwrap(archive)) {
        return;
    }
    if(!args.Convert(0, fname) || !ConvertZipStatFlag(info, 1, flags)) {
        return;
    }
    if(!args.Unwrap(2, stat)) {
        return;
    }
    if(zip_stat(archive->value, fname.c_str(), flags, &stat->value) == 0) {
        return;
    }
    archive->ThrowError("stat file by name");
}

NAN_METHOD(Archive::SourceBuffer) {
    Arguments args("sourceBuffer", info);
    Archive* archive;
    if(!args.Unwrap(archive)) {
        return;
    }
    auto result = Nan::NewInstance(Nan::New(Source::constructor), 0, nullptr).ToLocalChecked();
    Source* instance;
    if(!args.Unwrap(result, instance)) {
        return;
    }
    /**
     * transfer data from typed array to vector
     */
    Nan::TypedArrayContents<uint8_t> contents(info[0]);
    auto& data = instance->data;
    data.resize(contents.length());
    std::memcpy(data.data(), contents.operator*(), contents.length());
    /**
     * create source from in-memory data
     */
    zip_source_t* src = zip_source_buffer(archive->value, data.data(), data.size(), 0);
    if(src == nullptr){
        archive->ThrowError("create source buffer");
        return;
    }
    instance->value = src;
    info.GetReturnValue().Set(result);
}

NAN_METHOD(Archive::SourceFile) {
    Arguments args("sourceFile", info);
    Archive* archive;
    if(!args.Unwrap(archive)) {
        return;
    }
    auto result = Nan::NewInstance(Nan::New(Source::constructor), 0, nullptr).ToLocalChecked();
    Source* instance;
    if(!args.Unwrap(result, instance)) {
        return;
    }
    std::string fname;
    zip_uint64_t start;
    zip_int64_t len;
    if(!args.Convert(0, fname) || !args.Convert(1, start) || !args.Convert(2, len)) {
        return;
    }
    zip_source_t* src = zip_source_file(archive->value, fname.c_str(), start, len);
    if(src == nullptr){
        archive->ThrowError("create source buffer");
        return;
    }
    instance->value = src;
    info.GetReturnValue().Set(result);
}

NAN_METHOD(Archive::Discard) {
    Arguments args("discard", info);
    Archive* archive;
    if(!args.Unwrap(archive)) {
        return;
    }
    archive->discard();
}

NAN_METHOD(Archive::Open){
    Arguments args("open", info);
    Archive* archive;
    std::string path;
    if(!args.Unwrap(archive) || !args.Convert(0, path)) {
        return;
    }
    int flags;
    if(!ConvertZipOpenModeFlag(info, 1, flags)){
        return;
    }
    if(archive->value) {
        Nan::ThrowError(Nan::New("Archive is already open").ToLocalChecked());
        return;
    }
    int error = ZIP_ER_OK;
    archive->value = zip_open(path.c_str(), flags, &error);
    if(archive->ValidateError("open zip archive " + path, error)) {
        return;
    }
}

Archive::~Archive() {
    discard();
}

bool Archive::ValidateError(const std::string& prefix, int code) {
    if(code != ZIP_ER_OK) {
        if(value) {
            Nan::ThrowError(Nan::New("Failed to " + prefix + " with error code " + std::to_string(code) + ": " + zip_strerror(value)).ToLocalChecked());
        } else {
            Nan::ThrowError(Nan::New("Failed to " + prefix).ToLocalChecked());
        }
        return true;
    }
    return false;
}

bool Archive::HasError(const std::string& prefix) {
    const auto error = zip_get_error(value);
    return ValidateError(prefix, zip_error_code_zip(error));
}

void Archive::discard() {
    if(value != nullptr) {
        zip_discard(value);
        value = nullptr;
    }
}

void Archive::ThrowError(const std::string& prefix) {
    if(!HasError(prefix)) {
        Nan::ThrowError(Nan::New("Internal binding error when we tried to " + prefix + ": Expected an error, but no error was found on archive").ToLocalChecked());
    }
}
