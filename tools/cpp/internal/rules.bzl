load("@rules_cc//cc:defs.bzl", "cc_library")
load("//tools/cpp:properties.bzl", "INCLUDE_COPTS")

def cc_headers_lib(**kwargs):
    cc_library(
        copts = INCLUDE_COPTS,
        **kwargs
    )

def cc_impl_lib(**kwargs):
    cc_library(
        copts = INCLUDE_COPTS + [
            "-Inotes/core/cpp/src",
        ],
        **kwargs
    )
