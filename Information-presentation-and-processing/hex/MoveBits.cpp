//
//  MoveBits.cpp
//  Information presentation and processing
//
//  Created by 樊明杨 on 2020/9/30.
//  Copyright © 2020 樊明杨. All rights reserved.
//

#include "MoveBits.hpp"

void testBitsMove(){
    using namespace std;
    
    short sd = 0x1;
    int id = 0x1;
    long ld = 0x1;
    int moveCount = 0xf;
    //1.对比short运算结果
    cout << (sd << moveCount) << endl;
    cout << (id << moveCount) << endl;
    cout << (ld << moveCount) << endl;
    
    moveCount = 0xf + 1;
    
    cout << (sd << moveCount) << endl;
    sd <<= moveCount;
    cout << sd << endl;
    cout << (id << moveCount) << endl;
    cout << (ld << moveCount) << endl;
    
    //2.对比编码范围
    moveCount = 0x1f;
    cout << (id << moveCount) << endl;
    cout << (ld << moveCount) << endl;
    
    moveCount = 0x11f;
    cout << (id << moveCount) << endl;
    cout << (ld << moveCount) << endl;
    moveCount = 0x111f;
    cout << (id << moveCount) << endl;
    cout << (ld << moveCount) << endl;
}
