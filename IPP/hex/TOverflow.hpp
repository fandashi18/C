//
//  TOverflow.hpp
//  Information presentation and processing
//
//  Created by 樊明杨 on 2020/9/30.
//  Copyright © 2020 樊明杨. All rights reserved.
//
// 判断两个补码数字相加是否会产生溢出。

/*
 * 不可以用减法来证明加法是否会溢出，因为补码加法运算满足交换律和结合律（实际上存在阿贝尔群）。
 * 即 x + y - x = x - x + y，
 * 设 s = x + y，
 * 则
 * s - x = y
 * 在任何情况下（无论补码加法是否算术溢出）都成立！
 
 * 正确的思想：
 * 根据补码加法运算的特性，正溢出时，值小于等于-2，负溢出时，值大于等于0即可判断。
 * 从这个角度，可以发现 -1 是非常特殊的一个补码数值，因为它充当了补码加法溢出的边界。
 */

#ifndef TOverflow_hpp
#define TOverflow_hpp

#include <iostream>

/*
 * 正溢出返回1，正常返回0，负溢出返回-1。
 */
int tlAddOk(signed long,signed long);

int tiAddOk(signed int,signed int);
#endif /* TOverflow_hpp */
