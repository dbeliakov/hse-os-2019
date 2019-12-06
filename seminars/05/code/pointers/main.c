#include <stdio.h>
#include <stdint.h>

void printBytes(int* p)
{
    uint8_t *bPointer = (uint8_t*)p;
    for (unsigned i = 0; i < sizeof(*p) / sizeof(*bPointer); ++i) {
        printf("0x%x ", *(bPointer + i));
    }
    printf("\n");
}

int sum(int* start, int* end)
{
    int result = 0;
    for (; start != end; ++start) {
        result += *start;
    }
    return result;
}

int main()
{
    int i = 42;
    int* p = NULL;
    printf("p = %p\n", p);
    if (!p) {
        printf("p is NULL\n");
    }

    p = (int*)1;
    if (p) {
        printf("p is not NULL\n");
    }

    // UB
    // *p = 1;

    p = &i;
    printf("p = %p\n", p);

    int a[10];
    p = a;
    printf("Pointer = %p; first element pointer = %p\n", p, &a[0]);

    ++p;
    printf("Pointer = %p; second element pointer = %p\n", p, &a[1]);

    printBytes(&i);

    printf("Pointers difference: %lu\n", &a[1] - &a[0]);

    int arr[] = {1, 2, 3};
    printf("sum = %d\n", sum(arr, arr + 3));

    return 0;
}
