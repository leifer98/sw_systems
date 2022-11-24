all: connections

connections: main.o my_mat.o
	gcc -Wall -g -o connections main.o my_mat.o

.PHONY: clean all connections

clean: 
	rm -f *.o *.a *.so connections
