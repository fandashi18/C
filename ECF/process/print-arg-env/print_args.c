#include <stdio.h>
#include <stdlib.h>

extern char **environ;

int main(int argc, char const *argv[])
{
    if (argc >= 1)
    {
        for (int i = 0; i < argc; i++)
        {
            printf("arg : %s\n",argv[i]);
        }   
    }

    if (environ)
    {
        for (int i = 0; environ[i] != NULL; i++)
        {
            printf("env : %s\n",environ[i]);
        }
        
    }

    if (environ)
    {
        char * v = getenv("name");
        if (v)
        {
            printf("get name : %s\n",v);
        }
    }
    

    return 0;
}
