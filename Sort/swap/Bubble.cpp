//
// Created by fanmingyang on 2020/11/22.
//

#include "Bubble.h"
#include <stddef.h>

void bubbleSort(int iArr[], int length) {
    if (iArr == NULL || length <= 1) {
        return;
    }

    static bool change = true;
    static int copy;
    for (static int i = 0; i < length - 1 && change; ++i) {
        change = false;

        for (int j = 0; j < length - 2 - i; ++j) {
            if (iArr[j] > iArr[j + 1]) {
                change = true;
                copy = iArr[j];
                iArr[j] = iArr[j + 1];
                iArr[j + 1] = copy;
            }
        }

    }
}