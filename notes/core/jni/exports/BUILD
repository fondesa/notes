load("//tools/jni:rules.bzl", "cc_jni_library")
load("//notes/core/jni:visibility.bzl", "CONSUMERS")

cc_jni_library(
    name = "jni_sample_bind",
    srcs = [
        "export_sample_bind.cpp",
    ],
    visibility = CONSUMERS,
    deps = [
        "//notes/core/cpp/public:sample_bind",
    ],
)
