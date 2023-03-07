load("//tools/jvm:rules.bzl", "jvm_native_lib")
load("//notes/core/jvm:visibility.bzl", "CONSUMERS")

jvm_native_lib(
    name = "sample_bind",
    srcs = [
        "SampleBind.kt",
    ],
    native_deps = [
        "//notes/core/jni/exports:jni_sample_bind",
    ],
    visibility = CONSUMERS,
)
