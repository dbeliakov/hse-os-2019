#include <locale.h>
#include <stdio.h>
#include <wchar.h>
#include <wctype.h>
#include <stdlib.h>

int main()
{
    char* locale = setlocale(LC_ALL, "ru_RU.UTF-8");
    if (locale == NULL) {
        fprintf(stderr, "Bad locale\n");
        exit(1);
    }
    wint_t c = getwc(stdin);
    if (c == EOF) {
        return 0;
    }
    printf("%d\n", c);
    return 0;
}
