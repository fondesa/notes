load("@rules_java//java:defs.bzl", "java_library")
load("@fmeum_rules_jni//jni:defs.bzl", "java_jni_library")

java_jni_library(
    name = "sample_bind",
    srcs = [
        "SampleBind.java",
    ],
    native_libs = [
        "//notes/core/jni/src/main/native/com/fondesa/notes/core:jni_exports_sample_bind",
    ],
    # TODO: swap to stricter visibility in a real scenario
    visibility = ["//visibility:public"],
    deps = [
    ],
)
