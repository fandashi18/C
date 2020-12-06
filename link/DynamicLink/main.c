#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

int main(int argc, char const *argv[])
{
    static void * handle;
    static int (* add)(int,int);

    handle = dlopen("./libmath.so",RTLD_LAZY);
    if (!handle)
    {
        printf("error ：%s\n", dlerror());
        exit(1);
    }
    
    add = dlsym(handle,"add");
    if (!add)
    {
        printf("error ：%s\n", dlerror());
        exit(1);
    }

    int result = add(1,2);
    printf("result is %d\n",result);

    return 0;
}
