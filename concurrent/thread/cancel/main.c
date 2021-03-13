#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>

void *start_routine(void *arg);

int main(int argc, char const *argv[])
{
    pthread_t tid;
    pthread_create(&tid, NULL, start_routine, NULL);
    struct timespec time = {.tv_nsec = 200};
    nanosleep(&time, NULL);
    pthread_cancel(tid);
    exit(EXIT_SUCCESS);
}

void *start_routine(void *arg)
{
    for (int i = 0; i < 3; i++)
    {
        printf("sleep %d s\n", i);
        sleep(1);
    }

    return 0; //implicit call to pthread_exit()
}