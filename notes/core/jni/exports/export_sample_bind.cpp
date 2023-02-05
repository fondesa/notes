#include <jni.h>

//#include "sample_bind.hpp"

extern "C"
JNIEXPORT jint JNICALL
Java_com_fondesa_notes_core_SampleBind_fooFromJNI(
    JNIEnv *env,
    jobject /* this */) {
    return 78;
}
