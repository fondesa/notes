package com.fondesa.notes.cli

import com.fondesa.notes.core.di.CoreModule
import com.fondesa.notes.core.notes.NotesInteractor
import dagger.Component
import javax.inject.Singleton

@Singleton
@Component(
    modules = [
        CoreModule::class
    ]
)
interface CliAppComponent {
    fun interactor(): NotesInteractor

    companion object {
        fun create(): CliAppComponent = DaggerCliAppComponent.create()
    }
}