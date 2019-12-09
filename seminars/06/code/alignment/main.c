#include <stdio.h>
#include <stdint.h>

struct Foo
{
    uint8_t ch;
    uint32_t value;
};

#pragma pack(push, 1)
struct Bar
{
    uint8_t ch;
    uint16_t id;
    uint32_t value;
};
#pragma pack(pop)

void printBytes(uint8_t* p, size_t n)
{
    for (size_t i = 0; i < n; ++i) {
        printf("0x%hhx ", *(p + i));
    }
    printf("\n");
}

int main()
{
    printf("sizeof(Foo) = %lu\n", sizeof(struct Foo));
    struct Foo foo = {-1, -1};
    printBytes((uint8_t*)&foo, sizeof(foo));

    printf("sizeof(Bar) = %lu\n", sizeof(struct Bar));
    struct Bar bar = {-1, -1, -1};
    printBytes((uint8_t*)&bar, sizeof(bar));
    return 0;
}
