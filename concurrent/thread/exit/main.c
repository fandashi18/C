#include <pthread.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>

void *start_routine(void *arg);

int main(int argc, char const *argv[])
{
    pthread_t tid1;
    tid1 = pthread_create(&tid1, NULL, start_routine, NULL);

    printf("main thread will exit.\n");
    pthread_exit(NULL);
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