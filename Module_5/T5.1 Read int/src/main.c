#include <stdio.h>
#include <stddef.h>

// declare and define the function here
int* read_int(int* number)
{
    int ret;
    if (number == NULL) { // Check the provided pointer
        return NULL; // If the pointer is NULL, exit the function
    } if (scanf("%d", &ret) == 1) {
        *number = ret;
        return number;
    }
    return NULL;
}

int main(void)
{
    int a;
    int* ret = read_int(&a);
    printf("return value: %p\n", ret);
    if (ret)
        printf("reading succeeded: %d\n", a);
    else
        printf("not a valid number\n");


    return 0;
}
