# Notes - monorepo

_Important: the work on this repo just started so EVERYTHING is in progress_

The final aim of this project is to demonstrate how to manage and maintain a monorepo supporting multiple host platforms, cross-compiling for other target platforms using multiple languages.

Obviously this kind of tools are not needed at all to create few apps to create notes. This repo **aims** to be over-engineered to demonstrate how to handle a similar environment at scale, with a strong focus on the build tools, performances, CI.

## Apps

When completed, this monorepo aims to build all the following apps.

- Android → Kotlin
- iOS → Swift
- CLI → Kotlin
- Desktop → probably C++ ??

All these apps will share the same `core`, entirely written in C++ (maybe partially with Rust in future).

## Build system

This monorepo is entirely built with [Bazel](https://bazel.build/).

On the build tools side, the following languages are used:
- Starlark → 99% of the build-related files, since it's the official language for Bazel
- Python → some non-trivial implementations of Bazel genrules (e.g. Android manifest manipulation)
- Shell → some trivial implementations of Bazel genrules (e.g. linters invocation)

## Commands

Values of `<host-os>`:
- linux_x86_64
- macos_x86_64
- macos_arm64
- windows_x86_64

Values of `<android-target>`:
- android_arm
- android_arm64
- android_x86
- android_x86_64


#### Build the apps

```shell
bazel build //apps:cli --config=<host-os>

bazel build //apps:android --config=<android-target>
```

#### Run the apps

```shell
bazel run //apps:cli --config=<your-host-os>

bazel mobile-install //apps:android --config=<android-target> --start_app
```

### Prerequisites

- Bazel 6.x installed (recommended [Bazelisk](https://github.com/bazelbuild/bazelisk) so the version will be handled automatically)
- One of the following hosts:
    - Linux x86_64
    - macOS x86_64
    - macOS arm64 (M1, M2)
    - Windows x86_64 (not tested at all ATM)

- C++ compiler supporting C++17
- `JAVA_HOME` set to a valid JDK >= 8
- `ANDROID_HOME` set to the Android SDKs location
- `ANDROID_NDK_HOME` set to the Android NDKs location
