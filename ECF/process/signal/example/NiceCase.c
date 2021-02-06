/**
 * 信号不会排队，因此受到第一个子进程终止信号时就开始wait所有的子进程，直到所有的子进程都被wait完毕，再终止循环。
 *
 * gcc -std=gnu17 -O1 NiceCase.c -o nice.out
 *
 * 输出：
 * child 5601 print
 * child 5602 print
 * child 5603 print
 * wait
 * wait
 * wait
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

    while (waitpid(-1, NULL, WUNTRACED) > 0)
    {
        write(1, "wait\n", 5);
    }

    if (errno != ECHILD)
    {
        write(2, "error\n", 6);
    }

    sleep(1);
    errno = oldErrno;
}
