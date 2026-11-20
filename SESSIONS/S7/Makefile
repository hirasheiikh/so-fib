all: escritor escritor_v2 fichero_append invirtiendo_fichero sin_nombre insertax2_lseek insertax2_mmap

escritor: escritor.c
	gcc -o escritor escritor.c

escritor_v2: escritor_v2.c
	gcc -o escritor_v2 escritor_v2.c

fichero_append: fichero_append.c
	gcc -o fichero_append fichero_append.c

invirtiendo_fichero: invirtiendo_fichero.c
	gcc -o invirtiendo_fichero invirtiendo_fichero.c

sin_nombre: sin_nombre.c
	gcc -o sin_nombre sin_nombre.c

insertax2_lseek: insertax2_lseek.c
	gcc -o insertax2_lseek insertax2_lseek.c

insertax2_mmap: insertax2_mmap.c
	gcc -o insertax2_mmap insertax2_mmap.c
clean:
	rm -f *.o escritor escritor_v2 fichero_append invirtiendo_fichero sin_nombre insertax2_lseek insertax2_mmap