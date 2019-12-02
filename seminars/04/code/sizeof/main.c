#include <stdio.h>

#define FORMAT_SIZE(type) \
    printf("sizeof(%s) = %zu\n", #type, sizeof(type))

int main()
{
    FORMAT_SIZE(float);
    FORMAT_SIZE(double);
    FORMAT_SIZE(long double);
    return 0;
}
