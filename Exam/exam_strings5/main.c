#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/**
 * \brief Converts all white space characters in a null-terminated 
 *        string to tilde character, '~'.
 * 
 * \details This function finds all white space characters in a string and 
 *          converts these characters into a tilde character, '~'. It changes 
 *          the found white space characters inplace so that no dynamic 
 *          allocation is needed.
 * 
 * \param str The null-terminated string with some white space characters.
 * 
 * \note stdlib provides useful character handling functions in ctype.h. 
 *       ctype.h documentation also states different character classes,  
 *       including white space characters.
 * 
 * \note In your implementation, do not write to stdout to check the functionality.
 *       You should use my_tests function to print and check the functionality 
 *       of your implementation.
 */
void convert_white_space(char* str) {
	int len = strlen(str);
	for (int i = 0; i < len; i++) {
		if (isspace(str[i])) {
			str[i] = '~';
		}
	}
}

void my_tests(void) {
	char string1[] = "Hello World!";
	convert_white_space(string1);
	
}

int main(void) {
	/* You may implement your own tests in my_tests function */
	my_tests();
}