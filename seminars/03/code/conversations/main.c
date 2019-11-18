#include <stdio.h>

int main()
{
    unsigned char uc = 254;
    signed char c = uc;
    printf("unsigned char: %u -> signed char: %d\n", uc, c);

    c = 10;
    uc = c;
    printf("signed char: %d -> unsigned char: %u\n", c, uc);

    c = -2;
    uc = c;
    printf("signed char: %d -> unsigned char: %u\n", c, uc);

    unsigned short us = 256;
    uc = us;
    printf("unsigned short: %u -> unsigned char: %u\n", us, uc);

    short s = -32767;
    c = s;
    printf("short: %d -> signed char: %d\n", s, c);

    return 0;
}
