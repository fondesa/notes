#pragma once

#include <jni.h>
#include <memory>

namespace Jni {
template <typename T>
class JvmPointer {
 public:
  template <typename... ARGS>
  static JvmPointer<T> *make(ARGS... args) {
    return new JvmPointer<T>(args...);
  }

  static JvmPointer<T> *create(std::shared_ptr<T> obj) {
    return new JvmPointer(obj);
  }

  jlong toAddress() const {
    return reinterpret_cast<jlong>(this);
  }

  static std::shared_ptr<T> fromAddress(jlong address) {
    return from(address)->obj;
  }

  static void dispose(jlong address) {
    auto obj = from(address);
    delete obj;
  }

 private:
  std::shared_ptr<T> obj;

  static JvmPointer<T> *from(jlong address) {
    return reinterpret_cast<JvmPointer<T> *>(address);
  }

  template <typename... ARGS>
  explicit JvmPointer(ARGS... args) {
    obj = std::make_shared<T>(args...);
  }

  explicit JvmPointer(std::shared_ptr<T> obj) {
    this->obj = obj;
  }
};
}  // namespace Jni
