#include "swap.h"
#include <stdio.h>

void swap(data_t* const x,data_t* const y)
{
    printf("swap %d and %d\n",*x,*y);
    
    data_t temp = *x;
    *x = *y;
    *y = temp;
}