package com.fondesa.notes.core;

import com.github.fmeum.rules_jni.RulesJni;

public class SampleBind {
    static {
        RulesJni.loadLibrary("jni_exports_sample_bind", SampleBind.class);
    }

    public native int fooFromJNI();
}
