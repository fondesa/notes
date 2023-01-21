load("@bazel_skylib//rules:native_binary.bzl", "native_binary")

native_binary(
    name = "buildifier",
    src = select(
        {
            "//tools/platforms:linux_x86_64": "@buildifier_linux_x86_64//file",
            "//tools/platforms:macos_arm64": "@buildifier_macos_arm64//file",
            "//tools/platforms:macos_x86_64": "@buildifier_macos_x86_64//file",
            "//tools/platforms:windows_x86_64": "@buildifier_windows_x86_64//file",
        },
        no_match_error = "Buildifier: platform not supported"
    ),
    out = "buildifier",
)