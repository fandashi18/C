#include <sys/mman.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>

static void *buf;
int main(int argc, char const *argv[])
{
    buf = mmap(NULL, 4, PROT_WRITE, MAP_SHARED | MAP_ANON, 0, 0);
    if (buf == MAP_FAILED)
    {
        perror(strerror(errno));
        exit(EXIT_FAILURE);
    }
    *((int *)buf) = 1;

    if (fork() == 0)
    {
        *((int *)buf) = 0;
        exit(EXIT_SUCCESS);
    }

    waitpid(-1, NULL, 0);
    printf("buf value is %d\n", *((int *)buf));
    return 0;
}

