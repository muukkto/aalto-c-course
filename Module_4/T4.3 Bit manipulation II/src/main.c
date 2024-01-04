#include <stdio.h>
#include "source.c"

int main(void) {

    printf("%02x\n", mergeBits(0x5, 0xE));
    printf("%02x\n", mergeBits(0xA, 0xC));
    printf("%02x\n", mergeBits(0xD, 0x2));
    return 0;
}
