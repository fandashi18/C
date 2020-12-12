#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    static pid_t childPid;
    static int x = 1;

    childPid = fork();

    if (childPid == -1)
    {
        fprintf(stderr,"fork error : %s\n",strerror(errno));
        exit(EXIT_FAILURE);
    }
    

    if (childPid == 0)
    {
        x--;
        printf("child process x = %d\n", x);
    }else 
    {
        printf("child process pid is %d\n", childPid);

        x++;
        printf("parent process x = %d\n", x);
    }
    
    
    return 0;
}
