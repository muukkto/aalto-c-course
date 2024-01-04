#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "source.h"

/**
 * \brief Removes the C comments from the input C code.
 *
 * \details The function polishes the code by */
//          - removing the block comments delimited by /* and */.
/*            These comments may span multiple lines.You should remove only */
//            characters starting with /* and ending with */. The characters,
/*            including white space characters (' ', \n, \r, \t), */
//            after */ should not be removed.
/*
 *          - remove the line comments starting with // until and including the
 *            newline character \n.
 *
 * \param input A code segment that contains some comments.It is a dynamically
 *              allocated string(array of characters).
 * \return A pointer to the polished code
 */

char *delete_comments(char *input)
{
    char *input_org = input;
    char *modify = malloc(0);
    //char *modify_org = modify;

    //int ret_len = 0;
    int size = 0;

    while (*input)
    {
        if (*input == '/' && *(input + 1) == '*') {
            while (1) {
                if (*input == '*' && *(input + 1) == '/') {
                    input++;
                    input++;
                    break;
                }
                input++;
            }
        }

        if (*input == '/' && *(input + 1) == '/') {
            while (1) {
                if (*input == '\n') {
                    input++;
                    break;
                }
                input++;
            }
        }

        
        modify = realloc(modify, (size + 1)*sizeof(char));
        *(modify + size) = *input;
        size++;
        input++;
    }

    modify = realloc(modify, (size + 1)*sizeof(char));
    *(modify + size) = '\0';
    //char *ret = realloc(modify_org, ret_len);
    free(input_org);

    return modify;
}
