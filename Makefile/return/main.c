#include "math.h"
#include <stdio.h>

int main(void)
{
	bool isOk = false;
	data_t ret = sub(8,4,&isOk);
	if(isOk)
	{
		printf("%f - %f = %f\n",(double)8,(double)4,ret);
	}
	
	mult(4,5,&ret);
	printf("%f * %f =%f\n",(double)4,(double)5,ret);
	
	if(divi(9,7,&ret))
	{
		printf("%f / %f = %f\n",(double)9,(double)7,ret);
	}
	
	isOk = false;
	ret = 0;
	power(2.2,4,&ret,&isOk);
	if(isOk)
	{
		printf("pow(%f,%d) =%f\n",(double)2.2,4,ret);
	}
	
	data_t min = 0;
	data_t max = 0;
	extreme(7,6,&min,&max);
	printf("min =%f,max =%f\n",min,max);
	
	return 0;
}