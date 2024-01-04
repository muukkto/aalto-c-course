#include "stringsplit.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * \brief Splits a string into its parts, and returns a dynamically allocated  
 *        array of strings that are dynamically allocated.
 * 
 * \details For example called with "Test string split" and " ",
 *          the function returns ["Test", "string", "split", NULL].
 *          
 *          Or called with "Another - test" and " - ",
 *          returns ["Another", "test", NULL].
 * 
 * \param str The null-terminated string to split.
 * \param split The token string to split str with.
 * \return An array of strings that contains parts of str in each of 
 *         strings excluding the split.      
 */
char** split_string(const char* str, const char* split) {
	char** array = (char**) malloc(sizeof(char*));
	char* append_str;
	int len_arr = 0;
	int len_split = strlen(split);

	while (1) {
		char*a = strstr(str, split);
		if (a) *a = 0;
		append_str = malloc(sizeof(char)*(strlen(str)+1));
		strcpy(append_str, str);
		len_arr++;
		array = (char**) realloc(array, sizeof(char*)*len_arr);
		array[len_arr-1] = append_str;
		if (!a) break;
    	str = a+len_split;
	}

	array = (char**) realloc(array, sizeof(char*)*(len_arr+1));
	array[len_arr] = NULL; //malloc(sizeof(NULL));
	
	return array;
}

/**
 * \brief Prints string parts that are split with split_string function.
 * 
 * \param split_string An array of strings returned by split_string function.
 */
void print_split_string(char** split_string) {
	int i = 0;
	
	while (split_string[i]) {
		printf("%s\n", split_string[i]);
		i++;
	}
}

/**
 * \brief Releases dynamically allocated string parts by split_string function.
 * 
 * \param split_string An array of strings returned by split_string function.
 */
void free_split_string(char** split_string) {
	int i = 0;
	
	while (split_string[i]) {
		free(split_string[i]);
		i++;
	}
	
	free(split_string);
}
