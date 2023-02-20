load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "jni_exports_sample_bind",
    srcs = [
        "export_sample_bind.cpp",
    ],
    # TODO: swap to stricter visibility in a real scenario
    visibility = ["//visibility:public"],
    deps = [
        #        "//notes/core/cpp/src:sample_bind",
        "//notes/core/jni",
    ],
    alwayslink = True,
)

cc_binary(
    name = "jni_sample_bind",
    linkshared = True,
    visibility = ["//visibility:public"],
    deps = [":jni_exports_sample_bind"],
)
