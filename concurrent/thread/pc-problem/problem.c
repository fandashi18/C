#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>
#include <string.h>
#include <errno.h>

void sigHandler(int sig);
void *produce(void *);
void *consume(void *);

static pthread_t producerTid, consumerTid;

static const unsigned int SIZE = 10000;
static unsigned int count;

int main(int argc, char const *argv[])
{
    count = 0;

    if (signal(SIGUSR1, sigHandler) == SIG_ERR)
    {
        perror(strerror(errno));
        exit(EXIT_FAILURE);
    }

    if (pthread_create(&producerTid, NULL, produce, NULL) != 0)
    {
        fprintf(stderr, "Failed create producer.");
        exit(EXIT_FAILURE);
    }

    if (pthread_create(&consumerTid,NULL,consume,NULL) != 0)
    {
        fprintf(stderr, "Failed create consumer.");
        exit(EXIT_FAILURE);
    }

    pthread_exit(NULL);

    return 0;
}

void sigHandler(int sig) {
    
}

void *produce(void * arg){
    pthread_detach(pthread_self());
    unsigned long int localCount = 0;
    while (1)
    {
        if (count == SIZE)
        {
            pause();
        }

        printf("produce a item : %lu\n",++localCount);
        count++;

        if (count == 1)
        {
            pthread_kill(consumerTid, SIGUSR1);
        }
    }

    return NULL;
}

void *consume(void * arg){
    pthread_detach(pthread_self());

    while (1)
    {
        if (count == 0)
        {
            pause();
        }
        printf("consume a item\n");
        count--;

        if (count == SIZE - 1)
        {
            pthread_kill(producerTid, SIGUSR1);
        }
    }

    return NULL;
}