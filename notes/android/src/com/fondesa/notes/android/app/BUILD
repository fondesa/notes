load("//tools/android:defs.bzl", "android_bin")

android_bin(
    name = "app",
    srcs = glob(["*.kt"]),
    manifest = "AndroidManifest.xml",
    resource_files = glob(["res/**"]),
    visibility = ["//apps:__pkg__"],
    deps = [
        "//notes/core/jvm/src/com/fondesa/notes/core/notes/internal",
    ],
)
