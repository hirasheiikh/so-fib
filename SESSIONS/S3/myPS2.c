#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <sys/wait.h>


void error_y_exit(char *msg,int exit_status){
    perror(msg);
    exit(exit_status);
}

int main (int argc,char *argv[]){
    char buff[256];
    if (argc < 2) error_y_exit("Se necesita más de un parámetro", -1);

  
    sprintf(buff, "Soy el proceso %d \n", getpid());
    write (1, &buff, strlen(buff));
    
    sprintf(buff, "El nombre del parámetro es:\n");
    for(int i=1; i<argc; ++i){
          sprintf(buff, "parametre %d: %s\n", i, argv[i]);
          write (1, &buff, strlen(buff));
    }


    for (int i=1; i<argc; ++i){
        int pid = fork();
        if (pid == -1)error_y_exit("No existe hijos", -1);
        else if (pid==0) {
            sprintf(buff, "Soy el proceso %d \n", getpid());
            write (1, &buff, strlen(buff));
            exit(0);
        }
        waitpid(-1, NULL, 0);


    }

}
