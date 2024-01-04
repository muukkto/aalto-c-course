#include "source.h"
#include <stdio.h>


/* Print string */
/* Parameters:
 * s: string to be printed */

/**
 * \brief Prints ? terminated string
 *
 * \param s A ? terminated string
 */
void qstr_print(const char *s)
{
    while (*s != '?') {
        printf("%c", *s);
        s++;
    }
}

/**
 * \brief Returns the length of a ? terminated string
 *
 * \param s A ? terminated string
 * \return The number of characters before first occurrence of ?
 */
unsigned int qstr_length(const char *s)
{
    unsigned int len = 0;
    while (*s != '?') {
        len++;
        s++;
    }

    return len;
}

/**
 * \brief Concatenates two ? terminated strings
 *
 * \param dst The ? terminated string that will contain the concatenated ? terminated string
 * \param src A ? terminated string that will be appended to dst.
 * \return The length of the dst after concatenation
 */
int qstr_cat(char *dst, const char *src)
{
    int len = 0;

    while (*dst != '?') {
        dst++;
        len++;
    }

    while (*src != '?')
    {
        *dst = *src;
        dst++;
        src++;
        len++;
    }

    *dst = '?';
    

    return len;
}
