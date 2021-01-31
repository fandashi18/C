//
// Created by fmy on 2021/1/31.
//

#ifndef PILING_MALLOC_H
#define PILING_MALLOC_H
#include <malloc.h>
#include <stddef.h>
#define malloc(size) mymalloc(size)
#define free(ptr) myfree(ptr)

void * mymalloc(size_t);
void myfree(void *);
#endif //PILING_MALLOC_H
