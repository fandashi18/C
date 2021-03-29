#include <pthread.h>
#include <stdio.h>

volatile unsigned int turn = 0;
volatile unsigned int cnt = 0;

void *countRoutine(void *arg);

int main(int argc, char const *argv[])
{
    int turn0 = 0, turn1 = 1;
    pthread_t tid1, tid2;
    pthread_create(&tid1, NULL, countRoutine, &turn0);
    pthread_create(&tid2, NULL, countRoutine, &turn1);
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
    
    printf("cnt = %d\n", cnt);

    return 0;
}

void *countRoutine(void *arg) {
    int localTurn = *((int *)arg);
    for (unsigned i = 0; i < 100000; i++)
    {
        //忙等待。可能被临界区外的线程阻塞，从而减慢执行速度。
        while (turn != localTurn)
        {
            ;
        }
        //进入临界区
        cnt++;
        //退出临界区
        turn = 1 - localTurn;
    }
    return NULL;
}