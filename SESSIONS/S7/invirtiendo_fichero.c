#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <string.h>
#include <signal.h>
#include <syscall.h>
#include <fcntl.h>

void Usage(){
    char buff[256];
    sprintf(buff, "Usage: ./invirtiendo_fichero\n");
    write(1, &buff, strlen(buff));
    exit(0);
}

void error_y_exit(char* msg){
    perror(msg);
    exit(EXIT_FAILURE);
}

int main (int argc, char* argv[]){
    char buff[256];
    if (argc < 2) Usage();
    int fd1, fd2, ini;
    if ((fd1 = open(argv[1], O_RDONLY)) < 0) error_y_exit("open");
    if (lseek(fd1, 0, SEEK_END) < 0) error_y_exit("lseek");
    if ((fd2 = creat("out", 0600)) < 0) error_y_exit("creat");
    char c;
    lseek(fd1, -1, SEEK_END);
    ini = -2;
    int bool = 0;
    while (!bool && read(fd1, &c, sizeof(char) > 0)) {
        write(fd2, &c, sizeof(char));
        if (lseek(fd1, ini, SEEK_END) < 0) bool = 1;
        --ini;
    }
}