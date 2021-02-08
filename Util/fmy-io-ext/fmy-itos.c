#include "fmy-io.h"
#include "fmy-string/fmy-string.h"
#include <stddef.h>
/**
 * 将int类型整数转换为一个字符串
 * 32位int最大数据需要10个字符，最小负数需要11个字符，还需要一个字符存储'\0'。
 * 因此，建议输入字符数组s的长度是12。
 */
void myitos(int n, char s[])
{
    if (s == NULL)
    {
        return;
    }

    int sign = 0, index = 0;
    if (n < 0)
    {
        sign = 1;
        n = -n;
    }

    //因为一个整数数字至少有一位，所以可用do-while结构
    do
    {
        s[index++] = n % 10 + '0';
    } while ((n /= 10) > 0);

    if (sign == 1)
    {
        s[index++] = '-';
    }

    s[index] = '\0';

    myreverse(s);

    return;
}