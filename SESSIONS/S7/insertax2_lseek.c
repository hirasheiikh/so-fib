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
    sprintf(buff, "Usage: ./insertarx2_lseek\n");
    write(1, buff, strlen(buff));
    exit(EXIT_FAILURE);
}

void error_y_exit(char* msg) {
    perror(msg);
    exit(0);
}

int main(int argc, char *argv[]) {
	if (argc < 2) Usage();
	else {
		char buff[256];
		char buffX[256];
		int f1 = open(argv[1], O_RDWR);
		int f2 = lseek(f1, 0, SEEK_END);
		if (f1 == -1) error_y_exit("Open");
		sprintf(buffX, "X");
		int x = atoi(argv[2]);
		while (x != f2) {
			lseek(f1, x, SEEK_SET);
			write(1,buffX,strlen(buffX));
			++x;
		}
		close(f1);
	}
}