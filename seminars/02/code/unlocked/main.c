#include <stdio.h>
#include <time.h>

int main()
{
    int c;
    clock_t start = clock();
    while ((c = getchar_unlocked()) != EOF) {
        putchar_unlocked(c);
    }
    clock_t diff = clock() - start;
    int msec = diff * 1000 / CLOCKS_PER_SEC;
    fprintf(stderr, "Time: %dms\n", msec);
    return 0;
}
