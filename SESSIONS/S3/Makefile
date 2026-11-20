all: myPS myPS_v0 myPS2 myPS3 parsExec ejemplos

myPS: myPS.c
	gcc -Wall -Wextra -o myPS myPS.c

myPS_v0: myPS_v0.c
	gcc -Wall -Wextra -o myPS_v0 myPS_v0.c

myPS2: myPS2.c
	gcc -Wall -Wextra -o myPS2 myPS2.c

myPS3: myPS3.c
	gcc -Wall -Wextra -o myPS3 myPS3.c

parsExec: parsExec.c
	gcc -Wall -Wextra -o parsExec parsExec.c

ejemplos: ejemplo_fork1 ejemplo_fork2 ejemplo_fork3 ejemplo_fork4 ejemplo_fork5 ejemplo_fork6 ejemplo_fork7 ejemplo_exec1 ejemplo_exec2

ejemplo_fork1: ejemplo_fork1.c
	gcc -o ejemplo_fork1 ejemplo_fork1.c
ejemplo_fork2: ejemplo_fork2.c
	gcc -o ejemplo_fork2 ejemplo_fork2.c
ejemplo_fork3: ejemplo_fork3.c
	gcc -o ejemplo_fork3 ejemplo_fork3.c
ejemplo_fork4: ejemplo_fork4.c
	gcc -o ejemplo_fork4 ejemplo_fork4.c
ejemplo_fork5: ejemplo_fork5.c
	gcc -o ejemplo_fork5 ejemplo_fork5.c
ejemplo_fork6: ejemplo_fork6.c
	gcc -o ejemplo_fork6 ejemplo_fork6.c
ejemplo_fork7: ejemplo_fork7.c
	gcc -o ejemplo_fork7 ejemplo_fork7.c
ejemplo_exec1: ejemplo_exec1.c
	gcc -o ejemplo_exec1 ejemplo_exec1.c
ejemplo_exec2: ejemplo_exec2.c
	gcc -o ejemplo_exec2 ejemplo_exec2.c

clean:
	rm -f myPS myPS_v0 myPS2 myPS3 parsExec ejemplo_fork1 ejemplo_fork2 ejemplo_fork3 ejemplo_fork4 ejemplo_fork5 ejemplo_fork6 ejemplo_fork7 ejemplo_exec1 ejemplo_exec2
