#include <stdio.h>
#include <string.h>
#include "libMathApi.h"

#define UNUSED(x) (void)x

int main(int argc,char** argv)
{
	double data = power(10,2);
	printf("power(10,2) =%f\n",data);
	
	printf("add(3,7) =%f\n",add(3,7));
	printf("sub(3,7) =%f\n",sub(3,7));
	printf("mult(3,7) =%f\n",mult(3,7));
	printf("divi(3,7) =%f\n",divi(3,7));
	putc('\n',stdout);
	
	PointPtr pointPtr = point_create(4,5);
	if(pointPtr == NULL)
	{
		puts("pointPtr is null!");
		return -1;
	}
	point_display(pointPtr);
	
	point_setX(pointPtr,14);
	point_setY(pointPtr,15);
	
	double x = point_getX(pointPtr);
	double y = point_getY(pointPtr);
	printf("(%f,%f)\n",x,y);
	
	PointPtr point1 = point_create(10,20);
	PointPtr point2 = point_create(3.14,2.718);
	point_add(point1,point2,pointPtr);
	point_display(pointPtr);
	
	point_sub(point1,point2,pointPtr);
	point_display(pointPtr);
	
	point_destroy(&pointPtr);
	point_destroy(&point1);
	point_destroy(&point2);
	puts("");
	
	int num = abs_int(-5);
	printf("abs_int(-5) =%d\n",num);
	
	double value = abs_float(-0.618);
	printf("abs_float(-0.618) =%f\n",value);
	
	printf("min_2i(2,1) =%d\n",min_2i(2,1));
	printf("min_3int(8,7,9) =%d\n",min_3int(8,7,9));
	
	printf("min_2f(3.5,5.5) =%f\n",min_2f(3.5,5.5));
	printf("min_3float(25.7,11.5,17.63) =%f\n",min_3float(25.7,11.5,17.63));
	
	printf("max_2i(2,1) =%d\n",max_2i(2,1));
	printf("max_3int(8,7,9) =%d\n",max_3int(8,7,9));
	
	printf("max_2f(3.5,5.5) =%f\n",max_2f(3.5,5.5));
	printf("max_3float(25.7,11.5,17.63) =%f\n",max_3float(25.7,11.5,17.63));
	
	char buf[32] = {0};
	intToString(654321,buf);
	printf("buf =%s\n",buf);
	
	memset(buf,0,sizeof(buf));
	intToString(-1234,buf);
	printf("buf =%s\n",buf);
	
	memset(buf,0,sizeof(buf));
	floatToString(123.1415926,buf);
	printf("buf =%s\n",buf);

	floatToString(-981.414,buf);
	printf("buf =%s\n",buf);
	
	return 0;
}