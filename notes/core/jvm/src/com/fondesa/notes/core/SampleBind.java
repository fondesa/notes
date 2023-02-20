package com.fondesa.notes.core;

public class SampleBind {
    static {
        System.loadLibrary("jni_sample_bind");
    }

    public native int fooFromJNI();
}
