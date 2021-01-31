#ifdef LINKTIME
#include <malloc.h>
#include <stdio.h>

void *__real_malloc(size_t size);
void __real_free(void *ptr);

void *__wrap_malloc(size_t size)
{
    printf("call __wrap_malloc\n");
    return __real_malloc(size);
}

void __wrap_free(void *ptr)
{
    printf("call __wrap_free\n");
    __real_free(ptr);
}
#endif