package com.fondesa.notes.cli

import com.fondesa.notes.core.SampleBind
import com.fondesa.notes.core.notes.NotesInteractor
import com.fondesa.notes.core.notes.internal.NativeNotesInteractor

fun main(args: Array<String>) {
    System.loadLibrary("app_native")

    val interactor: NotesInteractor = NativeNotesInteractor()
    val draft = interactor.getDraft()
    println("Draft title: ${draft?.title}, desc: ${draft?.description}")

    val bind = SampleBind()
    println("CLI app init ${bind.fooFromJNI()}")
}