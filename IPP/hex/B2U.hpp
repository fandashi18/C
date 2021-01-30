//
//  B2U.hpp
//  Information presentation and processing
//
//  Created by 樊明杨 on 2020/9/30.
//  Copyright © 2020 樊明杨. All rights reserved.
//

#ifndef B2U_hpp
#define B2U_hpp

#include <iostream>

/*
 * 以无符号的方式解释二进制数字。
 * 程序设计会尽可能地避免使用乘法或除法，因为即使是英特尔I7处理器，乘法或除法的也需要3个时钟周期，而移位或加法只需要1个时钟周期。
 * 第一个参数代表二进制数字，格式为字符序列。
 * 第二个参数代表字符序列中的字符个数。受通用目的寄存器的限制，在64位计算机中不可以超过64。
 * 返回值是无符号长整数，64位计算机中占64个位。
 */
unsigned long B2U(char const *, int count);

#endif /* B2U_hpp */
