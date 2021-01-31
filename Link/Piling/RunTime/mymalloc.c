#ifdef RUNTIME
#define _GNU_SOURCE
#include <dlfcn.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>

void *malloc(size_t size)
{
    write(1, "call malloc\n", 12);
    static void *(*mallocp)(size_t);
    mallocp = dlsym(RTLD_NEXT, "malloc");
    if (mallocp == NULL)
    {
        exit(1);
    }

    return mallocp(size);
}

void free(void *ptr)
{
    write(1, "call free\n", 10);
    static void (*freep)(void *);
    freep = dlsym(RTLD_NEXT, "free");
    if (freep == NULL)
    {
        exit(1);
    }
    freep(ptr);
}
#endif