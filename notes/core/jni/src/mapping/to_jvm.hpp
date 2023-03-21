#pragma once

#include <jni.h>
#include <string>

namespace Jni {
class ToJvm {
 public:
  ToJvm(JNIEnv *env);

  jstring toString(std::string value);

 private:
  JNIEnv *env;
};
}  // namespace Jni