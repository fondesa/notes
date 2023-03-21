package com.fondesa.notes.cli

import com.fondesa.notes.core.notes.NotesInteractor
import com.fondesa.notes.core.notes.internal.NativeNotesInteractor

object CliApp {
    init {
        System.loadLibrary("app_native")
    }

    @JvmStatic
    fun main(args: Array<String>) {
        val interactor: NotesInteractor = NativeNotesInteractor()
        val draft = interactor.getDraft()
        println("Draft title: ${draft?.title}, desc: ${draft?.description}")
    }
}