/**
 * Java与C++中的提高一种较高层次的异常，c中是更加结构化的。
 * 可以把Java中的catch看作是setjmp，throw看作是longjmp。
 * 
 * 编译：
 * gcc -std=gnu11 -O1 Nonlocal-jump.c
 * 
 * 输出：
 * case error1
 */ 
#include <stdio.h>
#include <setjmp.h>

static void foo();
static void bar();

static jmp_buf env;
static int error0 = 0;
static int error1 = 1;

int main(int argc,char ** argv) {
    switch (setjmp(env)) {
        case 0:
            foo();
            break;
        case 1:
            printf("case error0\n");
            break;
        case 2:
            printf("case error1\n");
            break;
    }

    return 0;
}

void foo(){
    if (error0) {
        longjmp(env, 1);
    }
    bar();
}

void bar(){
    if (error1) {
        longjmp(env,2);
    }
    printf("bar exit normally\n");
}