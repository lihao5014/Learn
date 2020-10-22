#include "printui.h"
#include <stdio.h>

#define _CHANGE_WAY_
// #undef _CHANGE_WAY_

static void alignTest();

int main(int argc,char** argv)
{
	alignTest();
	
	welcomeUI("hello world");
	welcomeUI("hello world!");
	
	simpleUI("my print ui");
	simpleUI("my print: ui");
	
	label(24,"my text ui");
	label(24,"my text: ui");
	
	return 0;
}

void alignTest()
{
#ifndef _CHANGE_WAY_
	printf("name\tchinese\tmath\tenglish\n");           //数字相差不大时可以使用\t制表符对齐
	printf("%s\t%d\t%d\t%d\n","amy",85,65,78);
	printf("%s\t%d\t%d\t%d\n","lisa",80,85,67);
	printf("%s\t%d\t%d\t%d\n","kavin",71,92,58);
	printf("%s\t%d\t%d\t%d\n","too long name",71,93,72);
#else
	printf("%-10s\t%-10s\t%-10s\t%-10s\n","name","chinese","math","english");
	printf("%-10s\t%-10d\t%-10d\t%-10d\n","amy",85,65,78);
	printf("%-10s\t%-10d\t%-10d\t%-10d\n","lisa",80,85,67);
	printf("%-10s\t%-10d\t%-10d\t%-10d\n","kavin",71,92,58);
	printf("%-10s\t%-10d\t%-10d\t%-10d\n","too long name",71,93,72);    //如果数字相差太大，可以先将每个数据位宽限制相同再使用制表符
#endif
}