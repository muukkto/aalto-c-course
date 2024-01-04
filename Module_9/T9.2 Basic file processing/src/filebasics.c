#include "filebasics.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/**
 * \brief Print the given text file to the standard output stream.
 * 
 * \param filename The name of the file
 * \return The number of characters printed or -1 if file opening or reading 
 *         fails.
 */
int print_file_and_count(const char* filename) {
    FILE *f = fopen(filename, "r");

    if (!f) {
        return -1;
    }

    int buffer;
    int len = 0;

    while (1) {
        buffer = fgetc(f);

        if (buffer == -1) {
            fclose(f);
            return len;
        }

        printf("%c", buffer);
        len++;
    }
	
}

/**
 * \brief Compares two files and returns the first line that differ
 *        in the two files, concatenated together, separated by four dashes, on
 *        different lines.      
 * 
 * \param file1 The name of the first file
 * \param file2 The name of the second file
 * 
 * \note You can assume that lines are not longer than 1000 characters.
 * 
 * \return A dynamically allocated string that contains the first different 
 *         lines in the files. An example string is 
 * 
 *            printf("Hello world!\n");
 *       ----
 *            printf("Hello world\n");
 * \returns NULL if the files are equal or if either one of the 
            files ends.
 */
char* difference(const char* file1, const char* file2) {
    FILE *f1 = fopen(file1, "r");
    FILE *f2 = fopen(file2, "r");

    char row1[1000];
    char row2[1000];

    int i = 0;

    int buffer1;
    int buffer2;

    while (1) {
        buffer1 = fgetc(f1);
        buffer2 = fgetc(f2);

        if (buffer1 == -1 || buffer2 == -1) {
            fclose(f1);
            fclose(f2);

            return NULL;
        }

        if (buffer1 != buffer2) {
            row1[i] = (char) buffer1;
            row2[i] = (char) buffer2;

            i++;
            int j = i;
            int k = i;
            while (1) {
                buffer1 = fgetc(f1);
                row1[j] = (char) buffer1;
                j++;
                if ((char)buffer1 == '\n') {
                    break;
                }
            }

            while (1) {
                buffer2 = fgetc(f2);
                row2[k] = (char) buffer2;
                k++;
                if ((char)buffer2 == '\n') {
                    break;
                }
            }

            int len1 = strlen(row1);
            int len2 = strlen(row2);

            char *result = malloc(sizeof(char)*(len1+len2+6));
            strcpy(result, row1);
            strcat(result, "----\n");
            strcat(result, row2);

            fclose(f1);
            fclose(f2);

            return result;
        }

        if ((char)buffer1 == '\n') {
            memset(row1,0,1000);
            memset(row2,0,1000);
            i = 0;
        } else {
            row1[i] = (char) buffer1;
            row2[i] = (char) buffer2;

            i++;
        }
    }
	
}
