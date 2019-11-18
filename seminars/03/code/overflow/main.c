#include <stdio.h>

int main()
{
    char value1, value2, result;
    scanf("%hhi%hhi", &value1, &value2);
    if (__builtin_add_overflow(value1, value2, &result)) {
        fprintf(stderr, "Overflow!\n");
    } else {
        printf("Result: %d\n", result);
    }
    return 0;
}
