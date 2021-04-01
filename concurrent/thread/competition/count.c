#include <stdio.h>
#include <pthread.h>

static void *countRoutine(void *arg);

static volatile int cnt = 0;
int main(int argc, char const *argv[])
{
    pthread_t tid1, tid2;
    pthread_create(&tid1, NULL, countRoutine, NULL);
    pthread_create(&tid2, NULL, countRoutine, NULL);
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);

    printf("cnt = %d\n", cnt);

    return 0;
}

void *countRoutine(void *arg)
{
    for (unsigned i = 0; i < 100000; i++)
    {
        cnt++;
    }
    return NULL;
}

