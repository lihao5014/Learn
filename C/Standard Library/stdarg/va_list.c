#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>     //va_list,va_start(),va_arg(),va_end()
#include <assert.h>

typedef unsigned int count_t;

static int sum_int(count_t len,...);
static double average_int(count_t len,...);

static double sum_float(size_t size,...);
static double average_float(size_t size,...);

static int max(count_t len,...);
static int min(count_t len,...);

static double maxf(size_t count,...);  //fmax()/fmin()是C99自带的函数，所以自定义函数不能使用fmax或fmin函数名。
static double minf(size_t count,...);

int main(void)
{
	int ret = sum_int(10,10,11,12,13,14,15,16,17,18,19);
	printf("10 + 11 + ... + 19 =%d\n",ret);
	
	double result = average_int(10,10,11,12,13,14,15,16,17,18,19);
	printf("(10 + 11 + ... + 19)/10 =%f\n",result);
	
	double total = sum_float(5,3.14,2.718,1.414,0.618,1.732);
	printf("3.14 + 2.718 + 1.414 + 0.618 + 1.732 =%f\n",total);
	
	double avg = average_float(5,3.14,2.718,1.414,0.618,1.732);
	printf("(3.14 + 2.718 + 1.414 + 0.618 + 1.732)/5 =%f\n",avg);
	
	int num = max(10,10,11,12,13,14,15,16,17,18,19);
	printf("10,11 + ... + 19 max =%d\n",num);
	
	num = min(10,10,11,12,13,14,15,16,17,18,19);
	printf("10,11 + ... + 19 min =%d\n",num);
	
	double data = maxf(5,3.14,2.718,1.414,0.618,1.732);
	printf("3.14,2.718,1.414,0.618,1.732 max =%f\n",data);
	
	data = minf(5,3.14,2.718,1.414,0.618,1.732);
	printf("3.14,2.718,1.414,0.618,1.732 min =%f\n",data);
	
	return 0;
}

int sum_int(count_t len,...)
{
	va_list ap;
	
	int total = 0;
	va_start(ap,len);
	while(len-->0)
	{
		int num = va_arg(ap,int);
		total += num;
	}
	
	va_end(ap);
	return total;
}

/*（1）avg = (a1 + a2 + .. + an) / n求平均值公式，如果n的值很大，那么就可能造成所有数字求和时，整数越界。
 *（2）avg(n) = avg(n-1) + (an - avg(n-1)) / n求平均值公式，不用先对所有数字求和再除以n，就可以避免整数越界问题。
 */
double average_int(count_t len,...)
{
	double ret = 0;
	va_list arg_list;
	va_start(arg_list,len);
	for(int i=1;i <= len;++i)
	{
		int value = va_arg(arg_list,int);
		ret = ret + (value - ret) / i;
	}
	
	va_end(arg_list);
	return ret;
}

double sum_float(size_t size,...)
{
	va_list arg_ptr;
	
	double result = 0.0;
	va_start(arg_ptr,size);
	while(size-->0)
	{
		double data = va_arg(arg_ptr,double);
		result += data;
	}
	
	va_end(arg_ptr);
	return result;
}

double average_float(size_t size,...)
{
	va_list args;
	va_start(args,size);
	
	double ret = 0.0;
	for(int i=0;i<size;++i)
	{
		ret += va_arg(args,double);     //先进行数值累加，再求平均值的做法有可能造成数值越界问题。
	}
	
	va_end(args);
	return ret / size;
}

int max(count_t len,...)
{
	assert(len != 0);
	
	va_list p_args;
	va_start(p_args,len);
	
	int temp = va_arg(p_args,int);
	for(int i=1;i<len;++i)
	{
		int num = va_arg(p_args,int);
		if(num > temp)
		{
			temp = num;
		}
	}
	
	va_end(p_args);
	return temp;
}

int min(count_t len,...)
{
	if(len == 0)
	{
		puts("min() error: len is zero!");
		abort();
	}
	
	va_list valist;
	va_start(valist,len);
	
	int ret = va_arg(valist,int);
	while(len-->1)
	{
		int temp = va_arg(valist,int);
		if(temp < ret)
		{
			ret = temp;
		}
	}
	
	va_end(valist);
	return ret;
}

double maxf(size_t count,...)
{
	if(count == 0)
	{
		puts("maxf() error: count is zero!");
		exit(-1);
	}
	
	va_list pargs;
	va_start(pargs,count);
	
	double temp = va_arg(pargs,double);
	for(int i=1;i<count;++i)
	{
		double num = va_arg(pargs,double);
		if(num > temp)
		{
			temp = num;
		}
	}
	
	va_end(pargs);
	return temp;
}

double minf(size_t count,...)
{
	assert(count != 0);
	
	va_list argsPtr;
	va_start(argsPtr,count);
	
	double ret = va_arg(argsPtr,double);
	while(count-->1)
	{
		double temp = va_arg(argsPtr,double);
		if(temp < ret)
		{
			ret = temp;
		}
	}
	
	va_end(argsPtr);
	return ret;
}

