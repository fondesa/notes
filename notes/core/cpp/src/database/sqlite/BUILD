load("//notes/core/cpp:defs.bzl", "cc_core_lib")

cc_core_lib(
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
    deps = [
        "//notes/core/cpp/src/database",
        "@org_sqlite//:sqlite",
    ],
)
