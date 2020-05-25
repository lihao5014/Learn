//使用extern直接访问源文件，可以取消头文件包含。

#include <stdio.h>

extern int add(int x,int y);
int sub(int x,int y);			//默认情况是extern

//int mutl(int x,int y);

double div(int x,int y);
//double div(double x,double y);

int main()
{
	printf("x =%d, y =%d, sum =%d\n",4,5,add(4,5));
	printf("x =%d, y =%d, sub =%d\n",4,5,sub(4,5));
//	printf("x =%d, y =%d, sum =%d\n",4,5,mutl(4,5));
	printf("x =%d, y =%d, div =%f\n",4,5,div(4,5));
	
	return 0;
}