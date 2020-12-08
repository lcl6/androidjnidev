package com.example.androidjnidev.nativetest;

import com.example.androidjnidev.NativeListener;

/**
 * Created by liancl on 2020/12/7 0007.
 */

public class JNITest {
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
}
