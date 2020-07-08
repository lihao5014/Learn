#include "math.h"
#include <stdio.h>

#define PRINT(expr) printf("%s= %f\n",#expr,(expr))

int main(int argc,char* argv[])
{
	PRINT(3.5+5.2);
	printf("%d + %d =%d\n",3,5,(int)add(3,5));                         //整型数只能使用%d打印，浮点数只能使用%f打印，如果交叉使用会出bug
	printf("%f + %f =%f\n",(double)3,(double)5,(double)add(3,5));      //浮点与整数在内存中的存储方式不一样，所以打印访问的方式也不相同。
	printf("%f + %f =%f\n",3.5,5.2,add(3.5,5.2));
	
	return 0;
}