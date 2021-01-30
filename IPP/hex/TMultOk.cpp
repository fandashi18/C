//
//  TMultOk.cpp
//  Information presentation and processing
//
//  Created by 樊明杨 on 2020/10/1.
//  Copyright © 2020 樊明杨. All rights reserved.
//

#include "TMultOk.hpp"

int tlMultOk(signed long x,signed long y){
    signed long p = x * y;
    if (x == 0 || p/x == y) {
        return 0;
    }
    return -1;
}

int tiMultOk(signed int x,signed int y){
    signed int p = x * y;
    if (x == 0 || p/x == y) {
        return 0;
    }
    return -1;
}

int ti32MultOk(signed int x,signed int y){
    //这里注意，必须先强制类型转换为64位，再进行乘法。从机器的角度说明：数据的长度决定了采用机器指令imulq或imull，从而决定了是否存储完整的64位运算结果。
    int64_t p = (int64_t)x * (int64_t)y;
    if (p == (int32_t)p) {
        return 0;
    }
    return -1;
}
