#include <stdio.h>
#include "source.c"

int main(void)
{
    printf("%02x\n", sixBits(0xDF));
    printf("%02x\n", sixBits(0x8D));
    printf("%02x\n", sixBits(0x28));
    printf("%02x\n", sixBits(0xf0));
    return 0;
}
