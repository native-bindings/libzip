#ifndef NODELIBZIP_H_
#define NODELIBZIP_H_

#include <nan.h>
#include <zip.h>

bool ConvertNativeConstant(Nan::NAN_METHOD_ARGS_TYPE& info, const int&& index, int& out);
bool GetBindingNativeConstant(const int& value, v8::Local<v8::Uint32>& out);
void SetNativeConstants(v8::Local<v8::Object>);
bool ConvertZipEncryptionMethodFlag(Nan::NAN_METHOD_ARGS_TYPE& info, const int&& index, zip_uint16_t& out);
bool GetBindingZipEncryptionMethodFlag(const zip_uint16_t& value, v8::Local<v8::Uint32>& out);
void SetZipEncryptionMethodFlags(v8::Local<v8::Object>);
bool ConvertZipCompressionMethodFlag(Nan::NAN_METHOD_ARGS_TYPE& info, const int&& index, zip_int32_t& out);
bool GetBindingZipCompressionMethodFlag(const zip_int32_t& value, v8::Local<v8::Uint32>& out);
void SetZipCompressionMethodFlags(v8::Local<v8::Object>);
bool ConvertZipConstant(Nan::NAN_METHOD_ARGS_TYPE& info, const int&& index, zip_flags_t& out);
bool GetBindingZipConstant(const zip_flags_t& value, v8::Local<v8::Uint32>& out);
void SetZipConstants(v8::Local<v8::Object>);
bool ConvertZipOpenModeFlag(Nan::NAN_METHOD_ARGS_TYPE& info, const int&& index, int& out);
bool GetBindingZipOpenModeFlag(const int& value, v8::Local<v8::Uint32>& out);
void SetZipOpenModeFlags(v8::Local<v8::Object>);
bool ConvertZipLengthConstant(Nan::NAN_METHOD_ARGS_TYPE& info, const int&& index, zip_int32_t& out);
bool GetBindingZipLengthConstant(const zip_int32_t& value, v8::Local<v8::Uint32>& out);
void SetZipLengthConstants(v8::Local<v8::Object>);
bool ConvertZipStatFlag(Nan::NAN_METHOD_ARGS_TYPE& info, const int&& index, zip_flags_t& out);
bool GetBindingZipStatFlag(const zip_flags_t& value, v8::Local<v8::Uint32>& out);
void SetZipStatFlags(v8::Local<v8::Object>);

#endif // NODELIBZIP_H_
