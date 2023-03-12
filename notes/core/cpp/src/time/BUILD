load("//tools/cpp:rules.bzl", "cc_impl_lib")
load("//notes/core/cpp:visibility.bzl", "INTERNAL_CONSUMERS")

package(
    default_visibility = [
        "//tensorflow/cc/experimental/libtf:__subpackages__",
        "//tensorflow/python/saved_model:__subpackages__",
    ],
)

cc_impl_lib(
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
