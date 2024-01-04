# include <stdio.h>
# include "source.h"

double fracsum(int x, int y, int a, int b) 
{
    double xy = (float)x/y;
    double ab = (float)a/b;

    return (xy+ab);
}