load("//tools/cpp:rules.bzl", "cc_impl_lib")
load("//notes/core/cpp:visibility.bzl", "INTERNAL_CONSUMERS")

cc_impl_lib(
    name = "database",
    srcs = [
        "database_cursor.cpp",
        "database_exception.cpp",
        "database_statement.cpp",
    ],
    hdrs = [
        "database_exception.hpp",
    ],
    visibility = INTERNAL_CONSUMERS,
    deps = [
        "//notes/core/cpp/include/database",
    ],
)
