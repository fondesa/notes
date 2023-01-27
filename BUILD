load("@rules_kotlin//kotlin:core.bzl", "define_kt_toolchain")
load("//tools/linters/buildifier:rules.bzl", "buildifier")

buildifier(
    name = "buildifier_check",
    mode = "check",
)

buildifier(
    name = "buildifier_fix",
    mode = "fix",
)

KOTLIN_LANGUAGE_LEVEL = "1.7"

define_kt_toolchain(
    name = "kotlin_toolchain",
    api_version = KOTLIN_LANGUAGE_LEVEL,
    jvm_target = "1.8",
    language_version = KOTLIN_LANGUAGE_LEVEL,
)
