#include <stdio.h>

int main()
{
    printf("%f != %f\n", ((3.14f + 1e10f) - 1e10f), (3.14f + (1e10f - 1e10f)));
    printf("%f != %f\n", ((1e20f * 1e20f) * 1e-20f), (1e20f * (1e20f * 1e-20f)));
    printf("%f != %f\n", (1e20f * (1e20f - 1e20f)), (1e20f * 1e20f - 1e20f * 1e20f));
}
