load("//tools/android:rules.bzl", "android_bin")

android_bin(
    name = "app",
    srcs = glob(["*.kt"]),
    manifest = "AndroidManifest.xml",
    resource_files = glob(["res/**"]),
    deps = [
        "//notes/core/jvm/src/com/fondesa/notes/core:sample_bind"
    ]
)
