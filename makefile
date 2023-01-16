CC = gcc
CFLAGS = -g -Wall

all: graph

graph.o: graph.c graph.h
	$(CC) $(CFLAGS) -c graph.c -o graph.o

main.o: main.c graph.h graph.o
	$(CC) $(CFLAGS) -c main.c -o main.o

graph: main.o graph.o
	$(CC) $(CFLAGS) main.o graph.o -o graph


.PHONY: all clean

clean:
	rm graph *.o