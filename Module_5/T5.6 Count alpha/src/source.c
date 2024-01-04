#include "source.h"
#include <stdio.h>
#include <ctype.h>

/**
 * \brief Counts alphabetical characters in a string
 *
 * \param str The string to be processed
 * \return The number of alphabetical characters
 */
int count_isalpha(const char *str)
{
    int count = 0;
    while (*str != '\0') {
        if (isalpha(*str)) { 
            count++;
        }
        str++;
    }

    return count;

}
