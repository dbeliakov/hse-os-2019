#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

const off_t SKIP_HELLO = 7;

int main()
{
    int f = open("text.txt", O_RDONLY);
    if (f < 0) {
        printf("Cannot open file");
        return 1;
    }
    off_t res = lseek(f, SKIP_HELLO, SEEK_SET);
    if (res < 0) {
        printf("Cannot change position");
        return 1;
    }
    char world[5];
    read(f, world, 5);
    write(STDOUT_FILENO, world, 5);
    write(STDOUT_FILENO, "\n", 1);
    return 0;
}
