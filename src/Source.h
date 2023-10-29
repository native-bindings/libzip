#ifndef NODELIBZIP_SOURCE_H
#define NODELIBZIP_SOURCE_H

#include <nan.h>
#include <zip.h>
#include <vector>

class Source : public Nan::ObjectWrap {
public:
    std::vector<uint8_t> data;
    zip_source_t* value = nullptr;
    static Nan::Persistent<v8::Function> constructor;
    static void Init(v8::Local<v8::Object>);
    ~Source();
private:
    static NAN_METHOD(New);
};


#endif //NODELIBZIP_SOURCE_H
