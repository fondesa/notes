load("//notes/core/cpp:defs.bzl", "cc_core_lib")

cc_core_lib(
    name = "dao",
    srcs = [
        "drafts_dao_impl.cpp",
    ],
    hdrs = [
        "drafts_dao.hpp",
        "drafts_dao_impl.hpp",
    ],
    deps = [
        "//notes/core/cpp/src/database",
        "//notes/core/cpp/src/draft:draft_api",
    ],
)
