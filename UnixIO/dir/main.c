#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <dirent.h>

int main() {
    DIR * dir;
    if (NULL == (dir = opendir("/home/fmy/CLionProjects/Pratice/"))) {
        perror(strerror(errno));
        exit(EXIT_FAILURE);
    }
    struct dirent * dirEntry;
    while ((dirEntry = readdir(dir)) != NULL) {
        fprintf(stdout, "name : %s\n", dirEntry->d_name);
    }

    if (-1 == closedir(dir)) {
        perror(strerror(errno));
        exit(EXIT_FAILURE);
    }

    return 0;
}
