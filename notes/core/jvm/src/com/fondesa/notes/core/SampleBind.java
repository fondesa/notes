package com.fondesa.notes.core;

public class SampleBind {
    static {
        System.loadLibrary("sample_bind");
    }

    public native int fooFromJNI();
}
