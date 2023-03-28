load("@rules_jvm_external//:specs.bzl", "maven")

MAVEN_ARTIFACTS = [
    maven.artifact("javax.inject", "javax.inject", "1"),
]
