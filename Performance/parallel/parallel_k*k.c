/**
 * 编译指令：
 * gcc -std=c99 -O0 -o main parallel.c
 * 
 * 输出结果：
 * sum = 499500,time is 2ms
 * sum = 499500,time is 4ms
 */
#include <stdio.h>
#include <sys/time.h>
#include <time.h>

void run();

int main(int argc, char const *argv[])
{
    run();
    return 0;
}

void run()
{
    struct timespec start, end;
    long time;
    const int SIZE = 10000;
    long data[SIZE];
    int i;
    for (i = 0; i < SIZE; i++)
    {
        data[i] = i;
    }

    clock_gettime(CLOCK_REALTIME, &start);
    i = 0;
    int str = 10;
    int limit = SIZE - str;
    int acc0 = 0, acc1 = 0, acc2 = 0, acc3 = 0, acc4 = 0, acc5 = 0, acc6 = 0, acc7 = 0, acc8 = 0, acc9 = 0;
    long sum = 0;

    for (; i < limit; i += str)
    {
        acc0 += data[i];
        acc1 += data[i + 1];
        acc2 += data[i + 2];
        acc3 += data[i + 3];
        acc4 += data[i + 4];
        acc5 += data[i + 5];
        acc6 += data[i + 6];
        acc7 += data[i + 7];
        acc8 += data[i + 8];
        acc9 += data[i + 9];
    }

    for (; i < SIZE; i += 1)
    {
        acc0 += data[i];
    }

    sum = acc0 + acc1 + acc2 + acc3 + acc4 + acc5 + acc6 + acc7 + acc8 + acc9;
    clock_gettime(CLOCK_REALTIME, &end);
    time = end.tv_nsec - start.tv_nsec;
    fprintf(stdout, "sum = %ld,time is %ldms\n", sum, time);
}
