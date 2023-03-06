def _gen_manifest_impl(ctx):
    out_file = ctx.actions.declare_file("LibraryAndroidManifest.xml")
    substitutions = {
        "@@MIN_SDK_VERSION@@": "%s" % ctx.attr.min_sdk_version,
        "@@TARGET_SDK_VERSION@@": "%s" % ctx.attr.target_sdk_version,
    }
    ctx.actions.expand_template(
        template = ctx.file._template,
        output = out_file,
        substitutions = substitutions,
    )
    return [DefaultInfo(files = depset([out_file]))]

gen_manifest = rule(
    implementation = _gen_manifest_impl,
    attrs = {
        "min_sdk_version": attr.int(mandatory = True),
        "target_sdk_version": attr.int(mandatory = True),
        "_template": attr.label(
            default = "//tools/android/internal/manifest:LibraryAndroidManifest.xml.tpl",
            allow_single_file = True,
        ),
    },
)

def transform_manifest(
        name,
        manifest,
        min_sdk_version,
        target_sdk_version):
    manifest_transformer = "//tools/android/manifest/internal:manifest_transformer"
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
