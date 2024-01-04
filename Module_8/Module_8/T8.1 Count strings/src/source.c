#include "source.h"
#include <string.h>


/**
 * \brief Returns the number of occurrences of string sub in the string str.
 * 
 * \param str A null-terminated string that might contain sub in it. 
 * \param sub A null terminated string to search for.
 * \return The number of occurrences of sub in str.
 * 
 * \note strstr function declared in string.h might be useful. 
 */
int num_substr(const char* str, const char* sub) {
    int num = 0;
    str = strstr(str, sub);
    while (str) {
        num++;
        str = strstr((str+1), sub);
    }

    return num;
}
