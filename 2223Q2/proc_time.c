#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <signal.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>

void Usage(){
    char buff[256];
    sprintf(buff, "Usage: ./proc_time PID\n");
    write(1, &buff, strlen(buff));
    exit(0);
}

void error_y_exit(char *msg){
    perror(msg);
    exit(EXIT_FAILURE);
}

int main(int argc, char argv[]){ 
    if (argc != 2) Usage();
    char buff[256];
    char c;
    sprintf(buff, "/proc/%d/stat", argv[1]);
    int fd = open(buff, O_RDONLY);
    if (fd < 0) exit(255);
    close(0);
    char c;
    for (int i = 0; i < 13; ++i){
        while(read(fd, &c, sizeof(char)) > 0 && c != ' ')
    }
    

}