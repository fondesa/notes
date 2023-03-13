load("//tools/jvm:defs.bzl", "jvm_native_bin")

jvm_native_bin(
    name = "app",
    srcs = [
        "App.kt",
    ],
    main_class = "com.fondesa.notes.cli.AppKt",
    native_wrapper_deps = [
        "//notes/core/jni/public:jni_sample_bind",
    ],
    native_wrapper_name = "app_native",
    visibility = ["//apps:__pkg__"],
    deps = [
        "//notes/core/jvm/src/com/fondesa/notes/core:sample_bind",
    ],
)
