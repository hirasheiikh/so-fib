#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include "socketMng.h"

#define MAXSTRING 1024

void *atendre_client(void *arg) {
    int connectionFD = *(int*)arg;
    free(arg);
    
    char buffer_msg[MAXSTRING];
    char* response = "Hola desde el servidor thread\n";

    read(connectionFD, buffer_msg, sizeof(buffer_msg));

    send(connectionFD, response, strlen(response), 0);
    closeConnection(connectionFD);
    
    pthread_exit(NULL);
}

int main (int argc, char *argv[])
{
    int socketFD;
    int *connFD_ptr;
    char buffer[MAXSTRING];
    pthread_t th;

    if (argc != 2) {
        sprintf(buffer, "Usage: %s socketPath\n", argv[1]);
        write (2, buffer, strlen (buffer));
        exit (1);
    }

    socketFD = createSocket (argv[1]);
    if (socketFD < 0) {
        perror ("Error creating socket\n");
        exit (1);
    }
    
    while(1) {
        int connFD = serverConnection (socketFD);
       
        connFD_ptr = malloc(sizeof(int));
        *connFD_ptr = connFD;

        if (pthread_create(&th, NULL, atendre_client, connFD_ptr) != 0) {
            perror("Error creating thread");
        }
        pthread_detach(th);
    }

    deleteSocket (socketFD, argv[1]);
    return 0;
}