#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void Usage(){
    char buff[256];
    printf(buff, "Usage(): El programa rep 0 o >1 paràmetres\n");
    write(1, buff, strlen(buff));
    exit(0);
}

void error_y_exit(char* msg){
    perror(msg);
    exit(EXIT_FAILURE);
}

int main (int argc, char *argv[]){
    char buff[256];
    if (argc != 2) Usage();
    int PID = atoi(argv[1]);
    sprintf(buff,"Hola, soy el padre y mi PID es %d.\n",PID);
    write(1, buff, strlen(buff));
    int PIDfill = fork();
    sprintf(buff, "Hola, soy el hijo y mi PID es %d.\n", PIDfill);
    write(1, buff, strlen(buff));

    while(1);
}
