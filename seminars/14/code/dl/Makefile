shared-lib:
	gcc -O2 -Wall -Werror -std=c11 -fPIC -DPIC -c lib/lib.c -o lib/lib.o
	gcc -std=c11 -fPIC -shared lib/lib.o -o lib/liblib.so

bin:
	gcc -O2 -Wall -Werror -c main.c -o main.o
	gcc main.o -o main -ldl

clean:
	rm -f lib/lib.o lib/liblib.so main.o main 
