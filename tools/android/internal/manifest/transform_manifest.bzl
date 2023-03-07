def transform_manifest(
        name,
        manifest,
        min_sdk_version,
        target_sdk_version):
    manifest_transformer = "//tools/android/internal/manifest:manifest_transformer"
    manifest_transformer_cmd = " ".join([
        "$(location {})".format(manifest_transformer),
        "--input",
        "$(location {})".format(manifest),
        "--output",
        "$(OUTS)",
        "--min-sdk",
        "%s" % min_sdk_version,
        "--target-sdk",
        "%s" % target_sdk_version,
    ])
    return native.genrule(
        name = name,
        srcs = [manifest],
        outs = ["AndroidManifestTransformed.xml"],
        cmd = manifest_transformer_cmd,
        tools = [manifest_transformer],
    )
