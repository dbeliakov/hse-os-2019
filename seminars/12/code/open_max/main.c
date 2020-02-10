#include <unistd.h>
#include <stdio.h>
#include <limits.h>

int main()
{
    printf("POSIX_OPEN_MAX: %d\n", _POSIX_OPEN_MAX);
    printf("OPEN_MAX: %ld\n", sysconf(_SC_OPEN_MAX));
    return 0;
}
