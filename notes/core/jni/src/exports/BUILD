load("//notes/core/jni:defs.bzl", "cc_core_jni_lib")

cc_core_jni_lib(
    name = "jni_notes_interactor",
    srcs = [
        "jni_notes_interactor.cpp",
    ],
    is_public = True,
    deps = [
        "//notes/core/cpp/public:notes",
        "//notes/core/jni/src/mapping",
        "//notes/core/jni/src/mem",
    ],
)
