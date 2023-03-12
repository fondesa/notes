load("//notes/core/cpp:defs.bzl", "cc_core_lib")
load("//notes/core/cpp:visibility.bzl", "INTERNAL_CONSUMERS")

cc_core_lib(
    name = "database",
    srcs = [
        "database_cursor.cpp",
        "database_exception.cpp",
        "database_statement.cpp",
    ],
    hdrs = [
        "database.hpp",
        "database_cursor.hpp",
        "database_exception.hpp",
        "database_statement.hpp",
    ],
    visibility = INTERNAL_CONSUMERS,
)
