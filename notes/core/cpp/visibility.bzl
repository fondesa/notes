visibility("//notes/core/cpp/...")

INTERNAL_CONSUMERS = [
    "//notes/core/cpp/src:__subpackages__",
    "//notes/core/cpp/test:__subpackages__",
]

PUBLIC_CONSUMERS = INTERNAL_CONSUMERS + [
    "//notes/core/cpp/public:__pkg__",
]
