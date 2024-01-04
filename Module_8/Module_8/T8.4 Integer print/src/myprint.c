#include "myprint.h"
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>

int myprint(const char *str, ...){
    int size = 0;

    va_list args;
    va_start(args, str);

    for (int i = 0; i < (int) strlen(str); i++) {
        char cur_char = str[i];
        if (cur_char == '&') {
            int next = va_arg(args, int);
            printf("%d", next);
            size++;
        } else {
            printf("%c", cur_char);
        }
    }

    va_end(args);
    return size;
}
