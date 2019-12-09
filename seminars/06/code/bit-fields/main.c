#include <stdio.h>
#include <stdint.h>

struct Packed
{
    uint8_t b1:1;
    uint8_t b2:1;
    uint8_t b3:1;
    uint8_t b4:1;
    uint8_t data:4;
};

void printBytes(uint8_t* p, size_t n)
{
    for (size_t i = 0; i < n; ++i) {
        printf("0x%hhx ", *(p + i));
    }
    printf("\n");
}

int main()
{
    printf("sizeof(Packed) = %lu\n", sizeof(struct Packed));
    struct Packed p = {1, 1, 1, 1, 2};
    printBytes((uint8_t*)&p, sizeof(p));
}
