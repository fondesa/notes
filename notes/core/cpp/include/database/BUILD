load("//tools/cpp:rules.bzl", "cc_headers_lib")
load("//notes/core/cpp:visibility.bzl", "PUBLIC_CONSUMERS")

cc_headers_lib(
    name = "database",
    hdrs = [
        "database.hpp",
        "database_client.hpp",
        "database_cursor.hpp",
        "database_statement.hpp",
    ],
    visibility = PUBLIC_CONSUMERS,
)
