package com.fondesa.notes.android.app

import android.app.Activity
import android.os.Bundle
import android.util.Log
import com.fondesa.notes.core.notes.NotesInteractor
import com.fondesa.notes.core.notes.internal.NativeNotesInteractor

class MainActivity : Activity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        val interactor: NotesInteractor = NativeNotesInteractor()
        val draft = interactor.getDraft()
        Log.d("LYRA", "Draft title: ${draft?.title}, desc: ${draft?.description}")
    }
}