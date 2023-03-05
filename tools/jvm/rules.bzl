load("@rules_java//java:defs.bzl", "java_library")
load("@rules_kotlin//kotlin:jvm.bzl", "kt_jvm_binary", "kt_jvm_library")
load("@rules_cc//cc:defs.bzl", "cc_binary")
load("//tools/jvm/internal:gen_java_class.bzl", "gen_java_class")

jvm_lib = kt_jvm_library

jvm_bin = kt_jvm_binary

def jvm_native_bin(
        name,
        native_wrapper_name,
        native_wrapper_deps,
        **kwargs):
    cc_binary(
        name = native_wrapper_name,
        linkshared = True,
        deps = native_wrapper_deps,
    )
    java_wrapper_name = "%s_jvm_native_wrapper" % name
    _jvm_native_wrapper(
        name = java_wrapper_name,
        native_deps = [native_wrapper_name],
    )
    deps = kwargs.pop("deps", [])
    jvm_bin(
        name = name,
        deps = deps + [java_wrapper_name],
        **kwargs
    )

def jvm_native_lib(
        name,
        native_deps,
        **kwargs):
    java_wrapper_name = "%s_jvm_native_wrapper" % name
    _jvm_native_wrapper(
        name = java_wrapper_name,
        native_deps = native_deps,
    )
    deps = kwargs.pop("deps", [])
    jvm_lib(
        name = name,
        deps = deps + [java_wrapper_name],
        **kwargs
    )

def _jvm_native_wrapper(
        name,
        native_deps):
    gen_rule_name = "%s_internal_gen" % name
    gen_java_class(
        name = gen_rule_name,
        java_class_name = "Generated_%s" % name,
    )

    java_library(
        name = name,
        srcs = [gen_rule_name],
        deps = native_deps,
    )
