#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>

int main()
{
    int f = open("file", O_WRONLY | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    if (f < 0) {
        printf("Cannot open file");
        return 1;
    }
    for (int i = 0; i < 10; ++i) {
        char str[3];
        snprintf(str, 3, "%d\n", i);
        write(f, str, 2);
    }
    close(f);
    return 0;
};
