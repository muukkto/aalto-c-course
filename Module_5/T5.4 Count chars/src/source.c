#include <stdio.h>

/**
 * \brief Counts the number of occurrences of characters in an array
 *
 * \param array A zero (0) terminated string that is composed some number of characters
 * \param counts An int array of 256 elements that contains number of character occurrences.
 */

void count_chars(const char *array, unsigned int *counts) {
    for (int i = 0; 1 == 1; i++) {

        if (array[i] == 0) {
            break;
        }

        counts[(int) array[i]] += 1;
    }
}
