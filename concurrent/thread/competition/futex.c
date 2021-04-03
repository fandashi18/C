#include <linux/futex.h>
#include <sys/time.h>
#include <stdint.h>
#include <sys/mman.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <stdatomic.h>
#include <sys/types.h>
#include <sys/wait.h>

#define SIZE 100000

static void *count;
static void *buf;

static uint32_t zero = 0;
static uint32_t one = 1;

static void test(int);
static void countRoutine(int *);

static int futex(uint32_t *uaddr, int futex_op, uint32_t val,
                 const struct timespec *timeout, uint32_t *uaddr2, uint32_t val3)
{
    return syscall(SYS_futex, uaddr, futex_op, val,
                   timeout, uaddr2, val3);
}

/* 
 * Acquire the futex pointed to by 'futexp': wait for its value to
 * become 1, and then set the value to 0. 
 */
static void fwait(uint32_t *futexp)
{
    long s;
    while (1)
    {

        /* Is the futex available? */
        const uint32_t one = 1;
        if (atomic_compare_exchange_strong(futexp, &one, 0))
            break;

        /* Futex is not available; wait. */
        s = futex(futexp, FUTEX_WAIT, 0, NULL, NULL, 0);
        if (s == -1 && errno != EAGAIN)
        {
            perror(strerror(errno));
            exit(EXIT_FAILURE);
        }
    }
}

/* 
 * Release the futex pointed to by 'futexp': if the futex currently
 * has the value 0, set its value to 1 and the wake any futex waiters,
 * so that if the peer is blocked in fwait(), it can proceed. 
*/
static void fpost(uint32_t *futexp)
{
    long s;
    const uint32_t zero = 0;
    if (atomic_compare_exchange_strong(futexp, &zero, 1))
    {
        s = futex(futexp, FUTEX_WAKE, 1, NULL, NULL, 0);
        if (s == -1)
        {
            perror(strerror(errno));
            exit(EXIT_FAILURE);
        }
    }
}

static void countRoutine(int *arg)
{
    for (int i = 0; i < SIZE; i++)
    {
        fwait((uint32_t *)buf);
        (*arg)++;
        fpost((uint32_t *)buf);
    }
}

static void test(int num)
{
    for (int i = 0; i < num; i++)
    {
        count = mmap(NULL, 4, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANON, -1, 0);
        if (count == MAP_FAILED)
        {
            perror(strerror(errno));
            exit(EXIT_FAILURE);
        }
        *((int *)count) = 0;

        buf = mmap(NULL, 4, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANON, -1, 0);
        if (buf == MAP_FAILED)
        {
            perror(strerror(errno));
            exit(EXIT_FAILURE);
        }

        *((uint32_t *)buf) = 1; //初始化互斥字

        pid_t pid = fork();
        if (pid == -1)
        {
            perror(strerror(errno));
            exit(EXIT_FAILURE);
        }

        if (pid == 0)
        {
            countRoutine((int *)count);
            exit(EXIT_SUCCESS);
        }

        countRoutine((int *)count);

        wait(NULL);//等待任意子进程的终止信号
        printf("child : count = %d\n", *(int *)count);
    }
}

int main(int argc, char const *argv[])
{
    test(100);
    return 0;
}
