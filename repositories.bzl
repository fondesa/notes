load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive", "http_file")

def setup_repositories():
    _repositories_android()
    _repositories_cc()
    _repositories_jvm()
    _repositories_kotlin()
    _repositories_python()
    _repositories_tools()

def _repositories_android():
    rules_android_version = "0.1.1"
    http_archive(
        name = "build_bazel_rules_android",
        url = "https://github.com/bazelbuild/rules_android/archive/v%s.zip" % rules_android_version,
        sha256 = "cd06d15dd8bb59926e4d65f9003bfc20f9da4b2519985c27e190cddc8b7a7806",
        strip_prefix = "rules_android-%s" % rules_android_version,
    )

    rules_android_ndk_commit = "81ec8b79dc50ee97e336a25724fdbb28e33b8d41"
    http_archive(
        name = "rules_android_ndk",
        url = "https://github.com/bazelbuild/rules_android_ndk/archive/%s.zip" % rules_android_ndk_commit,
        sha256 = "b29409496439cdcdb50a8e161c4953ca78a548e16d3ee729a1b5cd719ffdacbf",
        strip_prefix = "rules_android_ndk-%s" % rules_android_ndk_commit,
    )

def _repositories_cc():
    rules_cc_version = "0.0.4"
    http_archive(
        name = "rules_cc",
        url = "https://github.com/bazelbuild/rules_cc/releases/download/{}/rules_cc-{}.tar.gz".format(rules_cc_version, rules_cc_version),
        sha256 = "af6cc82d87db94585bceeda2561cb8a9d55ad435318ccb4ddfee18a43580fb5d",
        strip_prefix = "rules_cc-%s" % rules_cc_version,
    )
    sqlite_archive_id = "sqlite-amalgamation-3400100"
    http_archive(
        name = "org_sqlite",
        sha256 = "49112cc7328392aa4e3e5dae0b2f6736d0153430143d21f69327788ff4efe734",
        strip_prefix = sqlite_archive_id,
        url = "https://www.sqlite.org/2022/%s.zip" % sqlite_archive_id,
        build_file = "@//:third_party/sqlite.BUILD",
    )

    google_test_version = "1.13.0"
    http_archive(
        name = "com_github_googletest",
        sha256 = "ffa17fbc5953900994e2deec164bb8949879ea09b411e07f215bfbb1f87f4632",
        strip_prefix = "googletest-%s" % google_test_version,
        url = "https://github.com/google/googletest/archive/refs/tags/v%s.zip" % google_test_version,
    )

def _repositories_jvm():
    rules_java_version = "5.4.0"
    http_archive(
        name = "rules_java",
        url = "https://github.com/bazelbuild/rules_java/releases/download/{}/rules_java-{}.tar.gz"
            .format(rules_java_version, rules_java_version),
        sha256 = "9b87757af5c77e9db5f7c000579309afae75cf6517da745de01ba0c6e4870951",
    )
    rules_jvm_external_version = "4.5"
    http_archive(
        name = "rules_jvm_external",
        sha256 = "b17d7388feb9bfa7f2fa09031b32707df529f26c91ab9e5d909eb1676badd9a6",
        strip_prefix = "rules_jvm_external-%s" % rules_jvm_external_version,
        url = "https://github.com/bazelbuild/rules_jvm_external/archive/%s.zip" % rules_jvm_external_version,
    )
    dagger_version = "2.45"
    http_archive(
        name = "dagger",
        strip_prefix = "dagger-dagger-%s" % dagger_version,
        sha256 = "8f55f8b081a72835fed96be66dbfccb95ee2ceff092872397e5e639cccec2114",
        url = "https://github.com/google/dagger/archive/dagger-%s.zip" % dagger_version,
    )

def _repositories_kotlin():
    rules_kotlin_version = "1.7.1"
    http_archive(
        name = "rules_kotlin",
        sha256 = "fd92a98bd8a8f0e1cdcb490b93f5acef1f1727ed992571232d33de42395ca9b3",
        url = "https://github.com/bazelbuild/rules_kotlin/releases/download/v%s/rules_kotlin_release.tgz" % rules_kotlin_version,
    )

def _repositories_python():
    rules_python_version = "0.17.3"
    http_archive(
        name = "rules_python",
        sha256 = "8c15896f6686beb5c631a4459a3aa8392daccaab805ea899c9d14215074b60ef",
        strip_prefix = "rules_python-%s" % rules_python_version,
        url = "https://github.com/bazelbuild/rules_python/archive/refs/tags/%s.tar.gz" % rules_python_version,
    )

def _repositories_tools():
    skylib_version = "1.4.0"
    http_archive(
        name = "bazel_skylib",
        sha256 = "f24ab666394232f834f74d19e2ff142b0af17466ea0c69a3f4c276ee75f6efce",
        urls = [
            "https://mirror.bazel.build/github.com/bazelbuild/bazel-skylib/releases/download/{}/bazel-skylib-{}.tar.gz"
                .format(skylib_version, skylib_version),
            "https://github.com/bazelbuild/bazel-skylib/releases/download/{}/bazel-skylib-{}.tar.gz"
                .format(skylib_version, skylib_version),
        ],
    )
    buildifier_version = "6.0.0"
    http_file(
        name = "buildifier_linux_x86_64",
        downloaded_file_path = "buildifier",
        executable = True,
        sha256 = "7ff82176879c0c13bc682b6b0e482d670fbe13bbb20e07915edb0ad11be50502",
        url = "https://github.com/bazelbuild/buildtools/releases/download/%s/buildifier-linux-amd64" % buildifier_version,
    )
    http_file(
        name = "buildifier_macos_arm64",
        downloaded_file_path = "buildifier",
        executable = True,
        sha256 = "21fa0d48ef0b7251eb6e3521cbe25d1e52404763cd2a43aa29f69b5380559dd1",
        url = "https://github.com/bazelbuild/buildtools/releases/download/%s/buildifier-darwin-arm64" % buildifier_version,
    )
    http_file(
        name = "buildifier_macos_x86_64",
        downloaded_file_path = "buildifier",
        executable = True,
        sha256 = "3f8ab7dd5d5946ce44695f29c3b895ad11a9a6776c247ad5273e9c8480216ae1",
        url = "https://github.com/bazelbuild/buildtools/releases/download/%s/buildifier-darwin-amd64" % buildifier_version,
    )
    http_file(
        name = "buildifier_windows_x86_64",
        downloaded_file_path = "buildifier.exe",
        executable = True,
        sha256 = "b5da47fb9746f3966eed4920fac9325ef7fc5712daafa43648512c3497bdb86f",
        url = "https://github.com/bazelbuild/buildtools/releases/download/%s/buildifier-windows-amd64.exe" % buildifier_version,
    )
