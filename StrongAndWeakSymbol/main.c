#include <stdio.h>

signed int id; //未初始化全局变量，即弱符号

signed int increId();

int main(int argc, char const *argv[])
{
    printf("id is %d\n",id);
    signed int result = increId();
    printf("result is %d\n",result);

    return 0;
}

signed int increId(){
    return ++id;
}