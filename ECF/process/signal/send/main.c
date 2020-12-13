#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <signal.h>

int main(int argc, char const *argv[])
{
    static pid_t pgid, childPid;

    pgid = getpgrp();

    printf("Process group id is %d\n", pgid);

    childPid = fork();

    if (childPid == -1)
    {
        fprintf(stderr, "fork error : %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    if (childPid == 0)
    {
        pause();
        printf("control should nerver reach here!\n");
        exit(EXIT_SUCCESS);
    }

    int killResult = kill(childPid, SIGKILL);
    if (killResult == -1)
    {
        fprintf(stderr,"kill error : %s\n",strerror(errno));
    }
    
    printf("Process end~\n");

    return 0;
}
