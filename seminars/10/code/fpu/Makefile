all: lib.o main.o
	gcc -m32 lib.o main.o -o main

lib.o: lib.S
	gcc -m32 -c lib.S -o lib.o

main.o: main.c
	gcc -m32 -c main.c -o main.o

clean:
	rm -f main.o lib.o main
