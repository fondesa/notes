load("//tools/cpp:rules.bzl", "cc_headers_lib")
load("//notes/core/cpp:visibility.bzl", "HDRS_CONSUMERS")

cc_headers_lib(
    name = "database",
    hdrs = [
        "database.hpp",
        "database_client.hpp",
        "database_cursor.hpp",
        "database_statement.hpp",
    ],
    visibility = HDRS_CONSUMERS,
)
