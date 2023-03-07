load("//tools/cpp:rules.bzl", "cc_impl_lib")
load("//notes/core/cpp:visibility.bzl", "IMPL_CONSUMERS")

cc_impl_lib(
    name = "database",
    srcs = [
        "database_cursor.cpp",
        "database_statement.cpp",
    ],
    visibility = IMPL_CONSUMERS,
    deps = [
        "//notes/core/cpp/include/database",
    ],
)
