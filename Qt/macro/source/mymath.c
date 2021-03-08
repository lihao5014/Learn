/*如果pro文件中没有添加INCLUDEPATH += $$PWD/include语句，那么源文件中就得添加上头文件的
 *全路径名#include "../include/mymath.h"。不然就会在编译源文件时提示找不到头文件错误。
 */
 
#include "mymath.h"
#include <stdio.h>

static int add(int x,int y)
{
	printf("add: %d + %d = %d\n",x,y,x + y);
	return x + y;
}

static int sub(int x,int y)
{
	printf("sub: %d - %d = %d\n",x,y,x - y);
	return x - y;
}

//_SUB_是一个定义到pro文件中的宏，其作用类似于使用gcc/g++命令编译C/C++源文件时指定宏。
int operate(int x,int y)
{
#ifndef _SUB_
	puts("operate is add");
	return add(x,y);
#else
	fputs("operate is sub\n",stdout);
	return sub(x,y);
#endif
}