#include <stdio.h>
#include "filestats.h"
#include <ctype.h>

/**
 * \brief Returns the number of lines in a file. 
 * 
 * \param filename The name of the file.
 * \return The number of lines in the file, or -1 if an error occurs. 
 */
int line_count(const char* filename) {
    FILE *f = fopen(filename, "rb");
    if (!f) {
        return -1;
    }

    int buffer;
    int count = 0;
    int other_char = 0;

    while (1) {
        buffer = fgetc(f);

        if (buffer == -1) {
            fclose(f);
            if (other_char) {
                return count + 1;
            } else {
                return count;
            }
        }

        other_char = 1;

        if (buffer == '\n') {
            count++;
            other_char = 0;
        }
    }
	
}

/**
 * \brief Returns the number of words in a file.
 * 
 * \details The function assumes that a word is formed by alphabetical characters
 *          as defined in ctype.h so that isalpha() returns nonzero value.
 * 
 *          The words are separated by a white space character as defined in 
 *          ctype.h so that isspace() returns nonzero value.
 * 
 * \param filename The name of the file.
 * \return The number of words in the file, or -1 if an error occurs.
 */
int word_count(const char* filename) {
    FILE *f = fopen(filename, "rb");
    if (!f) {
        return -1;
    }

    int buffer;
    int count = 0;
    int word = 0;

    while (1) {
        buffer = fgetc(f);

        if (buffer == -1) {
            fclose(f);
            return count;
        }

        if (isspace(buffer)) {
            word = 0;
        } else if (isalpha(buffer) && !word) {
            count++;
            word = 1;
        }
    }
}
