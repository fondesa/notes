package com.fondesa.notes.core.di

import com.fondesa.notes.core.notes.di.NotesCoreModule
import dagger.Module

@Module(includes = [NotesCoreModule::class])
interface CoreModule