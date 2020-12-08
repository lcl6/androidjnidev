package com.example.androidjnidev

import android.os.Bundle
import android.util.Log
import androidx.appcompat.app.AppCompatActivity
import com.example.androidjnidev.nativetest.JNITest

class MainActivity : AppCompatActivity()  , NativeListener {

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        // Example of a call to a native method
//        sample_text.text = stringFromJNI()
        JNITest.registerListener(this)
        JNITest.init("asdasda")
        val jniTest = JNITest()
//        jniTest.sayHello()
//        println(jniTest.number.toString() + "")
        //
        jniTest.jniCallJava()//jni 调用java

    }
    override fun showLog(level: Int, msg: String?) {
        msg?.let { Log.i("MainActivity", it) };
    }

}

