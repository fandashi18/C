#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    static int x = 1;
    static pid_t childPid;
    static int wstatus;

    childPid = fork();

    if (childPid == -1)
    {
        fprintf(stderr, "fork error : %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    if (childPid == 0)
    {
        x++;
    }
    else
    {
        pid_t wp = waitpid(-1, &wstatus, WUNTRACED);
        if (wp == -1)
        {
            fprintf(stderr,"waitpid error : %s\n",strerror(errno));
            exit(EXIT_FAILURE);
        }

        printf("waitpid end\n");
        printf("child process normally exit ? %d\n",WIFEXITED(wstatus));
        x--;
    }

    printf("x = %d\n",x);

    return 0;
}
