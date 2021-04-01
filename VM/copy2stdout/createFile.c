#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

static char buf[1024];

int main(int argc, char const *argv[])
{
    for (int i = 0; i < 1024; i++)
    {
        buf[i] = 'a';
    }

    int fd = open("/home/fmy/Downloads/a.txt", O_RDWR | O_CREAT, S_IRWXU | S_IRGRP);

    for (int i = 0; i < 10240; i++)
    {
        write(fd, buf, 1024);
    }

    close(fd);
    return 0;
}
