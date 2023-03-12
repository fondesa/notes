load("//notes/core/cpp:defs.bzl", "cc_core_lib")
load("//notes/core/cpp:visibility.bzl", "INTERNAL_CONSUMERS")

cc_core_lib(
    name = "time",
    srcs = [
        "clock_impl.cpp",
        "clock_impl.hpp",
        "time_format.cpp",
    ],
    hdrs = [
        "clock.hpp",
        "time_format.hpp",
    ],
    visibility = INTERNAL_CONSUMERS,
)
