#include <stdio.h>

int main()
{
    char buf[5];
    int res = snprintf(buf, 5, "%.6f", 5.0);
    printf("res = %d, str = '%s'\n", res, buf);
    return 0;
}
