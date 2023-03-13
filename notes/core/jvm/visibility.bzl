visibility("//notes/core/jvm/...")

INTERNAL_CONSUMERS = [
    "//notes/core/jvm:__subpackages__",
]

PUBLIC_CONSUMERS = INTERNAL_CONSUMERS + [
    "//notes/android:__subpackages__",
    "//notes/cli:__subpackages__",
]
