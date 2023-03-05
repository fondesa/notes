load("//tools/jni:rules.bzl", "cc_jni_library")

cc_jni_library(
    name = "jni_sample_bind",
    srcs = [
        "export_sample_bind.cpp",
    ],
    copts = [
        "-Inotes/core/cpp/include",
    ],
    # TODO: swap to stricter visibility in a real scenario
    visibility = ["//visibility:public"],
    deps = [
        "//notes/core/cpp/src:sample_bind",
    ],
)
