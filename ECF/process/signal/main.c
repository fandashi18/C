#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <signal.h>

int main(int argc, char const *argv[])
{
    static pid_t childPid;

    childPid = fork();

    if (childPid == -1)
    {
        fprintf(stderr,"fork error : %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
    

    if (childPid == 0)
    {
        pause();
        printf("control should nerver reach here!\n");
        exit(EXIT_SUCCESS);
    }

    kill(childPid,SIGKILL);
    printf("Process end~\n");
    
    return 0;
}
