load("//tools/cpp:rules.bzl", "cc_impl_lib")
load("//notes/core/cpp:visibility.bzl", "IMPL_CONSUMERS")

cc_impl_lib(
    name = "note",
    srcs = [
        "note.cpp",
    ],
    visibility = IMPL_CONSUMERS,
    deps = [
        "//notes/core/cpp/include/note",
    ],
)
