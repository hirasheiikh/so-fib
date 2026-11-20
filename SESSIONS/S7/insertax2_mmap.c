#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <signal.h>

void Usage() {
    char buff[128];
    sprintf(buff, "Usage: ./insertarx2_mmap\n");
    write(1, buff, strlen(buff));
    exit(EXIT_FAILURE);
}

void error_y_exit(char* msg) {
    perror(msg);
    exit(0);
}

int main(int argc, char *argv[]) {
	if (argc < 2) Usage();
	else {
		char buff[256];
		char buffX[256];

		int f1 = open(argv[1], O_RDWR);
        //char *f2 = mmap(NULL,sizeof(f1) /*MIRAR QUE FALTA*/);
		int f2; //ho deixo perquè compili 

        /*

        EXEMPLE MAN per entendre mmap;

           int          fd;
           char         *addr;
           off_t        offset, pa_offset;
           size_t       length;
           ssize_t      s;
           struct stat  sb;

            char *addr = mmap(NULL, length + offset - pa_offset, PROT_READ,
                       MAP_PRIVATE, fd, pa_offset);
           if (addr == MAP_FAILED)
               handle_error("mmap");
               
            s = write(STDOUT_FILENO, addr + offset - pa_offset, length);
           if (s != length) {
               if (s == -1)
                   handle_error("write");

               fprintf(stderr, "partial write");
               exit(EXIT_FAILURE);
           }

           munmap(addr, length + offset - pa_offset);
           close(fd);

           exit(EXIT_SUCCESS);
       }

        */
		if (f1 == -1) error_y_exit("Open");
		sprintf(buffX, "X");
		int x = atoi(argv[2]);
		while (x != f2) {
			//mmap(f1, x, SEEK_SET);
			write(1,buffX,strlen(buffX));
			++x;
		}
		close(f1);
	}
}