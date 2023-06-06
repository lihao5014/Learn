#include <stdio.h>
#include <stdarg.h>     //va_list,va_start(),va_arg(),va_end()

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
	int ret = sum_int(3,7,8,9);
	printf("7 + 8 + 9 =%d\n",ret);
	
	double result = average_int(5,3.14,2.718,1.414,0.618,1.732);
	printf("3.14 + 2.718 + 1.414 + 0.618 + 1.732 =%f\n",result);
	
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
		double value = va_arg(arg_list,double);
		ret = ret + (value - ret) / i;
	}
	
	va_end(arg_list);
	return ret;
}

double sum_float(size_t count,...)
{
	
}

double average_float(size_t count,...)
{
	
}

int max(count_t len,...)
{
	
}

int min(count_t len,...)
{
	
}

double maxf(size_t count,...)
{
	
}

double minf(size_t count,...)
{
	
}

