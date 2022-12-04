CC = gcc
CFLAGS = -g -Wall

all: libmy_mat.a connections

libmy_mat.a: main.o my_mat.o my_mat.h
	ar -rc libmy_mat.a main.o my_mat.o

connections: libmy_mat.a main.o
	$(CC) $(CFLAGS) main.o ./libmy_mat.a -L. -o connections

.PHONY: all clean

clean:
	rm connections *.o *.a