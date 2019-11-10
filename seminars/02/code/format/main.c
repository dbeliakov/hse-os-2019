#include <stdio.h>

#define FORMAT(...) \
    printf("printf(%s);\n", #__VA_ARGS__); \
    printf(__VA_ARGS__); \
    printf("\n")

int main()
{
    FORMAT("%c\n", 'a');
    FORMAT("%d\n", 1);
    FORMAT("%i\n", 1);
    FORMAT("%o\n", 8);
    FORMAT("%x\n", 15);
    FORMAT("%X\n", 15);

    FORMAT("%e\n", 314.5);
    FORMAT("%E\n", 314.5);

    FORMAT("%f\n", 314.5);
    FORMAT("%g\n", 314.5);
    FORMAT("%G\n", 314.5);
    FORMAT("%.2g\n", 314.5);

    FORMAT("%a\n", 15.47);
    FORMAT("%A\n", 15.47);

    int x = 0;
    FORMAT("123%n\n", &x);
    FORMAT("%d\n", x);

    FORMAT("%p, %p\n", NULL, &x);

    FORMAT("%s\n", "Hello!");

    FORMAT("%%\n");

    FORMAT("'%10d'\n", 1);
    FORMAT("'%*d'\n", 10, 1);
    FORMAT("'%*d'\n", -10, 1);

    FORMAT("%2$d - %1$d\n", 1, 2);
    FORMAT("'%1$*2$d'\n", 1, 2);
    FORMAT("'%*d' - '%*d'\n", 2, 1, 3, 1);

    FORMAT("'%-*d'\n", 2, 1);
    FORMAT("%+d\n", 1);
    FORMAT("% d\n% d\n", -1, 2);
    FORMAT("%1$#o, %1$#x, %1$#X\n", 32);
    FORMAT("%1$.0f, %1$#.0f\n", 1.0);
    FORMAT("%0*d\n", 2, 1);

    FORMAT("%.3d\n", 1);
    FORMAT("%.3f\n", 1.5);
    FORMAT("%.3g\n", 1.5);
    FORMAT("%.*d", 3, 1);
    FORMAT("%.2s", "Hello!");

    return 0;
}
