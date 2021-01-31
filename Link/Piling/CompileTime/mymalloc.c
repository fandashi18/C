//
// Created by fmy on 2021/1/31.
//
#ifdef COMPILETIME
#include <stdlib.h>
#include <stdio.h>

void * mymalloc(size_t size){
    printf("mymalloc be calling\n");
    void *ptr = malloc(size);
    return ptr;
}
void myfree(void * ptr){
    printf("myfree be calling\n");
    free(ptr);
    return;
}
#endif
