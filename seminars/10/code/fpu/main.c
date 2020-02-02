#include <stdio.h>

double sqrt(double value);

long double mul(long double a, long double b);

int main()
{
    double value = 2;
    printf("%lf\n", sqrt(value));

    printf("%llf\n", mul(1.5, 2.0));
    return 0;
}
