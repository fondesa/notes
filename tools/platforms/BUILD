load("@bazel_skylib//lib:selects.bzl", "selects")

config_setting(
    name = "linux_x86_64",
    values = {
        "cpu": "k8",
    },
)

selects.config_setting_group(
    name = "macos",
    match_any = [
        ":macos_x86_64",
        ":macos_arm64",
    ],
)

config_setting(
    name = "macos_x86_64",
    values = {
        "apple_platform_type": "macos",
        "cpu": "darwin",
    },
)

config_setting(
    name = "macos_arm64",
    values = {
        "apple_platform_type": "macos",
        "cpu": "darwin_arm64",
    },
)

config_setting(
    name = "windows_x86_64",
    values = {
        "cpu": "x64_windows",
    },
)

ANDROID_CROSSTOOL_TOP = "@androidndk//:toolchain"

config_setting(
    name = "android",
    values = {
        "crosstool_top": ANDROID_CROSSTOOL_TOP,
    },
)
