#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

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
    char buff[256];
	int fd = open("./pipe",O_RDONLY); //mknod("pipe_nomenada", S_IFFO|0644,0)
	if (fd == -1) error_y_exit("The pipe can't be opened");
	int ret;
	while ((ret = read(fd,buff,ret)) > 0) {
		write(1,buff,ret);
	}
	close(fd);
}