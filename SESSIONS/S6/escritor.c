// Pipes amb nom
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void error_y_exit(char* msg) {
	perror(msg);
}

int main(int argc, char *argv[]) {
	char buff[256];
	int fd = open("./pipe",O_WRONLY);
	if (fd == -1) error_y_exit("Error en obrir pipe");
	int ret;
	while ((ret = read(fd,buff,ret)) > 0) {
		write(fd,buff,ret);
	}
	close(fd);
}