#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "macro_wrapper.c"

extern int wrap_eq3_int(int a, int b, int c);
extern int wrap_eq3_float(float a, float b, float c);
extern int wrap_eq3_float_enclose(float a, float b, float c, int scale);
extern int wrap_min3_int(int a, int b, int c);
extern float wrap_min3_float(float a, float b, float c);
extern float wrap_min3_float_enclose(float a, float b, float c, int scale);

int main(void)
{
#ifdef EQ3
    printf("Testing EQ3:\n");
    printf("EQ3(3,3,3) returned %d, should have been 1.\n", wrap_eq3_int(3,3,3));
    printf("EQ3(1,2,3) returned %d, should have been 0.\n", wrap_eq3_int(1,2,3));
    printf("EQ3(3.0,3,3.0) returned %d, should have been 1.\n", wrap_eq3_float(3.0,3.0,3.0));
    printf("EQ3(1.0,2.0,3.0) returned %d, should have been 0.\n", wrap_eq3_float(1.0,2.0,3.0));
    printf("5*EQ3(3.0,3.0,3.0)*5 returned %d, should have been 25.\n", wrap_eq3_float_enclose(3.0,3.0,3.0, 5));
#else
    printf("Implement EQ3 first");
#endif

#ifdef MIN3
    printf("\nTesting MIN3:\n");
    printf("MIN3(1,2,3) returned %d, should have been 1.\n", wrap_min3_int(1,2,3));
    printf("MIN3(1.0,2.0,3.0) returned %f, should have been 1.\n", wrap_min3_float(1.0,2.0,3.0));
    printf("MIN3(1.0,2.0,3.0) returned %f, should have been 25.0.\n", wrap_min3_float_enclose(1.0,2.0,3.0, 5));
#else
    printf("Implement MIN3 first");
#endif
}
