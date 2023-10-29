#ifndef NODELIBZIP_ARGUMENTS_H
#define NODELIBZIP_ARGUMENTS_H

#include <nan.h>

class Arguments {
public:
    using ArgumentsType = Nan::NAN_METHOD_ARGS_TYPE;
    [[nodiscard]] Arguments(std::string&& methodName, ArgumentsType& info);
    [[nodiscard]] bool Convert(
        int index,
        std::string&
    ) const;
    [[nodiscard]] bool Convert(
        int index,
        uint64_t&
    ) const;
    [[nodiscard]] bool Convert(
        int index,
        int64_t&
    ) const;
    [[nodiscard]] bool Convert(
        int index,
        int32_t&
    ) const;
    template<typename T> [[nodiscard]] bool Unwrap(
            int index,
            T*& out
    ) const {
        if(!AssertArgumentIndex(index)) {
            return false;
        }
        return Unwrap(info[index], out);
    }
    template<typename T> [[nodiscard]] bool Unwrap(T*& out) const {
        return Unwrap(info.This(), out);
    }
    template<typename T> [[nodiscard]] bool Unwrap(v8::Local<v8::Value> value, T*& out) const {
        if(!value->IsObject()){
            ThrowError("Expected instance to be of type " + std::string(typeid(T).name()) + ".");
            return false;
        }
        out = nullptr;
        out = Nan::ObjectWrap::Unwrap<T>(Nan::To<v8::Object>(value).ToLocalChecked());
        if(out == nullptr) {
            ThrowError("Expected instance to be of type " + std::string(typeid(T).name()) + ".");
            return false;
        }
        return true;
    }
    [[nodiscard]] static bool IsUint32(const v8::Local<v8::Value>&);
    [[nodiscard]] static bool IsInt32(const v8::Local<v8::Value>&);
    [[nodiscard]] bool AssertArgumentType(std::string&& expectedType, int index, const std::function<bool(const v8::Local<v8::Value>&)>& assert) const;
private:
    std::string methodName;
    ArgumentsType& info;
    [[nodiscard]] bool AssertArgumentIndex(int index) const;
    [[nodiscard]] static bool IsString(const v8::Local<v8::Value>&);
    [[nodiscard]] static bool IsNumber(const v8::Local<v8::Value>&);
    static void ThrowError(std::string&&);
};

#endif //NODELIBZIP_ARGUMENTS_H
