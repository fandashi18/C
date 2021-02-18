/**
 * 利用内存映射打印文件内容到标准输出。
 *
 * 编译指令：
 * gcc -std=c11 -O1 main.c
 */ 
#include <sys/mman.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    int fd;
    if (-1 == (fd = open("/home/fmy/CProjects/MMAP/main.c", O_RDONLY)))
    {
      perror(strerror(errno));
      exit(EXIT_FAILURE);
    }

    struct stat stat;
    if (-1 == fstat(fd,&stat))
    {
        perror(strerror(errno));
        exit(EXIT_FAILURE);
    }
    
    int size = stat.st_size;

    void *bufp = mmap(NULL, size, PROT_READ, MAP_PRIVATE, fd, 0);
    if (bufp == MAP_FAILED)
    {
        fprintf(stdout, "failed mmap\n");
        exit(EXIT_FAILURE);
    }

    if (-1 == write(1,bufp,size))
    {
        perror(strerror(errno));
        exit(EXIT_FAILURE);
    }
    

    if (-1 == munmap(bufp, size))
    {
        perror(strerror(errno));
        exit(EXIT_FAILURE);
    }

    return 0;
}
