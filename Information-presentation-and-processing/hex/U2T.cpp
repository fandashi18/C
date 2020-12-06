//
//  U2T.cpp
//  Information presentation and processing
//
//  Created by 樊明杨 on 2020/9/30.
//  Copyright © 2020 樊明杨. All rights reserved.
//

#include "U2T.hpp"

signed long U2T(unsigned long u,unsigned int bitCount){
    using namespace std;
    //1.检查输入
    if (bitCount <= 0 || bitCount >= 65) {
        cout << "错误：位个数范围必须是[1,64]" << endl;
        return 0;
    }
    
    unsigned long uMax = (1 << bitCount) - 1;
    if (u > uMax) {
        cout << "错误：位数量不足以表示" << u << endl;
        return 0;
    }
    
    signed long tResult = u;
    
    //2.判断最高位是否为1
    unsigned long halfUMax = 1 << (bitCount - 1);
    if (u >= halfUMax) {
        tResult -= (1 << bitCount);
    }
    
    return tResult;
}
