//
// Created by fanmingyang on 2020/11/22.
//

#include <stddef.h>
#include <stdio.h>
#include "Shell.h"
#include "Straight.h"

void shellSort(int iArr[], int length, int dArr[], int deltaLength) {

    if (iArr == NULL || length <= 1 || dArr == NULL || deltaLength <= 0) {
        return;
    }

    if (dArr[deltaLength - 1] != 1) {
        printf("The last element of delta array must be 1\n");
        return;
    }

    for (int i = 0; i < deltaLength; ++i) {
        straightInsSortByDelta(iArr, length, dArr[i]);
    }
}
