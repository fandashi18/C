/**
 * 输出：

    current time is Sat Jun 19 22:03:43 2021
    sig 14 handled
    current time is Sat Jun 19 22:03:43 2021
    process have caught a signal

    Updating absolute time value as now time plus 5s delay time

    current time is Sat Jun 19 22:03:43 2021
    sig 14 handled
    current time is Sat Jun 19 22:03:47 2021
    process have caught a signal
 
 */ 
#define _GNU_SOURCE

#include <signal.h>
#include <time.h>
#include <stdio.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <pthread.h>

inline void errHanlder();

void errHanlder()
{
    perror(strerror(errno));
    exit(EXIT_FAILURE);
}

void showNowtime();

void sigHandler(int);

void showNowtime()
{
    time_t curTime;
    if (time(&curTime) == (time_t)-1)
    {
        errHanlder();
    }

    printf("current time is %s", asctime(localtime(&curTime)));
}

void sigHandler(int sig)
{
    printf("sig %d handled\n", sig);
    showNowtime();
}

int main(int argc, char const *argv[])
{
    if (signal(SIGALRM, sigHandler) == SIG_ERR)
    {
        errHanlder();
    }

    struct sigevent sev = {.sigev_notify = SIGEV_SIGNAL, .sigev_signo = SIGALRM};
    timer_t timerId;
    if (timer_create(CLOCK_REALTIME, &sev, &timerId) != 0)
    {
        errHanlder();
    }

    showNowtime();
    
    struct itimerspec its = {.it_value.tv_sec = 5, .it_value.tv_nsec = 0};
    if (timer_settime(timerId, TIMER_ABSTIME, &its, NULL) != 0)
    {
        errHanlder();
    }

    if (pause() == -1)
    {
        printf("process have caught a signal\n");
    }

    time_t nowTime;
    if (time(&nowTime) == (time_t)-1)
    {
        errHanlder();
    }

    printf("\nUpdating absolute time value as now time plus 5s delay time\n\n");
    
    showNowtime();

    its.it_value.tv_sec = nowTime + 5;

    if (timer_settime(timerId, TIMER_ABSTIME, &its, NULL) != 0)
    {
        errHanlder();
    }

    if (pause() == -1)
    {
        printf("process have caught a signal\n");
    }

    return 0;
}
