package com.fondesa.notes.android.app

import android.app.Application

class AndroidApp : Application() {
    companion object {
        init {
            System.loadLibrary("app")
        }
    }
}