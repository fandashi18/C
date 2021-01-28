#include "com_fmy_App.h"

JNIEXPORT jint JNICALL Java_com_fmy_App_add(JNIEnv * env, jobject jo, jint x, jint y){
    return x + y;
}