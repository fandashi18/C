#include <stdio.h>
#include "math.h"

int main(int argc, char const *argv[])
{
    static int result;
    result = add(1,2);
    printf("Add result is %d\n",result);

    result = sub(1,2);
    printf("Sub result is %d\n",result);
    
    return 0;
}
