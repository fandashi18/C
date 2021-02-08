#include "fmy-io-ext/fmy-io.h"
#include <stdio.h>

int main(int argc, char const *argv[])
{
    char string[12];
    myitos(-1234,string);
    printf("%s\n",string);
    return 0;
}
