load("@rules_kotlin//kotlin:android.bzl", "kt_android_library")

def android_library(**kwargs):
    manifest = kwargs.pop("manifest", "//tools/android/manifest:default_library_manifest")
    kt_android_library(
        manifest = manifest,
        **kwargs
    )
