load(
    "@//:third_party/sqlite_archive_info.bzl",
    "SQLITE_ARCHIVE_ID",
    "SQLITE_ARCHIVE_NAME",
    "SQLITE_ARCHIVE_VERSION",
)

cc_library(
    name = "sqlite",
    srcs = ["%s/sqlite3.c" % SQLITE_ARCHIVE_ID],
    hdrs = ["%s/sqlite3.h" % SQLITE_ARCHIVE_ID],
    includes = [SQLITE_ARCHIVE_ID],
    visibility = ["//visibility:public"],
)
