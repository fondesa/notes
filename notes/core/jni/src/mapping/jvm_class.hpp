#pragma once

#include <jni.h>
#include <string>

namespace Jni {

class JvmClass {
 public:
  static JvmClass from(JNIEnv *env, std::string className);

  jmethodID constructor(std::string signature);

  jmethodID method(std::string name, std::string signature);

  jfieldID field(std::string name, std::string signature);

 private:
  JvmClass(JNIEnv *env, jclass cls);

  JNIEnv *env;
  jclass cls;
};
}  // namespace Jni