load("//tools/jni:rules.bzl", "cc_jni_library")
load("//notes/core/jni:visibility.bzl", "API_CONSUMERS")

cc_jni_library(
    name = "jni_sample_bind",
    srcs = [
        "export_sample_bind.cpp",
    ],
    visibility = API_CONSUMERS,
    deps = [
        "//notes/core/cpp/src:sample_bind",
    ],
)
