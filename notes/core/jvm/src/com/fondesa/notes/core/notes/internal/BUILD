load("//tools/jvm:defs.bzl", "jvm_native_lib")
load("//notes/core/jvm:visibility.bzl", "PUBLIC_CONSUMERS")

jvm_native_lib(
    name = "internal",
    srcs = [
        "NativeNotesInteractor.kt",
    ],
    native_deps = [
        "//notes/core/jni/public:jni_notes_interactor",
    ],
    # TODO: make internal
    visibility = PUBLIC_CONSUMERS,
    deps = [
        "//notes/core/jvm/src/com/fondesa/notes/core/notes",
        "@maven//:javax_inject_javax_inject",
    ],
)
