/**
 * gcc -DRUNTIME -std=gnu17 -shared -fpic -o mymalloc.so mymalloc.c -ldl
 * gcc -std=gnu17 -o main main.c
 */
#include <malloc.h>

int main(int argc, char const *argv[])
{
    void *ptr = malloc(100);
    free(ptr);
    return 0;
}
