#include "to_native.hpp"

Jni::ToNative::ToNative(JNIEnv *env) : env(env) {
}

int Jni::ToNative::toInt(jobject obj, jfieldID field) {
  return env->GetIntField(obj, field);
}

std::string Jni::ToNative::toString(jobject obj, jfieldID field) {
  jboolean isCopy = JNI_TRUE;
  auto jvmString = (jstring)env->GetObjectField(obj, field);
  auto utfValue = env->GetStringUTFChars(jvmString, &isCopy);
  auto nativeString = std::string(utfValue);
  env->ReleaseStringUTFChars(jvmString, utfValue);
  return nativeString;
}
