//
//  U2T.hpp
//  Information presentation and processing
//
//  Created by 樊明杨 on 2020/9/30.
//  Copyright © 2020 樊明杨. All rights reserved.
//

#ifndef U2T_hpp
#define U2T_hpp

#include <iostream>

/*
 * 将无符号数字转换为补码数字。
 * 第一个参数代表无符号数字，不论用户输入哪种长度的无符号数字都自动转换为长度是64的long类型。
 * 第二个参数代表位数量，它决定了两种解释方式的值域，而不是由64位的第一个参数决定。
 */
signed long U2T(unsigned long u,unsigned int bitCount);

#endif /* U2T_hpp */
