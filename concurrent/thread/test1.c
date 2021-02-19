/**
 * posix thread API 测试
 * 
 * 编译指令：
 * gcc -std=gnu17 -O1 test1.c -lpthread
 * 
 * 输出：
 * tid is 140602231387904
 * hello
 * sleep 0 s
 * sleep 1 s
 * attemp to stop 140602231387904
 * main thread will exit
 */ 
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void *start_routine(void *);

int main(int argc, char const *argv[])
{
    pthread_t tid;
    if (pthread_create(&tid, NULL, start_routine, NULL) != 0)
    {
        fprintf(stderr, "Failed create thread.\n");
        exit(EXIT_FAILURE);
    }

    printf("tid is %lu\n", tid);

    if (pthread_join(tid, NULL) != 0)
    {
        fprintf(stderr, "Failed join thread.\n");
        exit(EXIT_FAILURE);
    }

    printf("main thread will exit \n");

    return 0;
}

void *start_routine(void *args)
{
    // pthread_detach(pthread_self());
    printf("hello\n");
    for (int i = 0; i < 3; i++)
    {
        if (i == 2)
        {
            printf("attemp to stop %lu\n", pthread_self());
            pthread_cancel(pthread_self());
        }

        sleep(1);
        printf("sleep %d s\n", i);
    }

    return NULL;
}