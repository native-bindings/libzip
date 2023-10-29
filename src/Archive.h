#ifndef NODELIBZIP_ARCHIVE_H
#define NODELIBZIP_ARCHIVE_H

#include <nan.h>
#include <zip.h>

class Archive : public Nan::ObjectWrap {
public:
    static Nan::Persistent<v8::Function> constructor;
    static void Init(v8::Local<v8::Object>);
    ~Archive();
private:
    zip_t* value = nullptr;
    static NAN_METHOD(New);
    static NAN_METHOD(AddDirectory);
    static NAN_METHOD(GetNumEntries);
    static NAN_METHOD(Open);
    static NAN_METHOD(OpenFile);
    static NAN_METHOD(StatIndex);
    static NAN_METHOD(Stat);
    static NAN_METHOD(Discard);
    static NAN_METHOD(Delete);
    static NAN_METHOD(RenameFile);
    static NAN_METHOD(NameLocate);
    static NAN_METHOD(GetName);
    static NAN_METHOD(Close);
    void discard();
    [[nodiscard]] bool ValidateError(const std::string&, int error);
    [[nodiscard]] bool HasError(const std::string&);
    void ThrowError(const std::string&);
};


#endif //NODELIBZIP_ARCHIVE_H
