#include <stdio.h>

int main()
{
    int x = 0;
    scanf("%*d %d", &x);
    printf("%d\n\n", x);

    float y;
    scanf("%3f", &y);
    printf("%f\n\n", y);

    scanf("%X", &x);
    printf("%d\n\n", x);

    char c[3];
    scanf("%3c", c);
    printf("%c - %c - %c\n\n", c[0], c[1], c[2]);

    char s[10];
    scanf("%9s", s);
    printf("%s\n\n", s);

    sscanf("abab", "%9[aba]", s);
    printf("%s\n\n", s);

    return 0;
}
