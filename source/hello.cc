#include <napi.h>
#include <string>

// 定义一个返回类型为 Napi String 的 greetHello 函数, 注意此处的 info
Napi::Value hello(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  if(info.Length() < 1 || !info[0].IsString()) {
    Napi::TypeError::New(env, "wrong args").ThrowAsJavaScriptException();
    return env.Null();
  }
  
  std::string result = std::string("Hello ") + info[0].As<Napi::String>().Utf8Value();
  return Napi::String::New(env, result);
}

Napi::Value add(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  if(info.Length() < 2) {
    Napi::TypeError::New(env, "wrong args").ThrowAsJavaScriptException();
    return env.Null();
  }

  int len = info.Length();
  double sum = 0;
  while (len)
  {
    sum = sum + info[--len].As<Napi::Number>().DoubleValue();
  }
  return Napi::Number::New(env, sum);
}

Napi::Promise asyncAdd(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::Promise::Deferred deferred = Napi::Promise::Deferred::New(env);
  if(info.Length() < 2) {
    deferred.Reject(Napi::TypeError::New(env, "wrong args").Value());
    return deferred.Promise();
  }

  int len = info.Length();
  double sum = 0;
  while (len)
  {
    sum = sum + info[--len].As<Napi::Number>().DoubleValue();
  }
  deferred.Resolve(Napi::Number::New(env, sum));

  return deferred.Promise();
}


// 设置类似于 exports = {key:value}的模块导出
Napi::Object Init(Napi::Env env, Napi::Object exports) {
  exports.Set(
    Napi::String::New(env, "hello"), // key
    Napi::Function::New(env, hello)  // value
  );

  exports.Set(
    Napi::String::New(env, "add"), // key
    Napi::Function::New(env, add)  // value
  );

  exports.Set(
    Napi::String::New(env, "asyncAdd"), // key
    Napi::Function::New(env, asyncAdd)  // value
  );

  return exports;
}

NODE_API_MODULE(hello, Init)