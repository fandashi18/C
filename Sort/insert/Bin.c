//
// Created by fanmingyang on 2020/11/17.
//

#include "Bin.h"
#include <stddef.h>

void binSort(int iArr[], int size) {
    if (iArr == NULL || size <= 1) {
        return;
    }

    static int low = 0, mid, high, insElement;
    for (int i = 1; i < size; ++i) {
        high = i - 1;
        insElement = iArr[i];

        while (low <= high) {
            mid = (low + high) / 2;
            if (insElement < iArr[mid]) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        for (int j = i - 1; j >= low; --j) {
            iArr[j + 1] = iArr[j];
        }

        iArr[low] = insElement;
    }
}