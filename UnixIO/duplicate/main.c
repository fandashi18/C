/**
 * 重定向标准输出到文件./outfile
 * 
 * 编译指令：
 * gcc -std=c11 -O1 main.c
 */
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    int fd;
    char *filename = "/home/fmy/Repository/C/UnixIO/duplicate/outfile";
    if (-1 == (fd = open(filename, O_RDWR | O_CREAT | O_APPEND, S_IRWXU | S_IRGRP | S_IROTH)))
    {
        perror(strerror(errno));
        exit(EXIT_FAILURE);
    }

    if (-1 == dup2(fd,1))
    {
        perror(strerror(errno));
        exit(EXIT_FAILURE);
    }
    
    fprintf(stdout,"dump2 me.");
    return 0;
}
