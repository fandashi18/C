#include "fmy-io.h"
#include "fmy-string/fmy-string.h"
/**
 * 将int类型整数转换为一个字符串
 * 32位int最大数据需要10个字符，最小负数需要11个字符，还需要一个字符存储'\0'。
 * 因此，建议输入字符数组s的长度是12。
 */ 
void myitos(int n, char s[])
{
    int i, sign;
    if ((sign = n) < 0) /* record sign */
        n = -n; /* make n positive */
    i = 0;
    do { /* generate digits in reverse order */
        s[i++] = n % 10 + '0'; /* get next digit */
    } while ((n /= 10) > 0); /* delete it */
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    myreverse(s);

    return;
}