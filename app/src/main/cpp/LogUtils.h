//
// Created by $liancl on 2020/12/7 0007.
//

#ifndef ANDROIDJNIDEV_LOGUTILS_H
#define ANDROIDJNIDEV_LOGUTILS_H

typedef void (*logCallback)(int , const char *,void *userData);

extern void registerLogListener(logCallback callback, void* impl);

void showLog(const char *msg);

#endif //ANDROIDJNIDEV_LOGUTILS_H
