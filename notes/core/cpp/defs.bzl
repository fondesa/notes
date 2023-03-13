load("//tools/cpp:defs.bzl", "cc_lib", "cc_test")

_SHARED_COPTS = [
    "-Inotes/core/cpp/src",
]

def cc_core_lib(**kwargs):
    cc_lib(
        copts = _SHARED_COPTS,
        **kwargs
    )

def cc_core_test(**kwargs):
    deps = kwargs.pop("deps", [])
    cc_test(
        copts = _SHARED_COPTS,
        deps = deps + [
            "@com_github_googletest//:gtest_main",
        ],
        **kwargs
    )
