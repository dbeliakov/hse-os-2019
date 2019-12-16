#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main()
{
    char str[64];
    while (scanf("%63s", str) == 1) {
        char* end = NULL;
        strtol(str, &end, 10);
        if (errno == ERANGE) {
            printf("-1\n");
        } else {
            printf("1\n");
        }
    }
    return 0;
}
