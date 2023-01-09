CC = gcc
CFLAGS = -g -Wall

all: libgraph.a run

libgraph.a: main.o graph.o graph.h
	ar -rc libgraph.a main.o graph.o

run: libgraph.a main.o
	$(CC) $(CFLAGS) main.o ./libgraph.a -L. -o run

.PHONY: all clean

clean:
	rm run *.o *.a