load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive", "http_file")

def setup_repositories():
    _repositories_jvm()
    _repositories_kotlin()
    _repositories_tools()

def _repositories_jvm():
    rules_jvm_external_version = "4.5"
    http_archive(
        name = "rules_jvm_external",
        sha256 = "b17d7388feb9bfa7f2fa09031b32707df529f26c91ab9e5d909eb1676badd9a6",
        strip_prefix = "rules_jvm_external-%s" % rules_jvm_external_version,
        url = "https://github.com/bazelbuild/rules_jvm_external/archive/%s.zip" % rules_jvm_external_version,
    )

def _repositories_kotlin():
    rules_kotlin_version = "1.7.1"
    http_archive(
        name = "io_bazel_rules_kotlin",
        sha256 = "fd92a98bd8a8f0e1cdcb490b93f5acef1f1727ed992571232d33de42395ca9b3",
        urls = ["https://github.com/bazelbuild/rules_kotlin/releases/download/v%s/rules_kotlin_release.tgz" % rules_kotlin_version],
    )

def _repositories_tools():
    http_file(
        name = "buildifier_linux_x86_64",
        downloaded_file_path = "buildifier",
        executable = True,
        sha256 = "7ff82176879c0c13bc682b6b0e482d670fbe13bbb20e07915edb0ad11be50502",
        urls = ["https://github.com/bazelbuild/buildtools/releases/download/6.0.0/buildifier-linux-amd64"],
    )
    http_file(
        name = "buildifier_macos_arm64",
        downloaded_file_path = "buildifier",
        executable = True,
        sha256 = "21fa0d48ef0b7251eb6e3521cbe25d1e52404763cd2a43aa29f69b5380559dd1",
        urls = ["https://github.com/bazelbuild/buildtools/releases/download/6.0.0/buildifier-darwin-arm64"],
    )
    http_file(
        name = "buildifier_macos_x86_64",
        downloaded_file_path = "buildifier",
        executable = True,
        sha256 = "3f8ab7dd5d5946ce44695f29c3b895ad11a9a6776c247ad5273e9c8480216ae1",
        urls = ["https://github.com/bazelbuild/buildtools/releases/download/6.0.0/buildifier-darwin-amd64"],
    )
    http_file(
        name = "buildifier_windows_x86_64",
        downloaded_file_path = "buildifier.exe",
        executable = True,
        sha256 = "b5da47fb9746f3966eed4920fac9325ef7fc5712daafa43648512c3497bdb86f",
        urls = ["https://github.com/bazelbuild/buildtools/releases/download/6.0.0/buildifier-windows-amd64.exe"],
    )
