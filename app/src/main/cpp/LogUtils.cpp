//
// Created by $liancl on 2020/12/7 0007.
//
#include <string>
#include <jni.h>
#include "LogUtils.h"
logCallback _callback;
void* _impl;


void registerLogListener(logCallback callback, void* impl){
    _callback = callback;
    _impl = impl;
}
void showLog(const char *msg){
    _callback(1, msg, _impl);
}