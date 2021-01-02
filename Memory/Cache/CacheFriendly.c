/**
 * 编写高速缓存友好的代码
 * 
 * 编译指令：
 * gcc -std=c99 -O0 -o main CacheFriendly.c
 * 
 * 输出结果：
 * cache friendly time is 1640 
 * not cache friendly time is 3497 
 * not/friendly = 2.132317
 */ 
#include <stdio.h>
#include <sys/time.h>

int main(int argc, char const *argv[])
{
    struct timeval start,end;
    int friendTime, notFriendTime;
    long sum;

    long iArr[1000][1000];
    /**
     * init array 
     */
    for (int i = 0; i < 1000; i++)
    {
        for (int j = 0; j < 1000; j++)
        {
            iArr[j][i] = i + j;
        }
    }

    sum = 0;
    gettimeofday(&start,NULL);
    for (int i = 0; i < 1000; i++)
    {
        for (int j = 0; j < 1000; j++)
        {
            sum += iArr[i][j];//Read row first
        }
    }
    gettimeofday(&end,NULL);
    friendTime = end.tv_usec - start.tv_usec;
    fprintf(stdout, "cache friendly time is %d \n", friendTime);

    sum = 0;
    gettimeofday(&start, NULL);
    for (int i = 0; i < 1000; i++)
    {
        for (int j = 0; j < 1000; j++)
        {
            sum += iArr[j][i];//Read column first
        }
    }
    gettimeofday(&end,NULL);
    notFriendTime = end.tv_usec - start.tv_usec;
    fprintf(stdout, "not cache friendly time is %d \n", notFriendTime);

    fprintf(stdout, "not/friendly = %f \n", (double)notFriendTime / friendTime);
    return 0;
}

