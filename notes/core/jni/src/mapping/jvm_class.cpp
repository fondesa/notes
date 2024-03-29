#include "jvm_class.hpp"

Jni::JvmClass::JvmClass(JNIEnv *env, std::string className) : env(env) {
  cls = env->FindClass(className.c_str());
  if (!cls) {
    auto msg = "The class \"" + className + "\" doesn't exist.";
    env->ThrowNew(env->FindClass("java/lang/ClassNotFoundException"), msg.c_str());
  }
}

jclass Jni::JvmClass::get() {
  return cls;
}

jmethodID Jni::JvmClass::constructor(std::string signature) {
  return method("<init>", signature);
}

jmethodID Jni::JvmClass::method(std::string name, std::string signature) {
  jmethodID method = env->GetMethodID(cls, name.c_str(), signature.c_str());
  if (!method) {
    auto msg = "The method \"" + name + "[signature: " + signature + "]\" doesn't exist.";
    env->ThrowNew(env->FindClass("java/lang/NoSuchMethodError"), msg.c_str());
  }
  return method;
}

jfieldID Jni::JvmClass::field(std::string name, std::string signature) {
  jfieldID field = env->GetFieldID(cls, name.c_str(), signature.c_str());
  if (!field) {
    auto msg = "The field \"" + name + "[signature: " + signature + "]\" doesn't exist.";
    env->ThrowNew(env->FindClass("java/lang/NoSuchFieldException"), msg.c_str());
  }
  return field;
}
