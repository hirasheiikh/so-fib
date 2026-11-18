#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(int argc,char *argv[])
{
char buf[80];
int i;
	for (i=0;i<argc;i++){
		if (i==0){
			sprintf(buf,"El argumento %d es %s (es el nombre del ejecutable)\n",i,argv[i]);
		}else{
			sprintf(buf,"El argumento %d es %s\n",i,argv[i]);
		}
		write(1,buf,strlen(buf));
	}
	return 0;
}

// Ejecutamos los siguientes ejemplos:
/*
	# ./listaParametros --> argc = 1; argv[0] = ./listaParametros
	# ./listaParametros a --> argc = 2; argv[0] = ./listaParametros; argv[1] = a
	# ./listaParametros a b --> argc = 3; argv[0] = ./listaParametros; argv[1] = a; argv[2] = b
	# ./listaParametros a b c --> argc = 4; argv[0] = ./listaParametros; argv[1] = a; argv[2] = b; argv[3] = c
	# ./listaParametros 1 2 3 4 5 6 7 --> argc = 8; argv[0] = ./listaParametros; argv[1] = 1; argv[2] = 2; argv[3] = 3; argv[4] = 4; argv[5] = 5; argv[6] = 6; argv[7] = 7
	-Los números son recibidos como cadenas de carácteres ya que el vector argv es de chars. A menos que hagamos atoi(argv[i])
	el contenido será un char.
*/