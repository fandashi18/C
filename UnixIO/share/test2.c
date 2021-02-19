/**
 * 进程只维护描述符表，内核维护打开文件表与v-node表，且只有调用open才能在打开文件表中增加新的条目。
 * 
 * 编译指令：
 * gcc -std=c11 -O1 test2.c
 * 
 * 输出:
 * child : c is /
 * parent : c is *
 */ 
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char const *argv[])
{
    char c;
    char * filename = "/home/fmy/Repository/C/UnixIO/read/test2.c";
    int fd;
    if (-1 == (fd = open(filename,O_RDONLY,0)))
    {
        perror(strerror(errno));
        exit(EXIT_FAILURE);
    }
    
    if (0 == fork())
    {
        if (-1 == read(fd,&c,1))
        {
            perror(strerror(errno));
            exit(EXIT_FAILURE);
        }

        printf("child : c is %c\n",c);
        exit(EXIT_SUCCESS);
    }

    wait(NULL);

    if (-1 == read(fd,&c,1))
    {
        perror(strerror(errno));
        exit(EXIT_FAILURE);
    }
    printf("parent : c is %c\n",c);
    
    return 0;
}
