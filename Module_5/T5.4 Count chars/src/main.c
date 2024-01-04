#include "source.c"
#include <stdio.h>

void print_counts(int min, int max, const unsigned int *counts)
{
    for (int i = min; i <= max; i++)
    {
        printf("%c: %u  ---  ", i, counts[i]);
        if ((i - min + 1) % 6 == 0)
            printf("\n");
    }
}

void print_array(const char *array)
{
    printf("{ ");
    while (*array)
    {
        printf("'%c',", *array);
        array++;
    }
    printf("0 }");
}

int main(void)
{
    unsigned int counts[256] = {0};

    char sample[] = {'a', 'b', 'r', 'a', 'c', 'a', 'd', 'a', 'b', 'r', 'a', 0};

    print_array(sample);
    count_chars(sample, counts);
    printf("\n");
    print_counts('a', 'e', counts);

    return 0;
}
