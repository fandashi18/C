#include <iostream>
#include "insert/Straight.h"
#include "insert/Bin.h"
#include "insert/Shell.h"
#include "swap/Bubble.h"

using namespace std;

int main() {
    const int MAX_SIZE = 5;
    int iArr[MAX_SIZE] = {13,21,13,8,71};
    straightInsSort(iArr, MAX_SIZE);
    binSort(iArr, MAX_SIZE);
    int dArr[2] = {2, 1};
    shellSort(iArr, 5, dArr, 2);
    bubbleSort(iArr, 5);

    for (int i = 0; i < MAX_SIZE; ++i) {
        cout << iArr[i] << ",";
    }
    cout << endl;

    return 0;
}
