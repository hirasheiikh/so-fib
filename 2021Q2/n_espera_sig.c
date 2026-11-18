#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <fcntl.h>
#include <errno.h>

void Usage(){
    char buff[256];
    sprintf(buff, "Usage: ./n_espera_sig N\n");
    write(1, &buff, strlen(buff));
    exit(0);
}

void error_y_exit(char *msg){
    perror(msg);
    exit(EXIT_FAILURE);
}

int main(int argc, char argv[]){
    char buff[256];
    if (argc != 2) Usage();
    int N = argv[1];
    int *pids = sbrk(sizeof(int) * N);
    for (int i = 0; i < N; ++i){
        pids[i] = fork();
        if (pids[i] == 0){
            sprintf(buff, "Soy el proceso %d y mi PID es %d\n", i, getpid());
            write(1, &buff, strlen(buff));
            execlp("./espera_sig.c", "espera_sig.c", (char*)NULL);
        }
        else if (pids[i] > 0){
            int fill,st;
            while((fill = waitpid(-1, &st, NULL)) > 0){
                int fd = open("exit_status.int", O_WRONLY|O_TRUNC|O_CREAT, 0640);
                if (fd < 0) error_y_exit("open");
                if (WIFEXITED(st)){
                    int estat = WEXITSTATUS(st);
                    if 

        
                }
            }
        }
        else error_y_exit("fork");
    }
}