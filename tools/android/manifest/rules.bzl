def _library_manifest_impl(ctx):
    out_file = ctx.actions.declare_file("LibraryAndroidManifest.xml")
    substitutions = {
        "@@MIN_SDK_VERSION@@": "21",
        "@@TARGET_SDK_VERSION@@": "29",
    }
    ctx.actions.expand_template(
        template = ctx.file._template,
        output = out_file,
        substitutions = substitutions,
    )
    return [DefaultInfo(files = depset([out_file]))]

library_manifest = rule(
    implementation = _library_manifest_impl,
    attrs = {
        "_template": attr.label(
            default = "//tools/android/manifest:LibraryAndroidManifest.xml.tpl",
            allow_single_file = True,
        ),
    },
)
