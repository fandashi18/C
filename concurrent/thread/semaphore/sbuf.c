#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdbool.h>
#include <stdlib.h>


volatile int cnt = 0;

int main(int argc, char const* argv[])
{
    
    return 0;
}

typedef struct {
    int* buf;
    unsigned int capacity;
    int front;
    int rear;
    sem_t mutex;
    sem_t slots;
    sem_t items;
} safe_buf_t;

_Bool initBuf(safe_buf_t * sbp, int capacity) {
    if (sbp == NULL || capacity <= 0)
    {
        return false;
    }

    sbp->buf = (int*)calloc(capacity, sizeof(int));
    sbp->capacity = capacity;
    sbp->front = sbp->rear = 0;
     
    sem_init(&sbp->mutex,0,1);
    sem_init(&sbp->slots, 0, capacity);
    sem_init(&sbp->items, 0, 0);
    return true;
}

void deBuf(safe_buf_t* sbp) {
    if (sbp == NULL)
    {
        return ;
    }

    free(sbp->buf);
    sbp->buf = NULL;
    sbp->capacity = 0;
    sbp->front = sbp->rear = 0;
}

_Bool insertItem(safe_buf_t* sbp, int item) {
    if (sbp == NULL)
    {
        return false;
    }

    sem_wait(&sbp->slots);
    sem_wait(&sbp->mutex);
    sbp->buf[(++sbp->rear) % sbp->capacity] = item;
    sem_post(&sbp->mutex);
    sem_post(&sbp->items);

    return false;
}

int removeItem(safe_buf_t* sbp) {
    if (sbp == NULL)
    {
        exit(EXIT_FAILURE);
    }

    int item;
    sem_wait(&sbp->items);
    sem_wait(&sbp->mutex);
    item = sbp->buf[(++sbp->front) % sbp->capacity];
    sem_post(&sbp->mutex);
    sem_post(&sbp->slots);
    
    return item;
}