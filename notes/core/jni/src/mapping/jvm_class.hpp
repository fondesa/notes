#pragma once

#include <jni.h>
#include <string>

namespace Jni {

class JvmClass {
 public:
  JvmClass(JNIEnv *env, std::string className);

  jmethodID constructor(std::string signature);

  jmethodID method(std::string name, std::string signature);

  jfieldID field(std::string name, std::string signature);

 private:
  JNIEnv *env;
  jclass cls;
};
}  // namespace Jni