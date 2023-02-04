load("@bazel_skylib//lib:shell.bzl", "shell")

_MODE_CHECK = "check"
_MODE_FIX = "fix"

def _buildifier_impl(ctx):
    args = [
        "-mode=%s" % ctx.attr.mode,
        # Use native rules for Android.
        "--warnings=-native-android",
    ]

    if ctx.attr.mode == _MODE_CHECK:
        args.append("-lint=warn")
    elif ctx.attr.mode == _MODE_FIX:
        args.append("-lint=fix")
    else:
        fail("Buildifier: attr mode `%s` not recognized" % ctx.attr.mode)

    out_file = ctx.actions.declare_file("%s.sh" % ctx.label.name)
    substitutions = {
        "@@ARGS@@": shell.array_literal(args),
        "@@BUILDIFIER_LINK_PATH@@": shell.quote(ctx.executable.buildifier.short_path),
    }
    ctx.actions.expand_template(
        template = ctx.file._template,
        output = out_file,
        substitutions = substitutions,
        is_executable = True,
    )
    return [
        DefaultInfo(
            files = depset([out_file]),
            runfiles = ctx.runfiles(files = [ctx.executable.buildifier]),
            executable = out_file,
        ),
    ]

buildifier = rule(
    implementation = _buildifier_impl,
    attrs = {
        "buildifier": attr.label(
            default = "//tools/linters/buildifier:buildifier",
            cfg = "exec",
            executable = True,
        ),
        "mode": attr.string(
            mandatory = True,
            values = [_MODE_CHECK, _MODE_FIX],
        ),
        "_template": attr.label(
            default = "//tools/linters/buildifier:buildifier.sh.tpl",
            allow_single_file = True,
        ),
    },
    executable = True,
)
