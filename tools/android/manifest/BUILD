load("@rules_python//python:defs.bzl", "py_binary")
load("//tools/android:properties.bzl", "ANDROID_MIN_SDK", "ANDROID_TARGET_SDK")
load("//tools/android/manifest:rules.bzl", "library_manifest")

py_binary(
    name = "manifest_transformer",
    srcs = ["transform_manifest.py"],
    main = "transform_manifest.py",
    visibility = ["//notes/android:__subpackages__"],
)

# TODO move
library_manifest(
    name = "default_library_manifest",
    min_sdk_version = ANDROID_MIN_SDK,
    target_sdk_version = ANDROID_TARGET_SDK,
    visibility = ["//notes/android:__subpackages__"],
)
