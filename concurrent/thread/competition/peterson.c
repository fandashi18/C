#include <pthread.h>
#include <stdio.h>

volatile  unsigned int turn = 0;
volatile _Atomic unsigned int cnt = 0;
unsigned int interested[2] = {0,0};

void enterRegion(unsigned int process);
void leaveRegion(unsigned int process);
void *countRoutine1(void *arg);
void *countRoutine2(void *arg);

void test();

unsigned int count1[10000],count2[10000];

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
    pthread_create(&tid1, NULL, countRoutine1, &turn0);
    pthread_create(&tid2, NULL, countRoutine2, &turn1);

    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);

    printf("%d\n", cnt);

    if (cnt == 20000)
    {
        return ;
    }

    for (int i = 0; i < 10000; i++)
    {
        int tmp = count1[i];
        for (int j = 0; j < 10000; j++)
        {
            if (tmp == count2[j])
            {
                printf("%d\n", tmp);
            }
            
        }
    }
    printf("\n\n");
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

void *countRoutine1(void *arg) {
    int process = *((int *)arg);
    unsigned i = 0;
    for (; i < 10000; i++)
    {
        enterRegion(process);
        count1[i] = cnt;
        cnt++;
        leaveRegion(process);
    }

    return NULL;
}

void *countRoutine2(void *arg) {
    int process = *((int *)arg);
    unsigned i = 0;
    for (; i < 10000; i++)
    {
        enterRegion(process);
        count2[i] = cnt;
        cnt++;
        leaveRegion(process);
    }

    return NULL;
}