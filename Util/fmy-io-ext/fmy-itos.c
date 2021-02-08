#include "fmy-io.h"
#include "fmy-string/fmy-string.h"
#include <stddef.h>
#include <stdint.h>

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

int mystoi(char *s)
{
    if (s == NULL)
    {
        return INT32_MIN;
    }

    /**
     * 1. 找到数字的起始位置与终止位置 
     */
    int result = 0;
    int sign = 0;

    if (s[0] == '-')
    {
        sign = 1;
    }

    int start = 0, end = 0;

    if (sign == 1)
    {
        start = 1;
        end = 1;
    }

    while (s[end] >= '0' && s[end] <= '9')
    {
        end++;
    }

    if (end == 0 ||(sign ==1 && end ==1))
    {
        return INT32_MIN;
    }
    /** 1. 完成 */
    
    /**
     * 2. 将每一进位的数字累加
     */ 
    int endPos = --end;
    int bits = end - start + 1;
    while (endPos >= start)
    {   
        /**
         * 计算每个进位的基数
         */ 
        int temp = start - endPos + bits -1;
        int carryBase = 1;
        for (int i = 0; i < temp; i++)
        {
            carryBase *= 10;
        }
        
        // 计算每个进位的具体值
        result += ((s[endPos] - '0') * carryBase);
        endPos--;
    }
    
    /**
     * 3. 转换符号
     */ 
    if (sign == 1)
    {
        result = -result;
    }
    
    return result;
}