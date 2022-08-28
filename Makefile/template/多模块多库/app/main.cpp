#include <cstdio>
#include "mymath.h"
#include "extreme.h"

extern "C" 
{
#include "mysort.h"
#include "point.h"
}

#define UNUSED(x) (void)x

int main(int argc,char* argv[])
{
	UNUSED(argc);
	UNUSED(argv);
	
	printf("%f + %f =%f\n",3.1,5.4,add(3.1,5.4));
	printf("%f - %f =%f\n",7.4,3.7,add(7.4,3.7));
	printf("%f * %f =%f\n",8.2,5.6,add(8.2,5.4));
	printf("%f / %f =%f\n",1.9,2.7,add(1.9,2.7));
	
	printf("5 greater than 3: %s\n",strBool[isgreater(5,3)]);
	printf("5 and 3 max is: %d\n",max(5,3));
	printf("4,6,8 max is:%d\n",max3(4,6,8));
	
	printf("5 less than 3: %s\n",strBool[isless(5,3)]);
	printf("5 and 3 min is: %d\n",min(5,3));
	printf("4,6,8 min is:%d\n",min3(4,6,8));
	
	int arr[] = {3,5,7,2,9,6,1,8,0,4};
	displayArray(arr,sizeof(arr)/sizeof(arr[0]));
	
	mysort(arr,sizeof(arr)/sizeof(int));
	displayArray(arr,sizeof(arr)/sizeof(arr[0]));

	Point* ppoint = createPoint(3,4);
	displayPoint(ppoint);
	
	setPointX(ppoint,7);
	setPointY(ppoint,8);
	
#ifdef _ERROR_
	printf("x = %f\n",ppoint->x);             //错误，句柄ppoint不知道Point结构体内部的实现，
	fprintf(stdout,"y = %f\n",ppoint->y);      //所以不能直接取隐藏结构体Point中的数据。
#else
	printf("x = %f\n",getPointX(ppoint));
	fprintf(stdout,"y = %f\n",getPointY(ppoint));	
#endif                                        //_ERROR_

	displayPoint(ppoint);
	
	return 0;
}
