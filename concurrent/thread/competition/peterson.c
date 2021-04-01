#include <pthread.h>
#include <stdio.h>

volatile unsigned int turn = 0;
volatile unsigned int cnt = 0;
unsigned int interested[2] = {0,0};

void enterRegion(unsigned int process);
void leaveRegion(unsigned int process);
void *countRoutine(void *arg);

void test();

int main(int argc, char const *argv[])
{
    for (int i = 0; i < 1000; i++)
    {
        cnt = 0;
        turn = 0;
        test();
    }
    
    return 0;
}

void test() {
    int turn0 = 0, turn1 = 1;
    pthread_t tid1, tid2;
    pthread_create(&tid1, NULL, countRoutine, &turn0);
    pthread_create(&tid2, NULL, countRoutine, &turn1);

    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);

    printf("%d\n", cnt);
}

void enterRegion(unsigned int process) {
    int other = 1 - process;
    interested[process] = 1;
    turn = process;
    while (turn == process && interested[other] == 1)
    {
        ;
    }
}

void leaveRegion(unsigned int process) {
    interested[process] = 0;
}

void *countRoutine(void *arg) {
    int process = *((int *)arg);
    unsigned i = 0;
    for (; i < 10000; i++)
    {
        enterRegion(process);
        cnt++;
        leaveRegion(process);
    }

    return NULL;
}