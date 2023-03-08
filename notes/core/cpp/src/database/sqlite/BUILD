load("//tools/cpp:rules.bzl", "cc_impl_lib")
load("//notes/core/cpp:visibility.bzl", "IMPL_CONSUMERS")

cc_impl_lib(
    name = "sqlite",
    srcs = [
        "shared_sqlite_statement.cpp",
        "shared_sqlite_statement.hpp",
        "sqlite_database_exception.hpp",
    ],
    visibility = IMPL_CONSUMERS,
    deps = [
        "//notes/core/cpp/include/database",
        "//notes/core/cpp/src/database",
        "@org_sqlite//:sqlite",
    ],
)
