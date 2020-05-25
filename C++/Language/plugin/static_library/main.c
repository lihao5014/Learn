#include "swap.h"
#include <stdio.h>

int main()
{
    data_t a=10,b=5;
    
    printf("a =%d, b =%d\n",a,b);
    swap(&a,&b);
    printf("a =%d, b =%d\n",a,b);
    
    return 0;
}