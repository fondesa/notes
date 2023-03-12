load("@rules_cc//cc:defs.bzl", "cc_test")

cc_test(
    name = "time_test",
    srcs = [
        "clock_impl_test.cpp",
        "time_format_test.cpp",
    ],
    copts = [
        "-Inotes/core/cpp/include",
        "-Inotes/core/cpp/src",
    ],
    deps = [
        "//notes/core/cpp/src/time",
        "@com_github_googletest//:gtest_main",
    ],
)
