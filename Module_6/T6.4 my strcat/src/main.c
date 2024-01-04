#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "source.h"

int main(void)
{
    char *str = malloc(7);
    strcpy(str, "Aatami");

    str = my_strcat(str, "Beetami");
    printf("%s\n", str);
    free(str);

    return 0;
}
