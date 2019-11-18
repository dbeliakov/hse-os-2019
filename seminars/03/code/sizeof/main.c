#include <stdio.h>

#define FORMAT_SIZE(type) \
    printf("sizeof(%s) = %zu\n", #type, sizeof(type))

int main()
{
    FORMAT_SIZE(char);
    FORMAT_SIZE(unsigned char);
    FORMAT_SIZE(signed char);
    FORMAT_SIZE(short);
    FORMAT_SIZE(unsigned short);
    FORMAT_SIZE(int);
    FORMAT_SIZE(unsigned int);
    FORMAT_SIZE(long);
    FORMAT_SIZE(unsigned long);
    FORMAT_SIZE(long long);
    FORMAT_SIZE(unsigned long long);
    return 0;
}
