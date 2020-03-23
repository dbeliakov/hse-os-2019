#include <stdio.h>

void printHello()
{
#ifdef PIC
    printf("Hello, shared!\n");
#else
    printf("Hello, static!\n");
#endif
}
