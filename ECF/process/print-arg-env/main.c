#include <unistd.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
    char *newargv[] = {"./main2", "hello", NULL};
    char *newenvp[] = {"name=Mike", NULL};

    int result = execve("./main2", newargv, newenvp);
    if (result == -1)
    {
        perror("execve failed");
    }
    
    return 0;
}
