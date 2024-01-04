#include "bit_sequence.h"
#include <stdio.h>
#include <stdlib.h>

/* DESCRIPTION:
 * ------------
 * The function extracts a sequence of bits from the argument data. The indexes
 * of the bits that will be extracted are the set bits in mask.
 *
 * The set bits in mask are copied to an unsigned char variable.
 *
 * For example,
 *
 * data = 0101 0101 1010 1010 0101 0101 1010 1010 = 0x55aa55aa
 * mask = 0000 0000 0001 0011 0011 0000 0010 0110 = 0x00133026
 *                     ^   ^^   ^^        ^   ^^
 * retVal =            0   10   01        1   01  = 0x4d
 *
 *
 * PARAMETERS:
 * ------------
 * uint32_t data: a 32 bit integer that will be operated on
 *
 * uint32_t mask: the bit packed data that indicates the bits to be copied to result
 *
 * RETURNS:
 * ------------
 * The extracted sequence stored in a single unsigned char.
 *
 */

uint8_t op_bit_get_sequence(uint32_t data, uint32_t mask)
{
    unsigned long maskb = 1;
    unsigned char retVal = 0;
    int amount = 0;

    for(int i = 0; i < 32; i++) {
        unsigned char datai = (data & maskb) << 7;
        unsigned char maski = mask & maskb;

        if (maski == 1) {
            retVal = (retVal >> 1) | datai;
            amount++;
        }


        
        mask = mask >> 1;
        data = data >> 1;

    }

    retVal = retVal >> (8-amount);

    return retVal;
}
