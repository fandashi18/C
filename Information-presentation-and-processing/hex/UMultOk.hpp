//
//  UMultOk.hpp
//  Information presentation and processing
//
//  Created by 樊明杨 on 2020/10/3.
//  Copyright © 2020 樊明杨. All rights reserved.
//
// 判断无符号整数乘法是否溢出。

/*
 * 整数乘法在以往的机器中需要10个或更多的时钟周期，在酷睿I7四代中也需要3个时钟周期。
 * 因此，编译期会尝试将乘法转换为加法和移位，因为它们每次只消耗1个时钟周期。但是，移位和加法也有可能需要比乘法更多的时钟周期。
 * 二进制乘法的运算规则与十进制类似，但是最后必须截断为数据类型所占有的位。
 *
 * 乘法中的特殊情况是，若一个数字x乘以数字K，而K恰好是2的k次方。则此时的乘法结果与 x << k 的结果相同（即使溢出）。
 */

#ifndef UMultOk_hpp
#define UMultOk_hpp

#include <iostream>
#include <cstdint>

//无溢出则返回0，溢出则返回-1.
int uiMultOk(unsigned int,unsigned int);

#endif /* UMultOk_hpp */
