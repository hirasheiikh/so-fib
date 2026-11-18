#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#define MAX_SIZE 8

int esNumero(char *str)
{
    //int bool = 1;
    if (str == NULL) return 0; //123
    int i = 0;
    int count = 0;
    if (str[i] == '-'){
        ++i; // argv[1] == '-' llavors el número comença a i = 2
        if (str[i] == '\0') return 0;
    }
    int j = i; //si '-' j = 2, sino j = 1
    while (str[j] != '\0'){ 
        if (str[j] < '0' || str[j] > '9') return 0;
        ++j; //argv[1], argv[2], argv[3]
        ++count; //quantitat de xifres --- count = 3
    }
    if (count > MAX_SIZE) return 0; 
    else return 1;
}

int main(int argc, char *argv[])
{
    char *p = argv[1]; // el punter p apunta a &argv[0] --> ./numeros
    char buff[256];
    int bool = esNumero(p);
    sprintf(buff, "%d\n", bool);
    write(1, buff, strlen(buff));

}