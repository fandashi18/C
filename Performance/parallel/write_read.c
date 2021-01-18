/**
 * 写/读相关问题
 * 读之前写操作必须完毕，由此造成时间时间增加了2～7倍。
 * 
 * 编译指令：
 * gcc -O0 -std=gnu11 -o main write_read.c
 * 
 * 结果：
 * -O0 time0 / time1 = 2.29
 * -O1 time0 / time1 = 7.21
 * -O2 time0 / time1 = 2.50
 * -O3 time0 / time1 = 2.50
 */

#include <stdio.h>
#include <time.h>

void write_read(long *src, long *dst, long n);

int main(int argc, char const *argv[])
{
    const signed int SIZE = 1000;
    long data[SIZE];
    struct timespec start, end;
    long time0, time1;

    for (size_t i = 0; i < SIZE; i++)
    {
        data[i] = i;
    }

    clock_gettime(CLOCK_REALTIME, &start);
    write_read(&data[0], &data[0], SIZE);
    clock_gettime(CLOCK_REALTIME, &end);

    time0 = end.tv_nsec - start.tv_nsec;

    clock_gettime(CLOCK_REALTIME, &start);
    write_read(&data[0], &data[1], SIZE);
    clock_gettime(CLOCK_REALTIME, &end);

    time1 = end.tv_nsec - start.tv_nsec;

    fprintf(stdout, "time0 / time1 = %f\n", (double)time0 / time1);
    return 0;
}

void write_read(long *src, long *dst, long n)
{
    long tmp = 0;

    while (n)
    {
        *dst = tmp;
        tmp = *src + 1;
        n--;
    }
}
