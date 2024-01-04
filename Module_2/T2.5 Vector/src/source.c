#include <math.h>
#include <stdio.h>

double vectorlength(double x, double y, double z)
{
    double r = x*x + y*y + z*z;

    return sqrt(r);
}



