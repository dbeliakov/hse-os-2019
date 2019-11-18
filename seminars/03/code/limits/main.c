#include <stdio.h>
#include <limits.h>

#define FORMAT_LIMIT(limit) \
    printf("%s = %lld\n", #limit, (long long)limit)

#define FORMAT_ULIMIT(limit) \
    printf("%s = %llu\n", #limit, (unsigned long long)limit)

int main()
{
    FORMAT_LIMIT(CHAR_MIN);
    FORMAT_LIMIT(CHAR_MAX);
    FORMAT_ULIMIT(UCHAR_MAX);

    FORMAT_LIMIT(SHRT_MIN);
    FORMAT_LIMIT(SHRT_MAX);
    FORMAT_ULIMIT(USHRT_MAX);

    FORMAT_LIMIT(INT_MIN);
    FORMAT_LIMIT(INT_MAX);
    FORMAT_ULIMIT(UINT_MAX);

    FORMAT_LIMIT(LONG_MIN);
    FORMAT_LIMIT(LONG_MAX);
    FORMAT_ULIMIT(ULONG_MAX);

    FORMAT_LIMIT(LLONG_MIN);
    FORMAT_LIMIT(LLONG_MAX);
    FORMAT_ULIMIT(ULLONG_MAX);
    return 0;
}
