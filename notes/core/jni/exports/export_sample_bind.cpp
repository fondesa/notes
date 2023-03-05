#include <jni.h>
#include <memory>

#include "sample_bind.hpp"

extern "C"
JNIEXPORT jint JNICALL
Java_com_fondesa_notes_core_SampleBind_fooFromJNI(
    JNIEnv *env,
    jobject /* this */) {
    auto foo = std::make_shared<SampleBind::Foo>();
    return foo->bar();
}
