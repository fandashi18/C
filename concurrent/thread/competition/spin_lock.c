/**
 * 用于解决忙等待互斥的优先级反转问题
 */ 
#define _POSIX_C_SOURCE >= 200112L

#include <pthread.h>
#include <stdio.h>

static pthread_spinlock_t spinlock;
static int count = 0;
static void *countRoutine(void *);
int main(int argc, char const *argv[])
{
    pthread_spin_init(&spinlock, PTHREAD_PROCESS_PRIVATE);
    pthread_t tid1, tid2;
    pthread_create(&tid1, NULL, countRoutine, NULL);
    pthread_create(&tid2, NULL, countRoutine, NULL);
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);

    pthread_spin_destroy(&spinlock);

    printf("count = %d\n", count);
    return 0;
}

void *countRoutine(void *arg)
{
    for (int i = 0; i < 1000000; i++)
    {
        pthread_spin_lock(&spinlock);
        count++;
        pthread_spin_unlock(&spinlock);
    }
    return NULL;
}