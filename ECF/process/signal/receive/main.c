#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

void sigint_handler(int sig);

int main(int argc, char const *argv[])
{
    //1.设置信号处理程序
    signal(SIGINT, sigint_handler);

    //2.等待信号
    printf("Pause to wait signal int \n");
    int pauseResult = pause();
    if (pauseResult == -1)
    {
        fprintf(stderr,"pause error : %s\n",strerror(errno));
    }
    
    //4.信号处理完毕，主程序继续执行
    printf("Continue run~");

    return 0;
}

void sigint_handler(int sig)
{
    //3.处理信号
    printf("\nCatch signal %d\n", sig);
    exit(EXIT_SUCCESS);
}