/**
 * using time 329802 ns
 */ 
#include <sys/mman.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int main(int argc, char const *argv[])
{
    struct timespec start, end;
    clock_gettime(CLOCK_REALTIME, &start);

    FILE * file;
    if (NULL == (file = fopen("/home/fmy/Projects/C-Research/C/VM/copy2stdout/main.c", "r")))
    {
      perror(strerror(errno));
      exit(EXIT_FAILURE);
    }

    char buf[1024];
    while (fread(buf,1,1,file) > 0)
    {
        printf("%s",buf);
    }
    
    clock_gettime(CLOCK_REALTIME, &end);

    printf("using time %ld ns\n",end.tv_nsec - start.tv_nsec);

    fclose(file);

    return 0;
}
