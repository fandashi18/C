#include "fmy-io-ext/fmy-io.h"
#include <stdio.h>

int main(int argc, char const *argv[])
{
    char string[12];
    myitos(-1234,string);
    printf("%s\n",string);

    char * s = "-12345";
    printf("%d\n",mystoi(s));
    return 0;
}
