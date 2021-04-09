#include <signal.h>
#include <time.h>
#include <stdio.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>

void sigHandler(int);

static long unsigned int count = 0;

int main(int argc, char const *argv[])
{
    signal(SIGALRM, sigHandler);
    timer_t tmid;
    struct timespec tsv = {.tv_sec = 1};

    struct itimerspec its = {.it_value = tsv, .it_interval = tsv};
    struct sigevent se = {.sigev_notify = SIGEV_SIGNAL,
                          .sigev_signo = SIGALRM};

    if (timer_create(CLOCK_REALTIME, &se, &tmid) != 0)
    {
        perror(strerror(errno));
        exit(EXIT_FAILURE);
    }

    timer_settime(tmid, TIMER_ABSTIME - 1, &its, NULL);

    while (1)
    {
        pause();
    }

    return 0;
}

void sigHandler(int sig)
{
    printf("sig %d handled %lu times\n", sig, ++count);
    if (count == 10)
    {
        exit(EXIT_SUCCESS);
    }
    
}