#pragma once

#include <jni.h>
#include <string>

namespace Jni {
class ToNative {
 public:
  ToNative(JNIEnv *env);

  int toInt(jobject obj, jfieldID field);

  std::string toString(jobject obj, jfieldID field);

 private:
  JNIEnv *env;
};
}  // namespace Jni