load("//tools/cpp:defs.bzl", "cc_lib", "cc_test")

visibility("//notes/core/cpp/...")

_SHARED_COPTS = [
    "-Inotes/core/cpp/src",
]

_INTERNAL_CONSUMERS = [
    "//notes/core/cpp/src:__subpackages__",
    "//notes/core/cpp/test:__subpackages__",
]

_PUBLIC_CONSUMERS = [
    "//notes/core/cpp/public:__pkg__",
]

def cc_core_lib(
        is_public = False,
        **kwargs):
    visibility = list(_INTERNAL_CONSUMERS)
    if is_public:
        visibility.extend(_PUBLIC_CONSUMERS)

    cc_lib(
        copts = _SHARED_COPTS,
        visibility = visibility,
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
