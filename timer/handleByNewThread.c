/**
 * 需要下载glibc-2.31文件：wget http://ftp.gnu.org/gnu/glibc/glibc-2.31.tar.gz
 * 
 * 链接rt与pthread库
 * 
 * 输出：
 * main thread's id is 140737351591744
 * task:Caller name is handleByNewThre,my tid is 140737351587584,my name is handleByNewThre
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

#define THREAD_NAME_LEN 16

inline void errHanlder();

void errHanlder()
{
    perror(strerror(errno));
    exit(EXIT_FAILURE);
}

void task(union sigval);

void task(union sigval sv)
{
    char threadNameArr[THREAD_NAME_LEN];
    if (pthread_getname_np(pthread_self(), threadNameArr, THREAD_NAME_LEN) != 0)
    {
        errHanlder();
    }

    printf("task:Caller name is %s,my tid is %ld,my name is %s\n",
           (char *)sv.sival_ptr, pthread_self(), threadNameArr);
}

int main(int argc, char const *argv[])
{
    printf("main thread's id is %ld\n", pthread_self());

    char threadNameArr[THREAD_NAME_LEN];
    if (pthread_getname_np(pthread_self(), threadNameArr, THREAD_NAME_LEN) != 0)
    {
        errHanlder();
    }

    union sigval sv = {.sival_ptr = threadNameArr};
    struct sigevent sev = {.sigev_notify = SIGEV_THREAD, .sigev_value = sv, ._sigev_un._sigev_thread._function = task};
    timer_t timerId;
    if (timer_create(CLOCK_REALTIME, &sev, &timerId) != 0)
    {
        errHanlder();
    }

    struct itimerspec its = {.it_value.tv_sec = 1, .it_value.tv_nsec = 0};
    if (timer_settime(timerId, 0, &its, NULL) != 0)
    {
        errHanlder();
    }

    sleep(4);

    return 0;
}
