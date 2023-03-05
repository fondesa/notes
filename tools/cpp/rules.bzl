load("@rules_cc//cc:defs.bzl", "cc_library")
load("//tools/cpp:properties.bzl", "INCLUDE_COPTS")

def cc_headers_lib(name, hdrs):
    cc_library(
        name = name,
        hdrs = hdrs,
        copts = INCLUDE_COPTS,
        visibility = [
            "//notes/core/cpp:__subpackages__",
            "//notes/core/jni:__subpackages__",
        ],
    )

def cc_impl_lib(**kwargs):
    cc_library(
        copts = INCLUDE_COPTS + [
            "-Inotes/core/cpp/src",
        ],
        visibility = [
            "//notes/core/cpp/src:__subpackages__",
            "//notes/core/cpp/test:__subpackages__",
            "//notes/core/jni:__subpackages__",
        ],
        **kwargs
    )
