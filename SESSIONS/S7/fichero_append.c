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
    sprintf(buff, "Usage: ./append\n");
    write(1, buff, strlen(buff));
    exit(EXIT_FAILURE);
}

void error_y_exit(char* msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
	if (argc < 2) Usage();
    int fd,ini,fi;
    char buff[256];
    if ((fd = open(argv[1], O_RDWR)) < 0) error_y_exit("open");
    ini = 0;
    if ((fi = lseek(fd, 0, SEEK_END)) < 0) error_y_exit("lseek");
    char c;
    lseek(fd, ini, SEEK_SET);
    while ((read(fd, &c, sizeof(char) > 0) && ini < fi)) {
        lseek(fd, 0, SEEK_END);
        write(fd, &c, sizeof(char));
        ++ini;
        lseek(fd, ini, SEEK_SET);
    }
	
}