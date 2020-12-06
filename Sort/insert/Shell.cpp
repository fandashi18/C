//
// Created by fanmingyang on 2020/11/22.
//

#include "Shell.h"
#include <stddef.h>
#include <iostream>
#include "Straight.h"

void shellSort(int iArr[], int length, int dArr[], int deltaLength) {
    using namespace std;

    if (iArr == NULL || length <= 1 || dArr == NULL || deltaLength <= 0) {
        return;
    }

    if (dArr[deltaLength - 1] != 1) {
        cout << "The last element of delta array must be 1" << endl;
        return;
    }

    for (int i = 0; i < deltaLength; ++i) {
        straightInsSort(iArr, length, dArr[i]);
    }
}
