#define _GNU_SOURCE

#include <pthread.h>
#include <stdio.h>

void *workRoutine(void *);

int main(int argc, char const *argv[])
{
    pthread_t tid;
    pthread_attr_t attr;
    
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
    pthread_create(&tid, &attr, workRoutine, NULL);
    pthread_attr_destroy(&attr);

    pthread_exit(NULL);
    return 0;
}

void *workRoutine(void *arg)
{
    pthread_attr_t gattr;
    pthread_getattr_np(pthread_self(), &gattr);
    int detached;
    pthread_attr_getdetachstate(&gattr, &detached);

    printf("detached ? %d\n", (detached == PTHREAD_CREATE_DETACHED));
}
