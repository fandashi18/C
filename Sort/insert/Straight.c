//
// Created by fanmingyang on 2020/11/17.
//
#include "Straight.h"
#include <stddef.h>

void straightInsSort(int iArr[], int size) {
    if (iArr == NULL || size <= 1) {
        return;
    }

    straightInsSortByDelta(iArr, size, 1);
}

void straightInsSortByDelta(int iArr[], int size, int delta) {
    if (iArr == NULL || size <= 1 || delta < 1) {
        return;
    }

    static int insElement,j;
    for (int i = delta; i < size; ++i) {
        insElement = iArr[i];
        j = i - delta;
        while (j >= 0) {
            if (insElement < iArr[j]) {
                iArr[j + delta] = iArr[j];
                j -= delta;
            } else {
                break;
            }
        }
        iArr[j + delta] = insElement;
    }
}
