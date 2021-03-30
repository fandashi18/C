#include <pthread.h>
#include <stdio.h>

volatile unsigned int turn = 0;
volatile unsigned int cnt = 0;
unsigned int interested[2] = {0,0};

void enterRegion(unsigned int process);
void leaveRegion(unsigned int process);
void *countRoutine(void *arg);

int main(int argc, char const *argv[])
{
    int turn0 = 0, turn1 = 1;
    pthread_t tid1, tid2;
    pthread_create(&tid1, NULL, countRoutine, &turn0);
    pthread_create(&tid2, NULL, countRoutine, &turn1);

    pthread_exit(NULL);
    return 0;
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
    pthread_detach(pthread_self());
    unsigned int localCount;
    int localTurn = *((int *)arg);
    unsigned i = 0;
    for (; i < 100000; i++)
    {
        enterRegion(localTurn);
        cnt++;
        leaveRegion(localTurn);
    }
    
    return NULL;
}