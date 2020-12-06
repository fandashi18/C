//
//  UOverflow.cpp
//  Information presentation and processing
//
//  Created by 樊明杨 on 2020/9/30.
//  Copyright © 2020 樊明杨. All rights reserved.
//

#include "UOverflow.hpp"

int ulAddOk(unsigned long x,unsigned long y){
    if (x + y < x) {
        return -1;
    }else {
        return 0;
    }
}

int uiAddOk(unsigned int x, unsigned int y){
    if (x + y < x) {
        return -1;
    }else {
        return 0;
    }
}
