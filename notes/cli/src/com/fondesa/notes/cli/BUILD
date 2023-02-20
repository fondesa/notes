load("@rules_kotlin//kotlin:jvm.bzl", "kt_jvm_binary")

kt_jvm_binary(
    name = "app",
    srcs = [
        "App.kt",
    ],
    jvm_flags = ["-Djava.library.path=notes/core/jni/exports"],
    main_class = "com.fondesa.notes.cli.AppKt",
    deps = [
        "//notes/core/jvm/src/com/fondesa/notes/core:sample_bind",
    ],
)
