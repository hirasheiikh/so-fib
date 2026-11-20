#include <stdlib.h>
#include <string.h>
#include "socketMng.c"

void error_y_exit(char* msg) {
	perror(msg);
}

int main (int argc, char *argv[]) {
	int connectionFD;
	int ret;
	char buff[256];
	if (argc != 2) {
		error_y_exit("Usage: prClientSocket socketPath\n");
	}
	connectionFD = clientConnection(argv[1]);
	ret = read(connectionFD, buff, sizeof(buff));
	while (ret > 0) {
		write(1, buff, ret);
		ret = read(connectionFD, buff, sizeof(buff));
	}
	closeConnection(connectionFD);
}