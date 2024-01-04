/*  The code below does not compile and produce the required output.
 *  Try first to understand why it does not compile. What does the compiler error mean?
 *  After that, correct the code so that it compiles and produces the correct
 *  value of the variable a after the mathematical operations.
 */

#include <stdio.h>

int main(void)
{
    int a = 1;
    a = a + 1;
    {
    int b = 6;
    b = b + 1;
    }
    a = a + 7;
    printf("a: %d", a);
    return 0;
}