load("//tools/cpp:rules.bzl", "cc_impl_lib")
load("//notes/core/cpp:visibility.bzl", "IMPL_CONSUMERS")

cc_impl_lib(
    name = "time",
    srcs = [
        "clock_impl.cpp",
        "clock_impl.hpp",
        "time_format.cpp",
    ],
    visibility = IMPL_CONSUMERS,
    deps = [
        "//notes/core/cpp/include/time",
    ],
)
