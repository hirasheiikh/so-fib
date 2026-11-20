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

void muta_a_PS(char *username){
    execlp("ps", "ps", "-u", username, (char*)NULL);
    error_y_exit("Ha fallado la mutación al ps", 1);
}

int main (int argc,char *argv[]){
    char buff[256];
    if (argc != 2) error_y_exit("Se necesita más de un parámetro", -1);

    int pid = fork();
    if (pid  < 0) error_y_exit("Error en fork", 1);
    sprintf(buff, "Soy el proceso %d \n", getpid());
    write (1, &buff, strlen(buff));

    if (pid == 0){
        sprintf(buff, "El nombre del parámetro es: %s\n", argv[1]);
        write (1, &buff, strlen(buff));
        muta_a_PS(argv[1]);
    }
    while(1);


}
