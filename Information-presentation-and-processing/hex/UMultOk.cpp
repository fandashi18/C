//
//  UMultOk.cpp
//  Information presentation and processing
//
//  Created by 樊明杨 on 2020/10/3.
//  Copyright © 2020 樊明杨. All rights reserved.
//

#include "UMultOk.hpp"

int uiMultOk(unsigned int x,unsigned int y){
    int64_t p = (u_int64_t) x * (u_int64_t)y;
    if (p == (unsigned int)p) {
        return 0;
    }
    return -1;
}
