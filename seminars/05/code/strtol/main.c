#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#define CONVERT(s) \
    errno = 0; \
    l = strtol(s, &end, 10); \
    printf("s = \"%s\", errno = %d, l = %ld, end - s = %lu\n", s, errno, l, end - s)

int main()
{
    char* end;
    long l;

    CONVERT("42");
    CONVERT("42a");
    CONVERT(" 42a");
    CONVERT("1111111111111111111111111111111111111");

    return 0;
}
