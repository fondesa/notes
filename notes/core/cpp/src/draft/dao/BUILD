load("//notes/core/cpp:defs.bzl", "cc_core_lib")

cc_core_lib(
    name = "dao",
    srcs = [
        "sqlite_drafts_dao.cpp",
        "sqlite_drafts_dao.hpp",
    ],
    hdrs = [
        "drafts_dao.hpp",
    ],
    deps = [
        "//notes/core/cpp/src/database",
        "//notes/core/cpp/src/draft:draft_api",
    ],
)
