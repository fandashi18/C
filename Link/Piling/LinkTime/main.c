/**
 * gcc -std=gnu11 -DLINKTIME  -c mymalloc.c 
 * gcc -std=gnu11 -Wl,--wrap,malloc -Wl,--wrap,free  main.c mymalloc.o -o main
 */
#include <malloc.h>

int main(int argc, char const *argv[])
{
    void *ptr = malloc(100);
    free(ptr);
    return 0;
}
