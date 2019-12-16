#include <stdio.h>

typedef void(*Callback)(int);

void forEach(int* begin, int* end, Callback callback)
{
    for (int* it = begin; it != end; ++it) {
        callback(*it);
        // Also valid
        // (*callback)(*it);
    }
}

void printInt(int value)
{
    printf("%d\n", value);
}

int main()
{
    int a[] = {1, 2, 3, 4, 5};
    forEach(a, a + 5, printInt);
    // Also valid
    //forEach(a, a + 5, &printInt);
    return 0;
}
