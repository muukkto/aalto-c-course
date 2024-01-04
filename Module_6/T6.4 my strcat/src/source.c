#include "source.h"

#include <stdlib.h>
#include <string.h>

char *my_strcat(char *dest, const char *src)
{
    int size = (strlen(dest) + strlen(src) + 1)*sizeof(char);
    char *newstr = realloc(dest, size);
    char *origdest = newstr;
    while (*newstr)
    {
        newstr++;
    }

    while (*src)
    {
        *newstr++ = *src++; // Copy the source
    }
    *newstr = 0;

    return origdest;
}

