/**
 * 初始化例程
 * 
 * 编译指令：
 * gcc -std=c11 -O1 main.c -lpthread
 */ 
#include <pthread.h>
#include <stdio.h>

void init_routine(void);
void *start_routine(void *);

int shareAge;

int main(int argc, char const *argv[])
{
    pthread_t tid1, tid2;
    pthread_once_t once_control = PTHREAD_ONCE_INIT;
    pthread_once(&once_control, init_routine);
    pthread_create(&tid1, NULL, start_routine, NULL);
    pthread_join(tid1,NULL);
    //只调用一次初始化例程
    pthread_once(&once_control, init_routine);

    pthread_create(&tid2, NULL, start_routine, NULL);
    pthread_join(tid2,NULL);

    return 0;
}

void init_routine(void){
    shareAge = 1;
}

void *start_routine(void * args){
    printf("tid is %lu,shareAge is %d\n", pthread_self(),shareAge);
    shareAge++;
    return NULL;
}
