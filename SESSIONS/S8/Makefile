BINARIES=suma_paralela cliente server suma_paralela_v2 suma_paralela_v3 server_thread costeProcesos
costeThreads

all:$(BINARIES)

suma_paralela:suma_paralela.c
	gcc -o suma_paralela suma_paralela.c

cliente:cliente.c socketMng.h socketMng.c
	gcc -o cliente cliente.c socketMng.c

server:server.c socketMng.c socketMng.h
	gcc -o server server.c socketMng.c

suma_paralela_v2:suma_paralela.c
	gcc -o suma_paralela_v2 suma_paralela_v2.c

suma_paralela_v3:suma_paralela_v3.c
	gcc -o suma_paralela_v3 suma_paralela_v3.c

server_thread:server_thread.c
	gcc -o server_thread server_thread.c

costeProcesos: costeProcesos.c
	gcc -o costeProcesos costeProcesos.c

costeThreads: costeThreads.c
	gcc -o costeThreads costeThreads.c

clean:
	rm -f $(BINARIES)
	

