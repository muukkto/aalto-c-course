
#include "macros.h"

int wrap_eq3_int(int a, int b, int c){
#ifdef EQ3
    return EQ3(a, b, c);
#else
    (void)a;
    (void)b;
    (void)c;
    #error "The required macro EQ3 is not defined!"
#endif
}

int wrap_eq3_float(float a, float b, float c){
#ifdef EQ3
    return EQ3(a, b, c);
#else
    (void)a;
    (void)b;
    (void)c;
    #error "The required macro EQ3 is not defined!"
#endif
}

int wrap_eq3_float_enclose(float a, float b, float c, int scale){
#ifdef EQ3
    return scale*EQ3(a, b, c)*scale;
#else
    (void)a;
    (void)b;
    (void)c;
    (void)scale;
    #error "The required macro EQ3 is not defined!"
#endif
}

int wrap_min3_int(int a, int b, int c){
#ifdef MIN3
    return MIN3(a, b, c);
#else
    (void)a;
    (void)b;
    (void)c;
    #error "The required macro MIN3 is not defined!"
#endif
}

float wrap_min3_float(float a, float b, float c){
#ifdef MIN3
    return MIN3(a, b, c);
#else
    (void)a;
    (void)b;
    (void)c;
    #error "The required macro MIN3 is not defined!"
#endif
}

float wrap_min3_float_enclose(float a, float b, float c, int scale){
#ifdef MIN3
    return scale*MIN3(a, b, c)*scale;
#else
    (void)a;
    (void)b;
    (void)c;
    (void)scale;
    #error "The required macro MIN3 is not defined!"
#endif
}
