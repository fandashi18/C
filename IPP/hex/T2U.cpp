//
//  T2U.cpp
//  Information presentation and processing
//
//  Created by 樊明杨 on 2020/9/30.
//  Copyright © 2020 樊明杨. All rights reserved.
//

#include "T2U.hpp"

unsigned long T2U(signed long t,int bitCount){
    using namespace std;
    //1.检查输入
    if (bitCount <= 0 || bitCount >= 65) {
        cout << "错误：位个数范围必须是[1,64]" << endl;
        return 0;
    }
    
    signed long tMin = ~(1 << (bitCount - 1)) + 1;
    signed long tMax = ~tMin;
    
    if (t < tMin || t > tMax) {
        cout << "错误：位数量是" << bitCount << "，故补码数字正确范围是[" << tMin << "," << tMax << "]" << endl;
        return 0;
    }
    
    unsigned long uResult = t;
    if (t < 0) {
        uResult += (1 << bitCount);
    }
    return uResult;
}
