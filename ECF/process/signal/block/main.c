/**
 * 编译命令：gcc -std=gnu11 -O0 -o main main.c
 */ 
#include <signal.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
    static sigset_t mask, prev_mask;
    //1.初始化信号表为空
    sigemptyset(&mask);

    /**
     * 2.阻塞INT信号
     */
    sigaddset(&mask, SIGINT);
    sigprocmask(SIG_BLOCK, &mask, &prev_mask);
    printf("Block signal INT\n");

    for (int i = 0; i < 6; i++)
    {
        printf("Sleep %ds,total 6s\n", i + 1);
        sleep((unsigned int)1);
    }

    //3.解除对INT信号的阻塞
    sigprocmask(SIG_SETMASK, &prev_mask, NULL);
    printf("Has deleted signal INT from block set.Now you can send INT signal to this process\n");

    for (int i = 0; i < 6; i++)
    {
        printf("Sleep %ds,total 6s\n", i + 1);
        sleep((unsigned int)1);
    }

    return 0;
}
