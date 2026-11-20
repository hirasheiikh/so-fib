#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int valor;
    char buffer[256];
    int total = 0;

    while (read(0, &valor, sizeof(int)) > 0) {
        sprintf(buffer, "Llegit número: %d\n", valor);
        write(1, buffer, strlen(buffer));
        total += valor;
    }

    sprintf(buffer, "Suma total rebuda: %d\n", total);
    write(1, buffer, strlen(buffer));
    return 0;
}
