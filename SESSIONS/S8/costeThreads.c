#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include "socketMng.h"

void* thread_func(void* arg) {
    pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
    char buff[256];
    if (argc != 2) return 1;
    int n = atoi(argv[1]);
    pthread_t tid;
    struct timespec start, end;
    
    clock_gettime(CLOCK_REALTIME, &start);
    
    for(int i=0; i<n; i++) {
        pthread_create(&tid, NULL, thread_func, NULL);
        pthread_join(tid, NULL);
    }
    
    clock_gettime(CLOCK_REALTIME, &end);
    double time = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
    sprintf("Coste procesos (%d ops): %f s\n", n, time);
    write(1,buff,strlen(buff));
    return 0;
}