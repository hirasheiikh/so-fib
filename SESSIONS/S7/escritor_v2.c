#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <signal.h>

void Usage() {
    char buff[128];
    sprintf(buff, "Usage: ./insertarx2_mmap\n");
    write(1, buff, strlen(buff));
    exit(EXIT_FAILURE);
}

void error_y_exit(char* msg) {
    perror(msg);
    exit(0);
}

int main(int argc, char *argv[]) {}