load("//notes/core/cpp:defs.bzl", "cc_core_lib")
load("//notes/core/cpp:visibility.bzl", "INTERNAL_CONSUMERS")

cc_core_lib(
    name = "database",
    srcs = [
        "database_client.cpp",
    ],
    hdrs = [
        "database_client.hpp",
    ],
    visibility = INTERNAL_CONSUMERS,
    deps = [
        "//notes/core/cpp/src/database",
        "//notes/core/cpp/src/database/sqlite",
    ],
)
