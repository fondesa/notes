load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive", "http_file")

def setup_repositories():
    _repositories_jvm()
    _repositories_tools()

def _repositories_jvm():
    rules_jvm_external_version = "4.5"
    http_archive(
        name = "rules_jvm_external",
        sha256 = "b17d7388feb9bfa7f2fa09031b32707df529f26c91ab9e5d909eb1676badd9a6",
        strip_prefix = "rules_jvm_external-%s" % rules_jvm_external_version,
        url = "https://github.com/bazelbuild/rules_jvm_external/archive/%s.zip" % rules_jvm_external_version,
    )

def _repositories_tools():
    http_file(
        name = "buildifier_linux",
        downloaded_file_path = "buildifier",
        executable = True,
        sha256 = "7ff82176879c0c13bc682b6b0e482d670fbe13bbb20e07915edb0ad11be50502",
        urls = ["https://github.com/bazelbuild/buildtools/releases/download/6.0.0/buildifier-linux-amd64"],
    )
    http_file(
        name = "buildifier_macos_arm",
        downloaded_file_path = "buildifier",
        executable = True,
        sha256 = "21fa0d48ef0b7251eb6e3521cbe25d1e52404763cd2a43aa29f69b5380559dd1",
        urls = ["https://github.com/bazelbuild/buildtools/releases/download/6.0.0/buildifier-darwin-arm64"],
    )
    http_file(
        name = "buildifier_macos_intel",
        downloaded_file_path = "buildifier",
        executable = True,
        sha256 = "3f8ab7dd5d5946ce44695f29c3b895ad11a9a6776c247ad5273e9c8480216ae1",
        urls = ["https://github.com/bazelbuild/buildtools/releases/download/6.0.0/buildifier-darwin-amd64"],
    )
    http_file(
        name = "buildifier_windows",
        downloaded_file_path = "buildifier.exe",
        executable = True,
        sha256 = "b5da47fb9746f3966eed4920fac9325ef7fc5712daafa43648512c3497bdb86f",
        urls = ["https://github.com/bazelbuild/buildtools/releases/download/6.0.0/buildifier-windows"],
    )
