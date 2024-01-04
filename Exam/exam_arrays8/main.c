#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/**
 * \brief Compares two integers and returns their comparison result.
 * \details This function defines the order of the elements by 
 *          returning (in a stable and transitive manner): 
 *          <0	The value pointed to by 'a' goes before the value pointed to by 'b'
 *           0	The value pointed to by 'a' is equivalent to the value pointed to by 'b'
 *          >0	The value pointed to by 'a' goes after the value pointed to by 'b'
 * 
 *          In other words, this function essentially calculates the difference
 *          of the values pointed by its arguments.
 * 
 * \param a A pointer to the integer that will be compared against the 
 *          value pointed by b.
 * \param b A pointer to the integer that will be compared against the 
 *          value pointed by a.
 * \return The comparison result
 */
int compare_ints(const void* a, const void* b) {
	return *(int*) a - *(int*) b;
}

/**
 * \brief Finds the smallest and the largest elements in an integer array of 
 *        n elements, and returns their sum.
 * 
 * \param array The array of integer values.
 * \param n The number of elements in the array. 
 * \return The sum of the largest and the smallest elements in the array.
 * 
 * \note  stdlib.h has some useful functions that might help you to
 *        sort the array to find the smallest and the largest values of an array.
 *        You might need the comparison function compare_ints if you prefer to 
 *        use stdlib function for sorting the array.
 * 
 * \note In your implementation, do not write to stdout to check the functionality.
 *       You should use my_tests function to print and check the functionality 
 *       of your implementation.
 */
int sum_min_max(int* array, unsigned int n) {
	int min, max;
	qsort(array, n, sizeof(int), compare_ints);
	min = array[0];
	max = array[n-1];

	return min + max;
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
	int array1[] = {50, 25, 75, 100};
	int result1 = sum_min_max(array1, 4);
	printf("Test 1: %d\n", result1);

	int array2[] = {1, 7, 8, 2, 3, 9};
	int result2 = sum_min_max(array2, 6);
	printf("Test 2: %d\n", result2);

	int array3[] = {1, 1, 4, 3, 2, 2, 2, 4};
	int result3 = sum_min_max(array3, 8);
	printf("Test 3: %d\n", result3);
}

int main(void) {
	/* You may implement your own tests in my_tests function */
	my_tests();
}