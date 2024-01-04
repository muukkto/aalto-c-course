#include "bit_sequence.c"
#include <stdio.h>

/* Feel free to modify this function to test different things */

int main(void)
{
    /* op_bit_get_sequence tests */
    printf("\n*** Testing your op_bit_get_sequence function..\n");

    printf("Getting sequence... Should be 0x4d, was 0x%02X\n", op_bit_get_sequence(0x55aa55aa, 0x00133026));
    printf("Getting sequence... Should be 0x12, was 0x%02X\n", op_bit_get_sequence(2857719210, 403227136));

    return 0;
}
