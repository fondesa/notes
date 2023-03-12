load("//notes/core/jni:defs.bzl", "cc_core_jni_lib")
load("//notes/core/jni:visibility.bzl", "CONSUMERS")

cc_core_jni_lib(
    name = "jni_sample_bind",
    srcs = [
        "export_sample_bind.cpp",
    ],
    visibility = CONSUMERS,
    deps = [
        "//notes/core/cpp/public:sample_bind",
    ],
)
