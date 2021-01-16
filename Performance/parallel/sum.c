#include <stdio.h>
#include <sys/time.h>
#include <time.h>

int main(int argc, char const *argv[])
{
    struct timespec start, end;
    long time,sum;
    const int SIZE = 10000;
    long data[SIZE];
    int i;
    for (i = 0; i < SIZE; i++)
    {
        data[i] = i;
    }

    clock_gettime(CLOCK_REALTIME, &start);
    sum = 0;
    for (int i = 0; i < SIZE; i++)
    {
        sum += data[i];
    }
    clock_gettime(CLOCK_REALTIME, &end);

    time = end.tv_nsec - start.tv_nsec;
    fprintf(stdout, "sum = %ld,time is %ld ms\n", sum, time);

    return 0;
}
