#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <sys/wait.h>


unsigned int char2int(char c){
	return (c - '0');
}

int mi_atoi(char *s){
    int value;
	int sign;

	value = 0;
	sign = 1;
	while (*s == '\n' || *s == ' ' || *s == '\t' || *s == '\r' ||
		*s == '\v' || *s == '\f'){
		++s;
	}
	if (*s == '+' || *s == '-'){
		if (*s == '-')
			sign = 0;
		s++;
	}
	while ((*s) >= '0' && (*s) <= '9'){
		value *= 10;
		value = (sign ? value + (char2int(*s)) : value - (char2int(*s)));
		s++;
	}
	return (value);

}

int esNumero(char *str) { 
	if (str == NULL) return 0;
	if (str[0] == '-') ++str; 
	for (int i = 0; str[i] != '\0'; ++i) {
		if (!(str[i] >= '0' && str[i] <= '9') || (i >= MAX_SIZE)) return 0;
	}
	return 1;
}
