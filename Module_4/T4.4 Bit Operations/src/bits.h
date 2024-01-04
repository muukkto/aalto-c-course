#ifndef AALTO_BITS_H
#define AALTO_BITS_H
#include <stdint.h>

int op_bit_get(uint32_t data, int i);
uint32_t op_bit_set(uint32_t data, int i);
uint32_t op_bit_clear(uint32_t data, int i);
uint32_t op_bit_toggle(uint32_t data, int i);
void op_print_byte(unsigned char b);

#endif
