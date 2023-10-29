#include "Source.h"

Nan::Persistent<v8::Function> Source::constructor;

void Source::Init(v8::Local<v8::Object> exports) {
    auto tpl = Nan::New<v8::FunctionTemplate>(New);
    tpl->SetClassName(Nan::New("Source").ToLocalChecked());
    tpl->InstanceTemplate()->SetInternalFieldCount(1);

    constructor.Reset(Nan::GetFunction(tpl).ToLocalChecked());

    Nan::Set(exports, Nan::New("Source").ToLocalChecked(), Nan::GetFunction(tpl).ToLocalChecked());
}

NAN_METHOD(Source::New) {
    if(!info.IsConstructCall()) {
        return Nan::ThrowTypeError("Class Constructor Source cannot be invoked without 'new'");
    }
    auto source = new Source();
    source->Wrap(info.This());
    info.GetReturnValue().Set(info.This());
}

Source::~Source() {
    if(value != nullptr) {
        zip_source_free(value);
        value = nullptr;
    }
}
