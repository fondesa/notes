load("@rules_cc//cc:defs.bzl", "cc_library")
load("@fmeum_rules_jni//jni:defs.bzl", "cc_jni_library")

cc_jni_library(
    name = "jni_exports_sample_bind",
    srcs = [
        "export_sample_bind.cpp",
    ],
    # TODO: swap to stricter visibility in a real scenario
    visibility = ["//visibility:public"],
    deps = [
        #        "//notes/core/cpp/src:sample_bind",
        #        "//notes/core/jni",
    ],
)
