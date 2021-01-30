//
//  TMultOk.hpp
//  Information presentation and processing
//
//  Created by 樊明杨 on 2020/10/1.
//  Copyright © 2020 樊明杨. All rights reserved.
//
// 判断两个数字相乘是否会溢出。若溢出，则返回-1。否则，返回0。

/*
 * UMultOk中对乘法的阐述同样适用于补码乘法。
 */

/*
 * 思路一：
 * 虽然不可以用减法来证明加法是否溢出，但是可以用除法来证明乘法是否溢出。
 * 具体的推导过程：
 * 假设有补码算术运算 x · y ，设补码运算结果为p。
 * 为了表示2·w个位的补码数字，设低w个位的无符号表示为u，高w位的补码表示为v·2^w。
 * 则
 * x · y = u + v·2^w
 * 根据除法运算定义，有
 * p = x · q + r
 * 补码运算的结果p是不变的，故用p来替换上述表达式中的u
 * T2U(p) = p + p_{w_1} · 2^w
 * x · y = p + p_{w_1} · 2^w + v·2^w
 * 设 t = p_{w_1} + v
 * 故
 * x · y = p + t * 2^w
 * 故
 * p = x · y - t * 2^w
 * p = x · q + r
 * 因此
 * 当y = q时，有 t = r = 0时，t = 0则代表无算术溢出。
 * 当y != q时，有 t != 0，故存在算术溢出。
 */

#ifndef TMultOk_hpp
#define TMultOk_hpp

#include <iostream>
#include <cstdint>

//无溢出则返回0，溢出则返回-1.
int tlMultOk(signed long,signed long);

int tiMultOk(signed int,signed int);

/*
 * 思路二：
 * 针对int为32位的情况，使用int64_t来判断补码乘法是否溢出。
 */
int ti32MultOk(signed int,signed int);

#endif /* TMultOk_hpp */
