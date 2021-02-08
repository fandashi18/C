#include "fmy-string.h"
#include <string.h>

/**
 * 将输入字符串对称翻转。
 */ 
void myreverse(char *s){
    if (s == NULL) {
        return;
    }

    int len = strlen(s);

    if (len <= 1) {
        return;
    }

    int mid = len / 2;
    char assist;
    for (int i = 0; i < mid; ++i) {
        assist = s[i];
        s[i] = s[len - i - 1];
        s[len - i - 1] = assist;
    }
}