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
    static char * s = "\nCatch signal.\n";
    /**
     * 3.处理信号
     * 相比printf，write函数更安全。
     * 因为只要写入至少1个字节，就可以避免被随时可能发生的信号处理程序造成的中断。 
     */
    write(STDOUT_FILENO,s,strlen(s));
    exit(EXIT_SUCCESS);
}