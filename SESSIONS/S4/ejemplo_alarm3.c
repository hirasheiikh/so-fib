#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>

void error_y_exit(char *msg)
{
    perror(msg);
    exit(EXIT_FAILURE);
}

int segundos=0;
void tract(int s)
{
    if (s == SIGCHLD){
        char buff[256];
        sprintf(buff,"SOC EL PARE I EL MEU FILL pid=%d HA MORT\n",getpid());
        write(1, buff, strlen(buff) );
        exit(1);
    }
}
   


int main (int argc,char * argv[])
{
    struct sigaction sa;
    sigset_t mask_fill;
    sigset_t mask_pare;
    sigset_t mask;
    

    /* EVITAMOS QUE NOS LLEGUE EL SIGALRM FUERA DEL SIGSUSPEND */
    sigemptyset(&mask);
    sigaddset(&mask, SIGALRM);
    sigaddset(&mask, SIGINT);
    sigaddset(&mask, SIGCHLD);
    sigprocmask(SIG_BLOCK,&mask, NULL);

    /* REPROGRAMAMOS EL SIGNAL SIGCHLD */
    sa.sa_handler = &tract;
    sa.sa_flags = SA_RESTART; 
    sigfillset(&sa.sa_mask); 
    if (sigaction(SIGCHLD, &sa, NULL) < 0) error_y_exit("sigaction");
    
    /*CREAMOS EL PROCESO HIJO*/
    int pid = fork();
    if (pid < 0) error_y_exit("fork");
    else if (pid == 0){
        sigemptyset(&mask); //buido la màscara
        sigaddset(&mask, SIGALRM);
        sigprocmask(SIG_UNBLOCK,&mask,NULL);
        alarm(10);
        execlp("./bucle", "./bucle", (char*)NULL);
    }
    else if (pid > 0){
        sigfillset(&mask_pare);
        sigdelset(&mask_pare, SIGCHLD);
        sigsuspend(&mask_pare);
        exit(1);
    }
    
}
