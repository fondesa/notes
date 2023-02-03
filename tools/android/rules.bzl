load("@rules_android_sdk//android:rules.bzl", "android_binary")
load("@rules_kotlin//kotlin:android.bzl", "kt_android_library")
load("//tools/android:properties.bzl", "ANDROID_MIN_SDK", "ANDROID_TARGET_SDK")
load("//tools/android/manifest:rules.bzl", "transform_manifest")

def android_bin(
        name,
        manifest,
        srcs = [],
        resource_files = [],
        deps = []):
    bin_internal_lib = "{}_bin_internal".format(name)
    kt_android_library(
        name = bin_internal_lib,
        srcs = srcs,
        manifest = "//tools/android:default_library_manifest",
        resource_files = resource_files,
        deps = deps,
    )

    android_binary(
        name = name,
        manifest = manifest,
        manifest_values = {
            "minSdkVersion": "%s" % ANDROID_MIN_SDK,
            "targetSdkVersion": "%s" % ANDROID_TARGET_SDK,
            "versionCode": "1",
            "versionName": "1",
        },
        deps = [bin_internal_lib],
    )

def android_lib(**kwargs):
    target_name = kwargs.get("name")
    if "manifest" in kwargs:
        original_manifest = kwargs.pop("manifest")
        manifest = original_manifest
        transform_manifest_target = "{}_manifest_transform".format(target_name)
        transform_manifest(
            name = transform_manifest_target,
            manifest = original_manifest,
            min_sdk_version = ANDROID_MIN_SDK,
            target_sdk_version = ANDROID_TARGET_SDK,
        )
        manifest = transform_manifest_target
    else:
        manifest = "//tools/android:default_library_manifest"

    kt_android_library(
        manifest = manifest,
        **kwargs
    )
