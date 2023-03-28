package com.fondesa.notes.cli

object CliApp {
    init {
        System.loadLibrary("app_native")
    }

    @JvmStatic
    fun main(args: Array<String>) {
        val appComponent = CliAppComponent.create()
        val interactor = appComponent.interactor()
        val draft = interactor.getDraft()
        println("Draft title: ${draft?.title}, desc: ${draft?.description}")
    }
}