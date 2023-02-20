config_setting(
    name = "linux_x86_64",
    values = {
        "cpu": "k8",
    },
)

config_setting(
    name = "macos",
    values = {
        "apple_platform_type": "macos",
    },
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

config_setting(
    name = "android_arm",
    values = {
        "crosstool_top": ANDROID_CROSSTOOL_TOP,
        "cpu": "armeabi-v7a",
    },
)

config_setting(
    name = "android_arm64",
    values = {
        "crosstool_top": ANDROID_CROSSTOOL_TOP,
        "cpu": "arm64-v8a",
    },
)

config_setting(
    name = "android_x86",
    values = {
        "crosstool_top": ANDROID_CROSSTOOL_TOP,
        "cpu": "x86",
    },
)

config_setting(
    name = "android_x86_64",
    values = {
        "crosstool_top": ANDROID_CROSSTOOL_TOP,
        "cpu": "x86_64",
    },
)
