#include <stdio.h>

int main(int argc, char* argv[])
{
    printf("Count of arguments: %d\n", argc);
    printf("Arguments: [");
    int delimiter = -1;
    for (int i = 0; i < argc; ++i) {
        if (delimiter > 0) {
            printf("%c ", (char)delimiter);
        }
        printf("\'%s\'", argv[i]);
        delimiter = ',';
    }
    printf("]\n");
    return 0;
}
