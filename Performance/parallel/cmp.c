/**
 * Optimizing compare expression.
 * -O0 time0 / time1 = 1
 * -O1 time0 / time1 = 2
 * -O2 time0 / time1 = 72  amazing
 * -O3 time0 / time1 = 50
 */
#include <stdio.h>
#include <time.h>

int main(int argc, char const *argv[])
{
    struct timespec start, end;
    long time0, time1;
    const int SIZE = 2000;
    long data0[SIZE];
    long data1[SIZE];
    for (int i = 0; i < SIZE; i++)
    {
        data0[i] = i;
        data1[i] = i + 1;
    }
    clock_gettime(CLOCK_REALTIME, &start);
    for (int i = 0; i < SIZE; i++)
    {
        if (data0[i] > data1[i])
        {
            long tmp = data1[i];
            data1[i] = data0[i];
            data0[i] = tmp;
        }
    }
    clock_gettime(CLOCK_REALTIME, &end);
    time0 = end.tv_nsec - start.tv_nsec;
    fprintf(stdout, "time is %ld ns\n", time0);

    clock_gettime(CLOCK_REALTIME, &start);
    for (int i = 0; i < SIZE; i++)
    {
        long min = data0[i] <= data0[i] ? data0[i] : data1[i];
        long max = data0[i] <= data0[i] ? data1[i] : data0[i];
        data0[i] = min;
        data1[i] = max;
    }
    clock_gettime(CLOCK_REALTIME, &end);
    time1 = end.tv_nsec - start.tv_nsec;
    fprintf(stdout, "time is %ld ns\n", time1);

    fprintf(stdout, "time0 / time1 = %f\n", ((double)time0 / time1));
    return 0;
}
