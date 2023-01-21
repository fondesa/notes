workspace(name = "notes")

load("//:repositories.bzl", "setup_repositories")

setup_repositories()

load("@rules_jvm_external//:repositories.bzl", "rules_jvm_external_deps")

rules_jvm_external_deps()

load("@rules_jvm_external//:setup.bzl", "rules_jvm_external_setup")

rules_jvm_external_setup()

load("@rules_jvm_external//:defs.bzl", "maven_install")
load("//:dependencies.bzl", "MAVEN_ARTIFACTS")

maven_install(
    artifacts = MAVEN_ARTIFACTS,
    fail_if_repin_required = True,
    fail_on_missing_checksum = True,
    maven_install_json = "//:maven_install.json",
    repositories = [
        "https://repo1.maven.org/maven2",
    ],
    strict_visibility = True,
    version_conflict_policy = "pinned",
)

load("@maven//:defs.bzl", "pinned_maven_install")

pinned_maven_install()
