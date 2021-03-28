#include <pthread.h>
#include <stdio.h>

static const unsigned int SIZE = 10000;
static unsigned int count;

static pthread_mutex_t mutex;
static pthread_cond_t condProduce,condConsume;

void *produce(void *);
void *consume(void *);

int main(int argc, char const *argv[])
{
    pthread_mutexattr_t mutexattr;
    pthread_mutexattr_init(&mutexattr);
    pthread_mutexattr_settype(&mutexattr, PTHREAD_MUTEX_NORMAL);

    pthread_mutex_init(&mutex, &mutexattr);
    pthread_mutexattr_destroy(&mutexattr);

    pthread_t producerTid, consumerTid;
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
    pthread_create(&producerTid, &attr, produce, NULL);
    pthread_create(&producerTid, &attr, consume, NULL);
    pthread_attr_destroy(&attr);

    pthread_exit(NULL);
    return 0;
}

void *produce(void *arg)
{

    while (1)
    {
        pthread_mutex_lock(&mutex);
        if (count == SIZE)
        {
            printf("wait consuming~~~\n");
            pthread_cond_wait(&condProduce,&mutex);
        }

        count++;

        printf("produce a item : %lu\n", count);

        if (count == 1)
        {
            pthread_cond_signal(&condConsume);
        }
        pthread_mutex_unlock(&mutex);
    }

    return NULL;
}

void *consume(void *arg)
{

    while (1)
    {
        pthread_mutex_lock(&mutex);
        if (count == 0)
        {
            printf("wait produce~~~\n");
            pthread_cond_wait(&condConsume,&mutex);
        }

        printf("consume a item : %lu\n", count);
        count--;
        
        if (count == SIZE - 1)
        {
            pthread_cond_signal(&condProduce);
        }
        pthread_mutex_unlock(&mutex);
    }

    return NULL;
}