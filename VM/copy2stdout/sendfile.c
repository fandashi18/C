#include <sys/sendfile.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    int fd = open("/home/fanmingyang/Downloads/a.txt", O_RDONLY);
    struct stat fileinfo;
    fstat(fd,&fileinfo);
    sendfile(1,fd,NULL,fileinfo.st_size);
    return 0;
}
