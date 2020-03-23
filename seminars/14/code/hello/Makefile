static-lib:
	gcc -O2 -Wall -Werror -std=c11 -c lib/lib.c -o lib/lib.o
	ar rcs lib/liblib.a lib/lib.o

static-bin: static-lib
	gcc -O2 -Wall -Werror -std=c11 -c main.c -o main.o
	gcc main.o -static -Llib -o main -llib

shared-lib:
	gcc -O2 -Wall -Werror -std=c11 -fPIC -DPIC -c lib/lib.c -o lib/lib.o
	gcc -std=c11 -fPIC -shared lib/lib.o -o lib/liblib.so

shared-bin: shared-lib
	gcc -O2 -Wall -Werror -std=c11 -c main.c -o main.o
	gcc main.o -Llib -Wl,-rpath,lib -o main -llib

clean:
	rm -f lib/lib.o lib/liblib.a lib/liblib.so main.o main
