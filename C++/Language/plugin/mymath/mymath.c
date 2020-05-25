#include "mymath.h"
#include <stdio.h>

data_t add(const data_t x,const data_t y)
{
    printf("%d + %d = %d\n",x,y,x+y);
    return x+y;
}

data_t sub(const data_t x,const data_t y)
{
    printf("%d - %d = %d\n",x,y,x-y);
    return x-y;
}

data_t mult(const data_t x,const data_t y)
{
    printf("%d * %d = %d\n",x,y,x*y);
    return x*y;
}

double divi(const data_t x,const data_t y)
{
    printf("%d / %d = %d\n",x,y,x/y);
    return (double)x/y;
}