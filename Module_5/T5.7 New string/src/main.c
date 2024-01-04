#include "source.c"
#include <stdio.h>

int main()
{
    /* Implement your own tests here. Free feel to modify. */

    char str[] = "one, two, three? four, five";

    // Test print
    qstr_print(str);

    // Testing length
    printf("\nlength: %d\n", qstr_length(str));

    // test cat
    char buf[80] = "Some str:?trtrttr";
    int ret = qstr_cat(buf, str);
    printf("After cat: '");
    qstr_print(buf);
    printf("' (ret: %d)\n", ret);

    char str1[] = "Hello student?candidateJack";
    const char str2[] = "John?student";
    unsigned int len = qstr_cat(str1, str2);
    qstr_print(str1);
    printf("\n%d", len);

    return 0;
}
