//
//  main.cpp
//  Information presentation and processing
//
//  Created by 樊明杨 on 2020/9/30.
//  Copyright © 2020 樊明杨. All rights reserved.
//

#include <iostream>
#include <climits>
#include "hex/B2U.hpp"
#include "hex/B2T.hpp"
#include "hex/U2T.hpp"
#include "hex/T2U.hpp"
#include "hex/UOverflow.hpp"
#include "hex/TOverflow.hpp"
#include "hex/MoveBits.hpp"
#include "hex/TMultOk.hpp"
#include "hex/UMultOk.hpp"
#include "hex/ShowBytes.hpp"
#include "hex/UDiv.hpp"

int main(int argc, char const *argv[])
{
    using namespace std;
    unsigned long u = B2U("11111", 5);
    cout << u << endl;
    
    signed long t = B2T("11110", 5);
    cout << t << endl;
    
    t = U2T(16, 5);
    cout << t << endl;
    
    u = T2U(t, 5);
    cout << u << endl;
    
    int uAddOk = ulAddOk(ULONG_MAX, 1);
    cout << uAddOk << endl;
    
    uAddOk = uiAddOk(UINT_MAX, 1);
    cout << uAddOk << endl;
    
    int tAddOk = tlAddOk(LONG_MAX, 1);
    cout << tAddOk << endl;
    tAddOk = tlAddOk(LONG_MIN, -1);
    cout << tAddOk << endl;

    testBitsMove();
    
    int tMultOk = tiMultOk(INT32_MAX, 2);
    cout << tMultOk << endl;
    tMultOk = ti32MultOk(INT32_MAX, 2);
    cout << tMultOk << endl;
    
    int uMultOk = uiMultOk(UINT32_MAX, 2);
    cout << uMultOk << endl;
    
    signed char x = 1,y= -1;
    showBytes((BytePointer)&x, 1);
    showBytes((BytePointer)&y, 1);

    testDiv();

    unsigned int ui = 1;
    cout << (~ui + 1) << endl;
    cout << -ui << endl;
    cout << -ui + ui << endl;
    cout << (2 * -ui) + 2 * ui << endl;

    //整数加法和乘法都不满足单调性
    cout << "整数加法和乘法都不满足单调性" << endl;
    int ia = INT32_MAX, ib = 123;
    cout << ((ia + (int)1000) > (ib + (int)1000)) << endl;
    cout << ((ia * (int)1000) > (ib * (int)1000)) << endl;

    //整数加法符合交换律与结合律
    cout << "整数加法符合交换律与结合律 :" << endl;
    cout << ((INT32_MAX + (int)123) == ((int)123 + INT32_MAX)) << endl;
    cout << ((INT32_MAX + (int)123 + (int)321) == (INT32_MAX + ((int)123 + (int)321))) << endl;
    cout << "因此，不能用减法来证明加法运算是否溢出！（a + b = c,c - a = a + b - a = b + a -a = b + ( a - a ) = b）" << endl;

    //整数乘法对加法符合分配律
    cout << "整数乘法对加法符合分配律 :" << endl;
    unsigned int uimax = UINT32_MAX;
    cout << ((unsigned int)(uimax * (1 + 2)) == (unsigned int)(uimax * 1 + uimax * 2)) << endl;

    signed int imax = INT32_MAX;
    cout << ((int)(imax * (1 + 2)) == (int)(imax * 1 + imax * 2)) << endl;

    //浮点数加法和乘法都满足单调性
    cout << "浮点数加法和乘法都满足单调性" << endl;


    //浮点数与整数的位模式转换，可手动计算后对比机器结果
    cout << "浮点数与整数的位模式转换" << endl;
    float f = 123.0f;
    showBytes((BytePointer)&f,sizeof(float));

    int32_t i32t = 123;
    showBytes((BytePointer)&i32t, 4);

    //浮点数转int时，会向0舍入
    f = 1.999f;
    cout << "float " << f << " to int " << (int)f << endl;
    f = -1.999f;
    cout << "float " << f << " to int " << (int)f << endl;

    //当无法为浮点数找到一个合理的整数近似值，intel处理器就会把整数的位模式设置为100···0以表示不确定
    f = +1e10f;
    cout << (int)f << endl;

    //int转float时，不会发生溢出，但是可能发生舍入
    i32t = INT32_MAX;
    cout << "int " << i32t << " to float " << (float)i32t << endl;
    cout << (int)(float)i32t << endl;

    return 0;
}
