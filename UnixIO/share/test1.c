/**
 * 每个描述符独立地关联着特定文件的位置。
 * 
 * 编译指令：
 * gcc -std=c11 -O1 test1.c
 * 
 * 输出：
 * c = /
 * c = /
 */ 
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>


int main() {
    char * filename = "/home/fmy/Repository/C/UnixIO/read/test1.c";
    int fd1,fd2;
    if ((fd1 = open(filename, O_RDONLY, 0)) == -1) {
        perror(strerror(errno));
        exit(EXIT_FAILURE);
    }

    if ((fd2 = open(filename, O_RDONLY,0)) == -1) {
        perror(strerror(errno));
        exit(EXIT_FAILURE);
    }

    char c;
    if (read(fd1, &c, 1) == -1) {
        perror(strerror(errno));
        exit(EXIT_FAILURE);
    }
    fprintf(stdout, "c = %c\n", c);

    if (read(fd2, &c, 1) == -1) {
        perror(strerror(errno));
        exit(EXIT_FAILURE);
    }

    fprintf(stdout, "c = %c\n", c);
    return 0;
}
