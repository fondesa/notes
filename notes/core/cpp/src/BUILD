load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "sample_bind",
    srcs = [
        "sample_bind.cpp",
    ],
    copts = [
        "-Inotes/core/cpp/include",
        "-Inotes/core/cpp/src",
    ],
    # TODO: swap to stricter visibility in a real scenario
    visibility = ["//visibility:public"],
    deps = [
        "//notes/core/cpp/include:sample_bind",
    ],
)
