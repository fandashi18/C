//
//  UOverflow.hpp
//  Information presentation and processing
//
//  Created by 樊明杨 on 2020/9/30.
//  Copyright © 2020 樊明杨. All rights reserved.
//

#ifndef UOverflow_hpp
#define UOverflow_hpp

#include <iostream>

/*
 * 判断无符号加法是否（正）溢出。
 * 输入的无符号数字会被转换为unsigned long（高位补0）。
 * 若溢出，则返回-1。否则，返回0。
 */
int ulAddOk(unsigned long ,unsigned long);

int uiAddOk(unsigned int , unsigned int);

#endif /* UOverflow_hpp */
