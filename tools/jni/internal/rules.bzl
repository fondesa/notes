load("@rules_cc//cc:defs.bzl", "cc_library")
load("//tools/cpp:properties.bzl", "INCLUDE_COPTS")

def cc_jni_library(**kwargs):
    deps = kwargs.pop("deps")
    cc_library(
        alwayslink = True,
        copts = INCLUDE_COPTS,
        deps = deps + ["//tools/jni:jni"],
        **kwargs
    )
