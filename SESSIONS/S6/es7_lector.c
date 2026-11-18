#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <signal.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>


void Usage(){
    char buff[256];
    sprintf(buff, "Usage: ./es7_lector N\n");
    write(1, &buff, strlen(buff));
    exit(0);
}

void error_y_exit(char *msg){
    perror(msg);
    exit(EXIT_FAILURE);
}


int main (int argc,char *argv[])
{
    
  if (argc !=2) Usage();
  int num = atoi(argv[1]);
  int ret;
  char buff[256];

  
  ret = read (0, &num, sizeof (int));

  if (ret == sizeof (int)){
    sprintf (buff, "Número llegit: %d\n", num);
    write (1, buff, strlen (buff));
    }
  else if (ret == 0){
    sprintf (buff, "Error: Fi de fitxer inesperat.\n");
    write (2, buff, strlen (buff));
    }
  else{
    sprintf (buff, "Error en la lectura.\n");
    write (2, buff, strlen (buff));
    }

  return 0;
}