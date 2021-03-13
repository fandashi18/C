#include <pthread.h>
#include <stdio.h>

void *start_routine(void *arg);

int main(int argc, char const *argv[])
{
    pthread_t tid;
    pthread_create(&tid, NULL, start_routine, NULL);

    void *joinResult;
    pthread_join(tid, &joinResult);
    printf("join result is %s\n", joinResult);
    return 0;
}

void *start_routine(void *arg)
{
    for (int i = 0; i < 3; i++)
    {
        printf("start_routine:sleep %d s\n", i);
        sleep(1);
    }

    pthread_exit("success_exit"); //implicit call to pthread_exit()
}
