#include <stdio.h>

int abs(int value)
{
    if (value >= 0) {
        return value;
    } else {
        return value; // error
    }
}

int main()
{
    int val;
    if (scanf("%d", &val) != 1) {
        fprintf(stderr, "No value in input\n");
        return 1;
    }
    printf("%d\n", abs(val));
    return 0;
}
