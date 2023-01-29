load("@rules_android//android:rules.bzl", "android_binary")
load("//tools/android:rules.bzl", "android_library")

android_library(
    name = "app",
    srcs = glob(["*.kt"]),
    resource_files = glob(["res/**"]),
    deps = [
    ],
)

android_binary(
    name = "app_bin",
    manifest = "AndroidManifest.xml",
    manifest_values = {
        "versionCode": "1",
        "versionName": "1",
    },
    deps = [
        ":app",
    ],
)
