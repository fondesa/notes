package com.fondesa.notes.core.notes.di

import com.fondesa.notes.core.notes.NotesInteractor
import com.fondesa.notes.core.notes.internal.NativeNotesInteractor
import dagger.Binds
import dagger.Module

@Module
interface NotesCoreModule {
    @Binds
    fun notesInteractor(interactor: NativeNotesInteractor): NotesInteractor
}