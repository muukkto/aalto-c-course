#include "bits.c"
#include <stdio.h>

/* Feel free to modify this function to test different things */

int main(void)
{

    uint32_t data = 0xaa5555aa;
    uint32_t result;
    /* op_bit_set tests */
    printf("\n*** Testing your op_bit_set function..\n");

    printf("At first data 0x%08X \n", data);
    printf("Setting bit 0\n");
    result = op_bit_set(data, 0);
    printf("data is 0x%08X, should be 0xAA5555AB\n", result);
    printf("Setting bit 17\n");
    result = op_bit_set(data, 17);
    printf("data is 0x%08X, should be 0xAA5755AA\n", result);

    printf("\n*** Testing your op_bit_clear function..\n");
    printf("Clearing bit 0\n");
    result = op_bit_clear(data, 0);
    printf("data is 0x%08X, should be 0xAA5555AA\n", result);
    printf("Clearing bit 16\n");
    result = op_bit_clear(data, 16);
    printf("data is 0x%08X, should be 0xAA5455AA\n", result);

    printf("\n*** Testing your op_bit_toggle function..\n");
    printf("Toggling bit 0\n");
    result = op_bit_toggle(data, 0);
    printf("data is 0x%08X, should be 0xAA5555AB\n", result);

    printf("Toggling bit 16\n");
    result = op_bit_toggle(data, 16);
    printf("data is 0x%08X, should be 0xAA5455AA\n", result);

    /* op_bit_get tests */
    printf("\n*** Testing your op_bit_get function..\n");
    printf("Setting bits 0, 1, 3 and 9\n");
    result = op_bit_set(data, 0);
    result = op_bit_set(result, 1);
    result = op_bit_set(result, 3);
    result = op_bit_set(result, 9);
    printf("Bit number 0 is %d, should be 1\n", op_bit_get(result, 0));
    printf("Bit number 1 is %d, should be 1\n", op_bit_get(result, 1));
    printf("Bit number 3 is %d, should be 1\n", op_bit_get(result, 3));
    printf("Bit number 9 is %d, should be 1\n", op_bit_get(result, 9));
    printf("Bit number 2 is %d, should be 0\n", op_bit_get(result, 2));
    printf("Bit number 13 is %d, should be 0\n", op_bit_get(result, 13));

    /* op_print_byte tests */
    printf("\n*** Testing your op_print_byte function..\n");
    unsigned char b = 0x80;
    printf("Printing out 10000000, got ");
    op_print_byte(b); // This should print out 10000000
    printf("\n");

    b = 0xFF;
    printf("Printing out 11111111, got ");
    op_print_byte(b); // This should print out 11111111
    printf("\n");

    return 0;
}
