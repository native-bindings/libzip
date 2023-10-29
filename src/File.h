#ifndef NODELIBZIP_FILE_H
#define NODELIBZIP_FILE_H

#include <zip.h>
#include <nan.h>

class File : public Nan::ObjectWrap {
public:
    zip_file_t* value = nullptr;
    static Nan::Persistent<v8::Function> constructor;
    static void Init(v8::Local<v8::Object>);
    ~File();
private:
    static NAN_METHOD(New);
    static NAN_METHOD(Close);
    static NAN_METHOD(IsSeekable);
    static NAN_METHOD(Seek);
    static NAN_METHOD(Tell);
    static NAN_METHOD(Read);
    bool Assert(std::string&& prefix) const;
    void Fail(std::string&& prefix) const;
};

#endif //NODELIBZIP_FILE_H
