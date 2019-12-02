#include <stdio.h>
#include <float.h>

int main() {
    printf("%.20f\n", FLT_EPSILON);
    printf("%.20lf\n", DBL_EPSILON);
    return 0;
}
