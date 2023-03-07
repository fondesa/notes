load("@rules_kotlin//kotlin:jvm.bzl", "kt_jvm_binary", "kt_jvm_library")
load(
    "//tools/jvm/internal:jvm_native.bzl",
    _jvm_native_bin = "jvm_native_bin",
    _jvm_native_lib = "jvm_native_lib",
)

jvm_bin = kt_jvm_binary
jvm_lib = kt_jvm_library
jvm_native_bin = _jvm_native_bin
jvm_native_lib = _jvm_native_lib
