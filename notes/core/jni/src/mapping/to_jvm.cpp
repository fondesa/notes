#include "to_jvm.hpp"

Jni::ToJvm::ToJvm(JNIEnv *env) : env(env) {
}

jstring Jni::ToJvm::toString(std::string value) {
  return env->NewStringUTF(value.c_str());
}
