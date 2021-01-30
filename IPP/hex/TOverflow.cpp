//
//  TOverflow.cpp
//  Information presentation and processing
//
//  Created by 樊明杨 on 2020/9/30.
//  Copyright © 2020 樊明杨. All rights reserved.
//

#include "TOverflow.hpp"

int tlAddOk(signed long x,signed long y){
    signed long sum = x + y;
    if (x >0 && y > 0 && sum <= -2) {
        return 1;
    }
    
    if (x < 0 && y < 0 && sum >=0) {
        return -1;
    }
    
    return 0;
}

int tiAddOk(signed int x,signed int y){
    signed int sum = x + y;
    if (x > 0 && y > 0 && sum <= -2) {
        return 1;
    }
    
    if (x < 0 && y < 0 && sum >=0) {
        return -1;
    }
    
    return 0;
}
