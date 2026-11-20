#include <stdlib.h>
#include <string.h>
#include "socketMng.c"

void error_y_exit(char* msg) {
	perror(msg);
}

int main (int argc, char *argv[]) {
	int socketFD;
	int connectionFD;
	int ret;
	char buff[256];
	if (argc != 2) {
		error_y_exit("Usage: prServerSocket socketPath\n");
	}
	socketFD = createSocket(argv[1]);
	connectionFD = clientConnection(argv[1]);
	ret = read(connectionFD, buff, sizeof(buff));
	while (ret > 0) {
		write(connectionFD, buff, ret);
		ret = read(0, buff, sizeof(buff));
	}
	closeConnection(connectionFD);
	deleteSocket(socketFD, argv[1]);
}