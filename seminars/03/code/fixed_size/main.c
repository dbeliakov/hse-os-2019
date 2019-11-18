#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

#define FORMAT(type) \
    printf("sizeof(%s) = %lu\n", #type, sizeof(type))

int main()
{
    FORMAT(uint8_t);
    FORMAT(uint16_t);
    FORMAT(uint32_t);
    FORMAT(uint64_t);

    uint8_t byte = 8;
    printf("%" PRIu8 "\n", byte);

    return 0;
}
