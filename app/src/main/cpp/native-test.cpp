#include <jni.h>
#include <string>
#include <iostream>
#include "NativeLearn.h"
#include "LogUtils.h"
#include <android/log.h>
#define LOG_TAG "cqEmbed"
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO,LOG_TAG,__VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR,LOG_TAG,__VA_ARGS__)
class NativeListenerImpl{

public:
    void init() {
        _class = _env->GetObjectClass(_listener);//获取jclass (NativeListener)
        _showLogMethodID = _env->GetMethodID(_class, "showLog", "(ILjava/lang/String;)V");//获取NativeListener 的showLog 方法id   "(ILjava/lang/String;)V"表示签名  b表示返回void 类型
    }

    NativeListenerImpl(JNIEnv* env, jobject listener){
        _listener = env->NewGlobalRef(listener);
        _env = env;
        init();
    }

    void onLog(int level, const char* logMsg){
        _env->CallVoidMethod(_listener, _showLogMethodID, level, _env->NewStringUTF(logMsg));//调用方法id 的方法
    }


private:
    jobject _listener;
    JNIEnv* _env;
    jmethodID  _showLogMethodID;
    jclass _class;
};


void OnLogListerCallBack(int severity, const char *log,void* userData){
    NativeListenerImpl* logger = (NativeListenerImpl*)userData;
    logger->onLog(severity,log);
}

extern "C"
JNIEXPORT void JNICALL
Java_com_example_androidjnidev_nativetest_JNITest_init(JNIEnv *env, jclass clazz, jstring cofig) {
    const char *config = env->GetStringUTFChars(cofig, 0);
    NativeInit(std::string(config));
    env->ReleaseStringUTFChars(cofig, config);
}
extern "C"
JNIEXPORT void JNICALL
Java_com_example_androidjnidev_nativetest_JNITest_registerListener(JNIEnv *env, jclass clazz,
                                                                   jobject listener) {
    NativeListenerImpl* impl = new NativeListenerImpl(env, listener);
    registerLogListener(OnLogListerCallBack, impl);
}

extern "C"
JNIEXPORT void JNICALL
Java_com_example_androidjnidev_nativetest_JNITest_sayHello(JNIEnv *env, jobject jobje) {

    //找到这个类
   jclass  jclas=env->GetObjectClass(jobje);
   jfieldID  jid=env->GetFieldID(jclas, "number", "I");
   jint  jnum=env->GetIntField(jobje,jid);
    LOGI("jnum=%d",jnum);
    env->SetIntField(jobje,jid,100L);

}extern "C"
JNIEXPORT void JNICALL
Java_com_example_androidjnidev_nativetest_JNITest_jniCallJava(JNIEnv *env, jobject thiz) {
   jclass  jclass1=env->GetObjectClass(thiz);
   jmethodID  jmethodId=env->GetMethodID(jclass1,"maxValue", "(DD)D");
   jdouble  jdouble1=env->CallDoubleMethod(thiz,jmethodId,2.3,4.6);
    LOGE("jdouble1= %f",jdouble1);

}