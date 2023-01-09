CC = gcc
CFLAGS = -g -Wall

all: libmy_sort.a libmy_txt.a isort txtfind

libmy_sort.a: isort.o header.o header.h
	ar -rc libmy_sort.a isort.o header.o

libmy_txt.a: txtfind.o header.o header.h
	ar -rc libmy_txt.a txtfind.o header.o

isort: libmy_sort.a isort.o
	$(CC) $(CFLAGS) isort.o ./libmy_sort.a -L. -o isort

txtfind: libmy_txt.a txtfind.o
	$(CC) $(CFLAGS) txtfind.o ./libmy_txt.a -L. -o txtfind

.PHONY: all clean

clean:
	rm isort txtfind *.o *.a