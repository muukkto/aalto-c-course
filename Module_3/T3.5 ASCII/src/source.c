/* In this task, you are required to print a part of ASCII character map
 * (https://en.wikipedia.org/wiki/ASCII) as shown below.
 *   28 0x1c ?    29 0x1d ?       30 0x1e ?       31 0x1f ?
 *   32 0x20      33 0x21 !       34 0x22 "       35 0x23 #
 *   36 0x24 $    37 0x25 %       38 0x26 &
 * Each entry of the table is formatted as below
 *   <integer value> <space> <hexadecimal value> <space> <ASCII character>
 * and <space> is the ' ' character.
 *
 *  1. Implement function void ascii_chart(char min, char max). It should iterate
 *     through numbers starting from min and ending at (and including) max. The
 *     function should print the example output above when it is called
 *     ascii_chart(28,38);.
 *  2. <integer value> part of a table entry should be 3 characters long. If the
 *     number has less than 3 digits (when it is less than 100), the output should
 *     be right aligned.
 *  3. <hexadecimal value> part of a table entry should have 4 characters width
 *     corresponding to the hexadecimal representation of the number. The hexadecimal
 *     representation should be prefixed with 0x and must have 2 character width
 *     filled with 0. For example, number 1 is shown as 0x01.
 *  4. <ASCII character> part of a table entry is the corresponding ASCII encoding
 *     of the number. This part has one character width.
 *     The ASCII encoding defines printable characters to specific integers.
 *     You are required to check whether the number is printable. If the number
 *     is not printable, you should print a ? character.
 *  5. Each row is composed of 4 columns.
 *      - The columns are separated with the tab character '\t'.
 *      - Each row ends with new line character '\n'.
 * Hint
 *  1. The standard C library has various character related functions declared in ctype.h.
 *     See the reference documentation of the file (http://www.cplusplus.com/reference/cctype/).
 *     In particular, check isprint function.
 *  2. The printf function format specification documentation might be very useful.
 */

#include "source.h"

#include <ctype.h>
#include <stdio.h>
#include <string.h>

void ascii_chart(char min, char max)
{
    for (int i = 0; i <= (int) max - (int) min; i++){
        int character = (int) min + i;
        int displ;
        if (isprint(character)){
            displ = character;
        } else {
            displ = 63;
        }

        if (i % 4 == 3) {
            printf("%3d 0x%.2x %1c\n", character, (unsigned int) character, displ);
        } else {
            printf("%3d 0x%.2x %1c\t", character, (unsigned int) character, displ);
        }
    }  
}
