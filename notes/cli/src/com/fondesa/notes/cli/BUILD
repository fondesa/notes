load("@rules_kotlin//kotlin:jvm.bzl", "kt_jvm_binary")
load("@rules_java//java:defs.bzl", "java_library")

cc_binary(
    name = "app_native_libs_wrapper",
    linkshared = True,
    deps = [
        "//notes/core/jni/exports:jni_sample_bind",
    ],
)

java_library(
    name = "app_jvm_wrapper",
    srcs = ["AppGenTemp.java"],
    deps = [":app_native_libs_wrapper"],
)

kt_jvm_binary(
    name = "app",
    srcs = [
        "App.kt",
    ],
    jvm_flags = ["-Djava.library.path=notes/cli/src/com/fondesa/notes/cli"],
    main_class = "com.fondesa.notes.cli.AppKt",
    deps = [
        ":app_jvm_wrapper",
        "//notes/core/jvm/src/com/fondesa/notes/core:sample_bind",
    ],
)
