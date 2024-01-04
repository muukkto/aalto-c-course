#include "hexread.h"
#include <stdio.h>

/**
 * \brief Prints the given file as hexdump.
 * 
 * \details The function outputs each byte in the file as a two character hexadecimal 
 *          number. 
 *
 *    - If a byte is less than ``0x10``, then the output should have ``0`` in 
 *      front of the number. 
 *    
 *    - Each line must have maximum of 16 hexadecimal numbers with a space between 
 *      them.
 * 
 *    - Only 16 hexadecimal numbers must be printed in one line and there should 
 *      be a space after the last value.After printing 16 hex values, the next 
 *      byte should be printed on the next line. 
 *
 *    - If the end-of-file indicator is set before a line ends, the dump should 
 *      end.
 * 
 * \param filename The name of the file to dump.
 * \return Returns the number of characters read or -1 if an error occurs when 
 *         reading the file.
 */
int file_to_hex(const char* filename) {
    FILE *f = fopen(filename, "rb");
    if (!f) {
        return -1;
    }
    
    unsigned char buffer[1];
    int len = 0;
    int row = 0;

    while (1) {
        if (fread(buffer, 1, 1, f) != 1){
            fclose(f);
            return len;
        }
        printf("%02x ", buffer[0]);
        len++;
        row++;

        if (row == 16) {
            printf("\n");
            row = 0;
        }
    }
}
