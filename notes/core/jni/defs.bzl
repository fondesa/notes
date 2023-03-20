load("//tools/jni:defs.bzl", "cc_jni_lib")

visibility("//notes/core/jni/...")

_SHARED_COPTS = [
    "-Inotes/core/cpp/src",
    "-Inotes/core/jni/src",
]

_INTERNAL_CONSUMERS = [
    "//notes/core/jni/src/exports:__subpackages__",
    "//notes/core/jni/test:__subpackages__",
]

_PUBLIC_CONSUMERS = [
    "//notes/core/jni/public:__pkg__",
]

def cc_core_jni_lib(
        is_public = False,
        **kwargs):
    visibility = list(_INTERNAL_CONSUMERS)
    if is_public:
        visibility.extend(_PUBLIC_CONSUMERS)

    cc_jni_lib(
        copts = _SHARED_COPTS,
        visibility = visibility,
        **kwargs
    )
