//
//  MoveBits.hpp
//  Information presentation and processing
//
//  Created by 樊明杨 on 2020/9/30.
//  Copyright © 2020 樊明杨. All rights reserved.
//

/*
 * 移位运算的本质是用最低位的1个字节来编码移位量，根据移位数的类型不同而取用该字节中的不同的连续的位。
 * 注意：short数据类型在算术运算时会先转化为int数据类型，运算完毕后，再将结果截断为short。结合移位运算的实质，从而导致了一些低级程序猿难以理解的微妙的结果。
 */
#ifndef MoveBits_hpp
#define MoveBits_hpp

#include <iostream>

void testBitsMove();
#endif /* MoveBits_hpp */
