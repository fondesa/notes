load("//tools/jvm:defs.bzl", "jvm_lib")
load("//notes/core/jvm:visibility.bzl", "PUBLIC_CONSUMERS")

jvm_lib(
    name = "di",
    srcs = [
        "NotesCoreModule.kt",
    ],
    # TODO: make internal
    visibility = PUBLIC_CONSUMERS,
    deps = [
        "//notes/core/jvm/src/com/fondesa/notes/core/notes",
        "//notes/core/jvm/src/com/fondesa/notes/core/notes/internal",
        "//third_party/jvm:dagger",
    ],
)
