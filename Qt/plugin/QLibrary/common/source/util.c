#include "util.h"
#include <stdlib.h>
#include <math.h>

#define EPS 0.000001

#define BUFF_SIZE 512

static char g_cache[BUFF_SIZE] = {0};

int cmpInt(int x,int y)
{
	return x - y;
}

int cmpIntWrapper(const void* x,const void* y)
{
	return cmpInt(*((int*)x),*((int*)y));
}

int cmpFloat(double x,double y)
{
	if(fabs(x - y) < EPS)
	{
		return 0;
	}
	
	return x > y ? 1 : -1;
}

int cmpFloatWrapper(const void* x,const void* y)
{
	return cmpFloat(*(const double*)x,*(const double*)y);
}

void memswap(void* data1,void* data2,unsigned int size)
{
	if(data1 == NULL || data2 == NULL || size == 0)
	{
		TRACK("error: data1 or data2 is null,or size is zero!");
		return;
	}
	
	/*如果需要交换的2个数据size比预先定义的缓冲区小，那么就使用全局变量g_cache作为内存交换的中间变量，
	 *这样可以减少每次函数调用都会进行动态内存申请和释放的性能开销。
	 */
	if(size <= BUFF_SIZE)
	{
		memcpy(g_cache,data1,size);
		memcpy(data1,data2,size);
		memcpy(data2,g_cache,size);
	}
	else
	{
		char* buf = (char*)malloc(size);
		memcpy(data1,buf,size);
		memcpy(data2,data1,size);
		memcpy(buf,data2,size);
		free(buf);
	}
}