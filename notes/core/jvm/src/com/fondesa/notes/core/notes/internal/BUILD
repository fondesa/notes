load("//tools/jvm:defs.bzl", "jvm_native_lib")
load("//notes/core/jvm:visibility.bzl", "PUBLIC_CONSUMERS")

jvm_native_lib(
    name = "internal",
    srcs = [
        "NativeNotesInteractor.kt",
    ],
    native_deps = [
        #        "//notes/core/jni/public:jni_sample_bind",
    ],
    visibility = PUBLIC_CONSUMERS,
    deps = [
        "//notes/core/jvm/src/com/fondesa/notes/core/notes",
    ],
)
