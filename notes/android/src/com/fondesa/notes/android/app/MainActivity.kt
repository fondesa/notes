package com.fondesa.notes.android.app

import android.app.Activity
import android.os.Bundle
import android.util.Log
//import com.fondesa.notes.core.SampleBind

class MainActivity : Activity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)
//        val fooFromJni = SampleBind().fooFromJNI()
//        Log.d("LYRA", "foo: $fooFromJni")
    }
}