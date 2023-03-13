load("//tools/jni:defs.bzl", "cc_jni_lib")

_SHARED_COPTS = [
    "-Inotes/core/cpp/src",
    "-Inotes/core/cpp/jni",
]

def cc_core_jni_lib(**kwargs):
    cc_jni_lib(
        copts = _SHARED_COPTS,
        **kwargs
    )
