load("@rules_python//python:defs.bzl", "py_binary")

exports_files(["LibraryAndroidManifest.xml.tpl"])

py_binary(
    name = "manifest_transformer",
    srcs = ["manifest_transformer.py"],
    main = "manifest_transformer.py",
    visibility = ["//visibility:public"],
)
