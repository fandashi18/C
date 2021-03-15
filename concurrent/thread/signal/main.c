#include <signal.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

void * startRoutine1(void * arg);
void * startRoutine2(void * arg);
void sigusr1Handler (int sig,siginfo_t * si, void * ucontext);

pthread_t tid1,tid2;

char gs[] ={'\0'} ;

int main(int argc, char const *argv[])
{
    
    if (pthread_create(&tid1,NULL,startRoutine1,NULL) != 0)
    {
        fprintf(stderr,"Failed create thread");
        exit(EXIT_FAILURE);
    }

    if (pthread_create(&tid1,NULL,startRoutine2,NULL) != 0)
    {
        fprintf(stderr,"Failed create thread");
        exit(EXIT_FAILURE);
    }
      
    pthread_exit(NULL);

    return 0;
}

void * startRoutine1(void * arg){
    struct sigaction sa = {.sa_sigaction = sigusr1Handler,.sa_flags = SA_SIGINFO};
    if (sigaction(SIGUSR1,&sa,NULL) != 0)
    {
        fprintf(stderr,"Failed sigaction");
        exit(EXIT_FAILURE);
    }

    sleep(5);

    fprintf(stdout,"exit~\n");

    return NULL;
}

void * startRoutine2(void * arg){
    const union sigval sv = {.sival_ptr="send from routine2"};
    pthread_sigqueue(tid1,SIGUSR1,sv);
    return NULL;
}

void sigusr1Handler (int sig,siginfo_t * si, void * ucontext) {
    union sigval sg = si->si_value;
    char *sp = (char *)sg.sival_ptr;
    if (write(1,sp,strlen(sp)) == -1)
    {
        perror(strerror(errno));
        exit(EXIT_FAILURE);
    }
    
    if (write(1,"\n",1) == -1)
    {
        perror(strerror(errno));
        exit(EXIT_FAILURE);
    }

}