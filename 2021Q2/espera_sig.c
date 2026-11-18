#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <sys/wait.h>
#include <stdio.h>
#include <errno.h>
#include <sys/types.h>
#include <fcntl.h>


void Usage(){
    char buff[256];
    sprintf(buff, "Usage: ./espera_sig\n");
    write(1, &buff, strlen(buff));
    exit(0);
}

void error_y_exit(char *msg){
    perror(msg);
    exit(EXIT_FAILURE);
}

void func(int s){
    char buff[256];
    if (s == SIGINT){
        sprintf(buff, "SIGINT\n");
        write(2,&buff,strlen(buff));
        exit(1);
    }
    if (s == SIGUSR1){
        sprintf(buff, "SIGUSR1\n");
        write(2, &buff, strlen(buff));
        exit(2);
    }
    if (s == SIGUSR2){
        sprintf(buff, "SIGUSR2\n");
        write(2, &buff, strlen(buff));
        exit(3);
    }
};

int main(int argc, char *argv[]){
    char buff[256];
    if (argc != 1) Usage();

    struct sigaction sa;
    sa.sa_handler = func;
    sa.sa_flags = 0;
    sigemptyset(&sa.sa_mask);
    if (sigaction(SIGINT, &sa, NULL) < 0) error_y_exit("sigaction");
    if (sigaction(SIGUSR1, &sa, NULL) < 0) error_y_exit("sigaction");
    if (sigaction(SIGUSR2, &sa, NULL) < 0) error_y_exit("sigaction");


    sigset_t mask;
    sigfillset(&mask);
    sigdelset(&mask, SIGINT);
    sigdelset(&mask, SIGUSR1);
    sigdelset(&mask, SIGUSR2);
    sigsuspend(&mask);

}