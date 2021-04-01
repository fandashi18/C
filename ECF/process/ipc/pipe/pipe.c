#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>

#define LENGTH 6
int main(int argc, char const *argv[])
{
    int fildes[2];

    const char helloStr[LENGTH] = "hello";
    if (pipe(fildes) == -1)
    {
        perror(strerror(errno));
        exit(EXIT_FAILURE);
    }

    pid_t pid = fork();
    if (pid == -1)
    {
        perror(strerror(errno));
        exit(EXIT_FAILURE);
    }
    
    if (pid == 0)
    {
        static char buf[LENGTH];
        if (read(fildes[0], buf, LENGTH - 1) == -1)
        {
            perror(strerror(errno));
            exit(EXIT_FAILURE);
        }
        printf("child: read : %s\n", buf);

    }

    if (write(fildes[1],helloStr,LENGTH) == -1)
    {
        perror(strerror(errno));
        exit(EXIT_FAILURE);
    }

    return 0;
}


