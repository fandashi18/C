//
//  ShowBytes.cpp
//  Information presentation and processing
//
//  Created by 樊明杨 on 2020/10/4.
//  Copyright © 2020 樊明杨. All rights reserved.
//

#include "ShowBytes.hpp"

void showBytes(BytePointer bp,int byteCount){
    using namespace std;
    //1.检查输入
    if (bp == nullptr) {
        cout <<"错误：输入字节指针不可为空" << endl;
        return;
    }
    
    if (byteCount <= 0) {
        cout << "错误：输入字节数应大于0" << endl;
        return;
    }
    
    //2.遍历字节
    for (int pos = 0; pos < byteCount; pos++) {
        printf("%.2x ",bp[pos]);
    }
    cout << endl;
}

