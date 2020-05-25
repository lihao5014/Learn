#include <stdio.h>

int main(int argc,char** argv)
{
	const int n;
	
//	n = 10;
//	printf("n=%d\n",n);
	
	int* p = &n;              //对于C语言可以通过指针修改const变量的值
	*p = 20;
	printf("n=%d\n",n);
	
	return 0;
}