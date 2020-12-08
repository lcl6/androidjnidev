package com.example.androidjnidev.nativetest;

import com.example.androidjnidev.NativeListener;

/**
 * Created by liancl on 2020/12/7 0007.
 */

public class JNITest {
    public  int number = 10;//定义一个属性
    static {
        try{
            System.loadLibrary("native-test");
        }catch (Exception e){
            e.printStackTrace();
        }
    }
    public static native void init(String cofig);
    /**
     * java注册C++的回调接口
     * @param listener
     */
    public static native void registerListener(NativeListener listener);

    public  native void sayHello();


    //jni 调用 java
    public native void jniCallJava();

    public double maxValue(double d1,double d2){
        return Math.max(d1, d2);
    }
}
