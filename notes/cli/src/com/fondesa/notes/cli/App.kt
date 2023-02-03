package com.fondesa.notes.cli

import com.fondesa.notes.core.SampleBind

fun main(args: Array<String>) {
    val bind = SampleBind()
    println("CLI app init ${bind.fooFromJNI()}")
}