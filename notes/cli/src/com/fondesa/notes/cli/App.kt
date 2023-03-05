package com.fondesa.notes.cli

import com.fondesa.notes.core.SampleBind

fun main(args: Array<String>) {
    System.loadLibrary("app_native")

    val bind = SampleBind()
    println("CLI app init ${bind.fooFromJNI()}")
}