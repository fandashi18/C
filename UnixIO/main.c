#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <ftw.h>

int main() {
    int fd;
    if (-1 == (fd = open("/home/fmy/CLionProjects/Pratice/main.c", O_RDONLY, 0))) {
        perror(strerror(errno));
        exit(EXIT_FAILURE);
    }

    fprintf(stdout, "%d\n", fd);

    struct stat structStat;
    if (-1 == fstat(fd, &structStat)) {
        perror(strerror(errno));
        exit(EXIT_FAILURE);
    } else {
        fprintf(stdout, "File type and mode = %d\n", structStat.st_mode);
        fprintf(stdout, "Total size, in bytes = %u\n", structStat.st_size);
        fprintf(stdout, "is reg ? %d\n", S_ISREG(structStat.st_mode));
        fprintf(stdout, "user can read ? %d\n", S_IRUSR & structStat.st_mode);
    }


    if (-1 == close(fd)) {
        perror(strerror(errno));
        exit(EXIT_FAILURE);
    }

    return 0;
}
