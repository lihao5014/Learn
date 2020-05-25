#include "math.h"
#include <stdio.h>

#ifdef _TRACK_
#define Print(expr) printf("%s =%d\n",#expr,(expr))
#else
#define Print(expr)
#endif

int main(int argc,char **argv)
{
	double x = 3;                //对于C89标准要求所有的变量都定义在函数的开头，C99中则可以在任意位置定义变量
	double y = 4;
	double ret = 0;
	
	Print(1 + 2);
	
	printf("%f + %f =%f\n",x,y,Operater(x,y,add));
	
	OPERATER(x,-,y,ret);
	printf("%f - %f =%f\n",x,y,ret);
	
	return 0;
}