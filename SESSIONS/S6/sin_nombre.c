// Pipes sense nom
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
	int pipe_fd[2];
	pipe(pipe_fd);
	char buff[256];
	int pid = fork();
	// fill
	if (pid == 0) {
		dup2(pipe_fd[0],0);
		close(pipe_fd[0]);
		close(pipe_fd[1]);
		execlp("cat","cat",NULL);
	} 
	// pare
	else if (pid > 0) {
		close(pipe_fd[0]);
		sprintf(buff,"Inicio\n");
		write(1,buff,strlen(buff));
		close(pipe_fd[1]);
		waitpid(-1,NULL,0);
		sprintf(buff,"Fin\n");
		write(1,buff,strlen(buff));
	}
}