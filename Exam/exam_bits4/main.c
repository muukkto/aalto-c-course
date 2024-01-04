#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/**
 * \brief Counts the number of cleared bits (value 0) in a byte array of n elements.
 * 
 * \details This function counts the number clear bits in a byte array. 
 *          For example, if array = {0xA3, 0x58} and n = 2, the array 
 *          bytes has binary values 1010 0011 0101 1000, and the function
 *          returns 9. Since 
 *          1010 0011 0101 1000
 *           ^ ^ ^^   ^ ^   ^^^ 
 *          has 9 clear bits.
 * 
 * \param array A byte array of n elements.
 * \param n The number of bytes in array.
 * \return The number of clear bits in the bytes of array.
 * 
 * \note In your implementation, do not write to stdout to check the functionality.
 *       You should use my_tests function to print and check the functionality 
 *       of your implementation.
 */
unsigned int count_clear_bits_in_array(unsigned char* array, unsigned int n) {
	unsigned int zeros = 0;

	for (int j = 0; j < n; j++) {
		unsigned int current = (unsigned int) array[j];
		current = current + (1 << 8);

		while (current > 0) {
        if ((current & 1) == 0) {
            zeros++;
        }
 
        current = current >> 1;
    	}
	
	}

	return zeros;
}

/**
 * \brief conducts the tests for your implementation.
 * 
 * \details You are strongly encouraged to test your implementation
 * using this function. Try to create at least three test cases to check
 * whether your function implementation is correct.
 * 
 */
void my_tests(void) {
	unsigned char array[] = {0xA3, 0x58};
	unsigned int result1 = count_clear_bits_in_array(array, 2);

	unsigned char array2[] = {0x01, 0xd1, 0xeb, 0x34, 0x0c, 0xf3};
	unsigned int result2 = count_clear_bits_in_array(array2, 6);
}

int main(void) {
	/* You may implement your own tests in my_tests function */
	my_tests();
}
