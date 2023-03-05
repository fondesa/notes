def _gen_java_class(ctx):
    java_class_name = ctx.attr.java_class_name
    file_name = "%s.java" % java_class_name
    out_file = ctx.actions.declare_file(file_name)
    substitutions = {
        "@@NAME@@": java_class_name,
    }
    ctx.actions.expand_template(
        template = ctx.file._template,
        output = out_file,
        substitutions = substitutions,
    )
    return [DefaultInfo(files = depset([out_file]))]

gen_java_class = rule(
    implementation = _gen_java_class,
    attrs = {
        "java_class_name": attr.string(mandatory = True),
        "_template": attr.label(
            default = "//tools/jvm/internal:GeneratedJavaClass.java.tpl",
            allow_single_file = True,
        ),
    },
)
