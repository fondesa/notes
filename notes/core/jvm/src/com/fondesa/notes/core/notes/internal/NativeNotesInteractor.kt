package com.fondesa.notes.core.notes.internal

import com.fondesa.notes.core.notes.Draft
import com.fondesa.notes.core.notes.NotesInteractor

// TODO make internal
class NativeNotesInteractor : NotesInteractor {
    private val address: Long by lazy { nativeAddress() }

    override fun getDraft(): Draft? = getDraft(address)

    override fun dispose() = dispose(address)

    private external fun getDraft(address: Long): Draft?

    private external fun nativeAddress(): Long

    private external fun dispose(address: Long)
}