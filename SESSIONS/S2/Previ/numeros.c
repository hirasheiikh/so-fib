#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_SIZE 8 

int esNumero(char *str) { 
	if (str == NULL) return 0;
	if (str[0] == '-') ++str; 
	for (int i = 0; str[i] != '\0'; ++i) {
		if (!(str[i] >= '0' && str[i] <= '9') || (i >= MAX_SIZE)) return 0;
	}
	return 1;
}

int main(int argc, char *argv[]) {
	int i;
	char buff[256];
	for (i = 1; i < argc; ++i) {
		if (esNumero(argv[i]) == 1) {
			sprintf(buff, "%s es un número\n", argv[i]); 
		} else {
			sprintf(buff, "%s no es un número\n", argv[i]);
		}
		write(1, &buff, strlen(buff));
	}
	//return 0;
}
