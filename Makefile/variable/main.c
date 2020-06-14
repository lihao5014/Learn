#include "extreme.h"
#include <stdio.h>

int main()
{
	printf("5 greater than 3: %s\n",strBool[isMax(5,3)]);
	printf("5 and 3 max is: %d\n",max(5,3));
	printf("4,6,8 max is:%d\n",Max(4,6,8));
	
	printf("5 less than 3: %s\n",strBool[isMin(5,3)]);
	printf("5 and 3 min is: %d\n",min(5,3));
	printf("4,6,8 min is:%d\n",Min(4,6,8));
	
	return 0;
}