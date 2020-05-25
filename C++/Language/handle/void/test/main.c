#include "point.h"
#include <stdio.h>

int main(void)
{
	void* handle = createPoint(3,4);
	display(handle);
	
	setX(handle,7);
	setY(handle,8);
	
#ifdef _ERROR_
	printf("x = %d\n",handle->x);             //错误，句柄handle不知道Point结构体内部的实现，
	fprintf(stdout,"y =%d\n",handle->y);      //所以不能直接取隐藏结构体Point中的数据。
#else
	printf("x = %d\n",getX(handle));
	fprintf(stdout,"y =%d\n",getY(handle));	
#endif                                        //_ERROR_

	display(handle);
	
	return 0;
}