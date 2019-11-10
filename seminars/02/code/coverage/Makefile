build: obj/main.o
	gcc -fprofile-arcs -ftest-coverage -g obj/main.o -o program

obj/main.o: main.c
	mkdir -p obj
	gcc -Wall -Wextra -Werror -fprofile-arcs -ftest-coverage -g -O0 -c -o obj/main.o main.c

clean:
	rm -rf obj report.* program

test: build
	./run_tests.sh

coverage: test
	gcovr -r . --object-directory obj --html --html-details -o report.html
