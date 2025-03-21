CFLAGS = -Wall -Wextra -g
CC = gcc

all: busca

busca: busca.o avl-tree.o
	gcc -o busca busca.o avl-tree.o

busca.o: busca.c avl-tree.h
	gcc -c busca.c $(CFLAGS)

clean:
	rm -f *.o 

purge:
	rm -f *.o busca avl-tree
