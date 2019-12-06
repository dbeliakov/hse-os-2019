#include <stdio.h>

#define UNUSED(var) \
    (void)var

void foo(int array[20])
{
    UNUSED(array);

    // sizeof on array function parameter will return size of 'int *' instead of 'int [20]' [-Werror,-Wsizeof-array-argument]
    //sizeof(array);
}

void foo2(int array[])
{
    UNUSED(array);
}

void bar(int* array)
{
    UNUSED(array);
}

int main()
{
    int arr1[16];
    printf("Size of arr1 = %lu; count of elements = %lu\n", sizeof(arr1), sizeof(arr1) / sizeof(int));

    int arr2[] = {1, 2, 3};
    printf("Count of elements in arr2 = %lu\n", sizeof(arr2) / sizeof(int));

    foo(arr1);
    foo(arr2);

    foo2(arr1);
    foo2(arr2);

    bar(arr1);
    bar(arr2);

    return 0;
}
