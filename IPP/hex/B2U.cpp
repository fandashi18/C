//
//  B2U.cpp
//  Information presentation and processing
//
//  Created by 樊明杨 on 2020/9/30.
//  Copyright © 2020 樊明杨. All rights reserved.
//

#include "B2U.hpp"

unsigned long B2U(char const * binaryStr, int count){
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
    unsigned long uResult = 0;
    for (int i = 0; i < count; i++) {
        int b = binaryStr[i] - 0x30;
       
        if (b == 1) {
            uResult += (1 << (count - i - 1));
        }else if (b != 0){
            cout << "错误：输入的字符序列只能包含字符0或字符1" << endl;
            return 0;
        }
        
    }
    return uResult;
}
