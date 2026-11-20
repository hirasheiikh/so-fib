#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "socketMng.h"

#define MAXSTRING	1024

int main (int argc, char *argv[])
{
				int connectionFD;
				int ret;
				char buffer[MAXSTRING], buffer2[2048];
				char* hello = "Hola servidor!";

				if (argc != 3)
				{
								sprintf (buffer, "Usage: %s socketPath num_peticiones\n", argv[1]);
								write (2, buffer, strlen (buffer));
								exit (1);
				}
				uint peticiones = (uint)atoi(argv[2]);
				for (uint p = 0; p < peticiones; p++){

				sprintf(buffer,"Creando peticion %d\n", p);
				write(1,buffer, strlen(buffer));

				// Encapsular este codigo en 1 thread
				connectionFD = clientConnection (argv[1]);
				if (connectionFD < 0)
				{
								perror ("Error establishing connection\n");
								exit (1);
				}

				send(connectionFD, hello, strlen(hello), 0);
				read(connectionFD, buffer, sizeof(buffer));

				sprintf(buffer2, "Respuesta del servidor: %s\n", buffer);
				write(1, buffer2, strlen(buffer2));

				closeConnection (connectionFD);
				// Hasta aqui

				}
				return 0;
}



