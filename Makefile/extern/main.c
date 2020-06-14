#include "foobar.h"
#include <stdio.h>

extern int var;
extern const double pi;      //extern声明全局变量pi为const double，则定义变量pi也应该是const double类型

static void baz()
{
	extern int num;
	extern const double e;
	printf("call fun(): num =%d, e =%f\n",num,e);
}

static void qux();

int num = 10;
const double e = 2.718281;

int main(void)
{
	foo();
	bar();
	baz();
	qux();
	return 0;
}

void qux()
{
	printf("call qux(): var =%d, pi =%f\n",var,pi);
}