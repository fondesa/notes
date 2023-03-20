load("//notes/core/cpp:defs.bzl", "cc_core_lib")

cc_core_lib(
    name = "database",
    srcs = [
        "notes_database_client.cpp",
    ],
    hdrs = [
        "notes_database_client.hpp",
    ],
    deps = [
        "//notes/core/cpp/src/database",
        "//notes/core/cpp/src/note/dao",
    ],
)
