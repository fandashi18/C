#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

void *start_routine(void *arg);
void *start_routine_safe(void *arg);

volatile int cnt = 0;

sem_t sem;

int main(int argc, char const *argv[])
{

    pthread_t tid1, tid2;
    pthread_create(&tid1, NULL, start_routine, NULL);
    pthread_create(&tid2, NULL, start_routine, NULL);
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);

    printf("cnt = %d\n", cnt);

    cnt = 0;

    /**
     * 同步对共享数据的访问
     */
    sem_init(&sem, 0, 1);
    pthread_t tid3, tid4;
    pthread_create(&tid3, NULL, start_routine_safe, NULL);
    pthread_create(&tid4, NULL, start_routine_safe, NULL);
    pthread_join(tid3, NULL);
    pthread_join(tid4, NULL);
    sem_destroy(&sem);
    printf("cnt = %d\n", cnt);
    return 0;
}

void *start_routine(void *arg)
{

    for (unsigned i = 0; i < 100000; i++)
    {
        cnt++;
    }
}

void *start_routine_safe(void *arg)
{
    for (unsigned i = 0; i < 100000; i++)
    {
        sem_wait(&sem); //取锁
        cnt++;
        sem_post(&sem); //还锁
    }
}
