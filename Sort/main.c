#include <stdio.h>
#include "insert/Straight.h"
#include "insert/Bin.h"
#include "insert/Shell.h"
#include "swap/Bubble.h"
#include "swap/Quck.h"

static const int MAX_SIZE = 5;

int main() {
    int iArr[5] = {11,-1,0,14,-3};
    // straightInsSort(iArr, MAX_SIZE);
    // binSort(iArr, MAX_SIZE);
    // int dArr[2] = {2, 1};
    // shellSort(iArr, 5, dArr, 2);
    // bubbleSort(iArr, 5);
    quckSort(iArr,0,4);
    for (int i = 0; i < MAX_SIZE; ++i) {
        fprintf(stdout,"%d,",iArr[i]);
    }
    fprintf(stdout,"\n");

    return 0;
}
