#ifndef NODELIBZIP_STAT_H
#define NODELIBZIP_STAT_H

#include <nan.h>
#include <zip.h>

namespace bindings::libzip {

class Stat : public Nan::ObjectWrap {
public:
    zip_stat_t value;
    static Nan::Persistent<v8::Function> constructor;
    static void Init(v8::Local<v8::Object>);
private:
    static NAN_METHOD(New);
    static NAN_METHOD(EncryptionMethod);
    static NAN_METHOD(CyclicalRedundancyCheck);
    static NAN_METHOD(ModificationTime);
    static NAN_METHOD(CompressedSize);
    static NAN_METHOD(Size);
    static NAN_METHOD(Index);
    static NAN_METHOD(Valid);
    static NAN_METHOD(Name);
};

}

#endif //NODELIBZIP_STAT_H
