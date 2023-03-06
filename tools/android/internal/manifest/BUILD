load("@rules_python//python:defs.bzl", "py_binary")
load("//tools/android/internal:properties.bzl", "ANDROID_MIN_SDK", "ANDROID_TARGET_SDK")
load("//tools/android/internal/manifest:rules.bzl", "gen_manifest")

exports_files(["LibraryAndroidManifest.xml.tpl"])

py_binary(
    name = "manifest_transformer",
    srcs = ["manifest_transformer.py"],
    main = "manifest_transformer.py",
    visibility = ["//notes/android:__subpackages__"],
)

gen_manifest(
    name = "default_library_manifest",
    min_sdk_version = ANDROID_MIN_SDK,
    target_sdk_version = ANDROID_TARGET_SDK,
    visibility = ["//tools/android:__pkg__"],
)
