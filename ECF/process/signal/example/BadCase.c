/**
 * 信号不会排队，如果已经存在了某类型的信号，后续的信号会被丢弃。
 * 
 * gcc -std=gnu17 -O1 BadCase.c -o bad.out
 * 
 * 输出：
 * child 15122 print
 * child 15123 print
 * child 15124 print
 * catch
 * catch
 */
#include <unistd.h>
#include <stdio.h>
#include <wait.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
void childHandler(int sig);

int main()
{
    if (SIG_ERR == signal(SIGCHLD, &childHandler))
    {
        perror(strerror(errno));
        exit(0);
    }

    for (int i = 0; i < 3; ++i)
    {
        if (0 == fork())
        {
            printf("child %d print\n", getpid());
            exit(0);
        }
    }
    pause();
    return 0;
}

void childHandler(int sig)
{
    const int oldErrno = errno;
    if (-1 == write(1, "catch\n", 6))
    {
        errno = oldErrno;
        exit(0);
    }

    sleep(1);
    errno = oldErrno;
}
