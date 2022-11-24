all: runit

runit: main.c my_mat.c
	gcc -Wall -c main.c my_mat.c
	gcc -Wall -o program main.o my_mat.o

.PHONY: clean all loops recursives loopd recursived

clean: 
	rm -f *.o *.a *.so mains maindloop maindrec
