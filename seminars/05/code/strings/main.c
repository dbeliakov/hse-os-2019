#include <stdio.h>

int main()
{
    char* hello = "Hello, world";
    printf("%s\n", hello);
    ++hello;
    printf("%s\n", hello);

    char hello2[] = "Hello, world";
    // UB
    //hello2[12] = 1;
    //printf("%s\n", hello2);

    return 0;
}
