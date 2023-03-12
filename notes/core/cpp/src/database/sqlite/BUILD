load("//tools/cpp:rules.bzl", "cc_impl_lib")
load("//notes/core/cpp:visibility.bzl", "INTERNAL_CONSUMERS")

cc_impl_lib(
    name = "sqlite",
    srcs = [
        "shared_sqlite_statement.cpp",
        "shared_sqlite_statement.hpp",
        "sqlite_cursor.cpp",
        "sqlite_cursor.hpp",
        "sqlite_database.cpp",
        "sqlite_database_exception.hpp",
        "sqlite_statement.cpp",
        "sqlite_statement.hpp",
    ],
    hdrs = [
        "sqlite_database.hpp",
    ],
    visibility = INTERNAL_CONSUMERS,
    deps = [
        "//notes/core/cpp/src/database",
        "@org_sqlite//:sqlite",
    ],
)
