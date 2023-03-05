load("@rules_cc//cc:defs.bzl", "cc_library")

def cc_jni_library(**kwargs):
    deps = kwargs.pop("deps")
    cc_library(
        alwayslink = True,
        deps = deps + ["//tools/jni:jni"],
        **kwargs
    )
