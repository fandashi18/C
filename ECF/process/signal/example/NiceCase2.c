/**
 * 信号不会排队
 *
 * gcc -std=gnu17 -O1 NiceCase2.c -o nice2.out
 *
 * 输出：
 * 2
 * 1
 * 3
 */
#include <unistd.h>
#include <stdio.h>
#include <wait.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
void user1Handler(int sig);

static volatile sig_atomic_t counter = 2;

int main()
{
    if (SIG_ERR == signal(SIGUSR1, &user1Handler))
    {
        perror(strerror(errno));
        exit(EXIT_FAILURE);
    }

    printf("%d\n", counter);
    fflush(stdout);
    pid_t childPid;
    if ((childPid = fork()) == 0)
    {
        while (1)
        {
            ;
        }
    }

    if (kill(childPid, SIGUSR1) == -1)
    {
        perror(strerror(errno));
        exit(EXIT_FAILURE);
    }

    if (waitpid(-1, NULL, WUNTRACED) == -1)
    {
        perror(strerror(errno));
        exit(EXIT_FAILURE);
    }

    sigset_t sigset, oldSigset;
    if (sigfillset(&sigset) == -1)
    {
        perror(strerror(errno));
        exit(EXIT_FAILURE);
    }

    if (sigprocmask(SIG_BLOCK, &sigset, &oldSigset) == -1)
    {
        perror(strerror(errno));
        exit(EXIT_FAILURE);
    }

    counter++;
    printf("%d\n", counter);

    if (sigprocmask(SIG_SETMASK, &oldSigset, NULL) == -1)
    {
        perror(strerror(errno));
        exit(EXIT_FAILURE);
    }

    return 0;
}

void user1Handler(int sig)
{
    const int OLD_ERRNO = errno;

    sigset_t sigset, oldSigset;
    if (sigfillset(&sigset) == -1)
    {
        perror(strerror(errno));
        exit(EXIT_FAILURE);
    }

    if (sigprocmask(SIG_BLOCK, &sigset, &oldSigset) == -1)
    {
        perror(strerror(errno));
        exit(EXIT_FAILURE);
    }

    counter--;

    if (sigprocmask(SIG_SETMASK, &oldSigset, NULL) == -1)
    {
        perror(strerror(errno));
        exit(EXIT_FAILURE);
    }

    char *counterStr;
    printf("%d\n", counter);
    //    if (write(1, counterStr, strlen(counterStr)) == -1) {
    //        perror(strerror(errno));
    //        exit(EXIT_FAILURE);
    //    }

    errno = OLD_ERRNO;
    exit(EXIT_SUCCESS);
}
