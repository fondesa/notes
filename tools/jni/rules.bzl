load("@rules_cc//cc:defs.bzl", "cc_library")
load("//tools/cpp:properties.bzl", "INCLUDE_COPTS")

def cc_jni_library(**kwargs):
    deps = kwargs.pop("deps")
    cc_library(
        alwayslink = True,
        copts = INCLUDE_COPTS,
        deps = deps + ["//tools/jni:jni"],
        visibility = [
            "//notes/core/jvm:__subpackages__",
            "//notes/core/jni:__subpackages__",
            "//notes/android:__subpackages__",
            "//notes/cli:__subpackages__",
        ],
        **kwargs
    )
