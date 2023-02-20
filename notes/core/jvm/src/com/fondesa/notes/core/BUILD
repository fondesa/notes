load("@rules_java//java:defs.bzl", "java_library")

java_library(
    name = "sample_bind",
    srcs = [
        "SampleBind.java",
    ],
    data = [
        "//notes/core/jni/exports:jni_sample_bind",
    ],
    # TODO: swap to stricter visibility in a real scenario
    visibility = ["//visibility:public"],
    deps = [
    ],
)
