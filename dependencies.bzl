load("@rules_jvm_external//:specs.bzl", "maven")

MAVEN_ARTIFACTS = [
    maven.artifact("com.google.code.findbugs", "jsr305", "3.0.2"),
]
