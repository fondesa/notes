load("@bazel_skylib//rules:copy_file.bzl", "copy_file")

cc_library(
    name = "jni",
    hdrs = select({
        # The Android toolchain makes the JNI headers available in the include path.
        "//tools/platforms:android": [],
        # Generates the JNI headers for non-Android toolchains.
        "//conditions:default": [
            ":jni_h",
            ":jni_md_h",
        ],
    }),
    includes = select({
        "//tools/platforms:android": [],
        "//conditions:default": ["."],
    }),
    visibility = ["//notes/core/jni:__subpackages__"],
)

# Rules to make the JNI headers (jni.h, jni_md.h) available in the include path.
# This is the same strategy used by Bazel and Tensorflow internally.

copy_file(
    name = "jni_h",
    src = "@bazel_tools//tools/jdk:jni_header",
    out = "jni.h",
)

copy_file(
    name = "jni_md_h",
    src = select({
        "//tools/platforms:macos": "@bazel_tools//tools/jdk:jni_md_header-darwin",
        "//tools/platforms:windows_x86_64": "@bazel_tools//tools/jdk:jni_md_header-windows",
        "//conditions:default": "@bazel_tools//tools/jdk:jni_md_header-linux",
    }),
    out = "jni_md.h",
)
