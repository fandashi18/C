#include "Quck.h"
#include <stddef.h>
#include <stdio.h>

void quckSort(int iArr[], int low, int high)
{

    // 1. 确保输入合法
    if (iArr == NULL || low < 0 || high < 0 || low >= high)
    {
        fprintf(stderr, "arguement error");
        return;
    }

    // 备份本次排序的右边界，左边界永远为0
    int highCopy = high;

    // 2. 选择枢轴元素。策略可采用其他。
    int pivot = iArr[low];

    while (low < high)
    {
        // 3. 从右往左扫描
        while (low < high)
        {
            if (iArr[high] < pivot)
            {
                iArr[low] = iArr[high];
                break;
            }
            high--;
        }

        // 4. 从左往右扫描
        while (low < high)
        {
            if (iArr[low] >= pivot)
            {
                iArr[high] = iArr[low];
                break;
            }
            low++;
        }
    }

    // 4. 已找到枢轴元素的位置，故存放枢轴元素
    iArr[low] = pivot;

    // 5. 对左表排序
    if (low > 1)
    {
        quckSort(iArr, 0, low - 1);
    }

    // 6. 对右表排序
    if (low < highCopy - 1)
    {
        quckSort(iArr,low + 1,highCopy);
    }
    
}