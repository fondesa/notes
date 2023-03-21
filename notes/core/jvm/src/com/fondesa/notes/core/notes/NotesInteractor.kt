package com.fondesa.notes.core.notes

interface NotesInteractor {
    fun getDraft(): Draft?

    fun dispose()
}