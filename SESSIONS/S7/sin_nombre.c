#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <string.h>
#include <signal.h>
#include <syscall.h>

void Usage(){
    char buff[256];
    sprintf(buff, "Usage: ./sin_nombre.c");
    write(1, &buff, strlen(buff));
    exit(0);
}

void error_y_exit(char* msg){
    perror(msg);
    exit(EXIT_FAILURE);
}

int main (int argc, char* argv[]){
    int pipe_fd[2];
    pipe(pipe_fd);
    char buff[256];
    int pid = fork();

    //fill 
        //cuyo canal de entrada estándar deberá estar asociado al extremo de lectura de la pipe
    if (pid == 0){
        dup2(pipe_fd[0],0); //dupliquem el canal de lectura de la pipe al canal de lectura del procés fill
        close(pipe_fd[0]); //tanquem els canals de la pipe. 
        close(pipe_fd[1]); // important bloquejar els file descriptors que no fem servir per evitar BLOQUEJOS
        execlp("cat","cat",NULL); //mutem per executar cat
    }

    //pare
    else if (pid > 0){
        close(pipe_fd[0]);
        sprintf(buff, "Inicio\n");
        /*dup2(pipe_fd[1],1);
        close(pipe_fd[1]);*/
        write(pipe_fd[1],buff,strlen(buff));
        close(pipe_fd[1]);
        waitpid(-1,NULL,0);
        sprintf(buff,"Fin\n");
        write(1,buff,strlen(buff));
    }

    else error_y_exit("fork");
}