#include <stdio.h>

#define _ERROR_
// #undef _ERROR_

char* getString()
{
#ifdef _ERROR_
	char str[] = "hello world";       //str是一个数组，而不是指针。
	printf("sizeof(str) =%d\n",sizeof(str));      //sizeof()运算符的返回值是size_t类型，所以最好使用%zu打印
#else
	static char str[] = "hello world";
	printf("sizeof(str) =%zu\n",sizeof(str));
#endif
	
	return str;      //函数不能返回临时变量的地址
}

int main()
{
	char* str = getString();
	printf("%s\n",str);
	
	return 0;
}