
#include "source.h"
#include <stdlib.h>
#include <string.h>

/**
 * \brief Joins 3 arrays into a new dynamically allocated array
 *
 * \param n1 The number of elements in array a1
 * \param a1 The array 1 composed of n1 elements
 * \param n2 The number of elements in array a2
 * \param a2 The array 2 composed of n2 elements
 * \param n3 The number of elements in array a3
 * \param a3 The array 3 composed of n3 elements
 * \return a pointer to the dynamically allocated array
 *
 * \note The caller is responsible for deallocating the allocated array
 */
int *join_arrays(unsigned int n1,
                 const int *a1,
                 unsigned int n2,
                 const int *a2,
                 unsigned int n3,
                 const int *a3)
{
    int *new_array;
    size_t n = n1 + n2 + n3;
    size_t size = sizeof(int);
    new_array = (int*)calloc(n, size);

    memcpy(new_array, a1, n1*sizeof(int));
    memcpy(new_array + n1, a2, n2*sizeof(int));
    memcpy(new_array + (n1+n2), a3, n3*sizeof(int));

    return new_array;

}
