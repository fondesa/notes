load("//tools/android:properties.bzl", "ANDROID_MIN_SDK", "ANDROID_TARGET_SDK")
load("//tools/android/manifest:rules.bzl", "gen_manifest")

gen_manifest(
    name = "default_library_manifest",
    min_sdk_version = ANDROID_MIN_SDK,
    target_sdk_version = ANDROID_TARGET_SDK,
    visibility = ["//notes/android:__subpackages__"],
)
