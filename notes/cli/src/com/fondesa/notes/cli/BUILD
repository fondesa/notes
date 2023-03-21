load("//tools/jvm:defs.bzl", "jvm_native_bin")

jvm_native_bin(
    name = "app",
    srcs = [
        "CliApp.kt",
    ],
    main_class = "com.fondesa.notes.cli.CliApp",
    native_wrapper_deps = [
        "//notes/core/jni/public:jni_notes_interactor",
    ],
    native_wrapper_name = "app_native",
    visibility = ["//apps:__pkg__"],
    deps = [
        "//notes/core/jvm/src/com/fondesa/notes/core/notes/internal",
    ],
)
