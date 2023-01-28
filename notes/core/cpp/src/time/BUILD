load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "time",
    srcs = [
        "clock_impl.cpp",
        "clock_impl.hpp",
        "time_format.cpp",
    ],
    copts = [
        "-Inotes/core/cpp/include",
        "-Inotes/core/cpp/src",
    ],
    visibility = ["//notes/core/cpp/test:__subpackages__"],
    deps = [
        "//notes/core/cpp/include/time",
    ],
)
