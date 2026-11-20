// Pipes amb nom
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

int main(int argc, char *argv[]) {
	char buff[256];
	int fd = open("./pipe",O_WRONLY|O_NONBLOCK);
	if (fd < 0 && errno == ENXIO) {
		perror("Esperant lector");
	}
	fd = open("./pipe",O_WRONLY);
	int ret;
	if ((ret = read(fd,buff,ret)) > 0) {
		write(fd,buff,ret);
	}
}