#include "mis_funciones.h"

#define MAX_SIZE 8 


int main(int argc, char *argv[]) {
	int suma = 0;
	int total = 0;
	int i;
	char buff[256];
	for (i = 1; i < argc; ++i) {
		if (esNumero(argv[i])) {
			if (total == 0) suma += mi_atoi(argv[i]); 
		} 
		else if (total == 0) total = i;
	}
	if (total == 0) printf("La suma es %i\n",suma);
	else printf("Error: el parámetro \"%s\" no es un número\n", argv[total]);
}
