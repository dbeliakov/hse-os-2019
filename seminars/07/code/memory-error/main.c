#include <stdlib.h>

int main()
{
    int* a = (int*)malloc(sizeof(int));
    (void)a; // make unused

    int* b = NULL;
    *b = 0;

    int* c = (int*)malloc(6);
    c[1] = 2;

    return 0;
}
