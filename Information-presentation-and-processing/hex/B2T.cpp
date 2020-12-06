//
//  B2T.cpp
//  Information presentation and processing
//
//  Created by 樊明杨 on 2020/9/30.
//  Copyright © 2020 樊明杨. All rights reserved.
//

#include "B2T.hpp"

signed long B2T(char const * binaryStr,int count){
    using namespace std;
    //1.检查输入
    if (binaryStr == nullptr) {
        cout << "错误：输入字符序列为空" << endl;
        return 0;
    }
    
    if (count <= 0 || count >= 65) {
        cout << "字符个数范围必须是[1,64]" << endl;
        return 0;
    }
    
    //2.解释字符序列
    signed long tResult = 0;
    //2.1 计算负权
    int negativeWeight = binaryStr[0] - 0x30;
    //2.2 计算除符号位之外的累加和
    for (int i = 1; i < count; i++) {
        int b = binaryStr[i] - 0x30;
        
         if (b == 1) {
             tResult += (1 << (count - i - 1));
         }else if (b != 0){
             cout << "错误：输入的字符序列只能包含字符0或字符1" << endl;
             return 0;
         }
    }
    //2.3 加上负数
    if (negativeWeight == 1) {
        tResult += ~(1 << (count - 1)) + 1;
    }
    return tResult;
}
