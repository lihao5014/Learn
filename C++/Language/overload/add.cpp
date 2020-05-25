#include "add.h"
#include <stdio.h>

#define _GCC_

#define IMPLEMENT_TWO

#ifdef _GCC_
#undef IMPLEMENT_TWO
#endif

#ifndef IMPLEMENT_TWO
int add(int x,int y) 
{
	printf("called1: int add(int x,int y)\n");
	return x + y;
} 
#else
int add(const int x,const int y)                 //等价于 int add(int x,int y) 
{
	printf("called2: int add(const int x,const int y)\n");
	return x + y;
} 
#endif	

#ifndef IMPLEMENT_TWO
int add(int* x,int* y)
{
	fprintf(stdout,"called1: int add(int* x,int* y)\n");
	return *x + *y;
}
#else
int add(int* const x,int* const y)                //等价于 int add(int* x,int* y)
{
	fprintf(stdout,"called2: int add(int* const x,int* const y)\n");
	return *x + *y;
}	
#endif

#ifndef IMPLEMENT_TWO
int add(const int* x,const int* y)
{
	puts("called1: int add(const int* x,const int* y)");
	return *x + *y;
}
#else
int add(const int* const x,const int* const y)      //等价于 int add(const int* x,const int* y)
{
	puts("called2: int add(const int* const x,const int* const y)");
	return *x + *y;
}	
#endif

#ifndef IMPLEMENT_TWO
int add(int& x,int& y)
{
	fputs("called1: int add(int& x,int& y)\n",stdout);
	return x + y;
}
#else
int add(int& const x,int& const y)                   //VC++编译器支持int& const类型；GCC编译器则认为加const多此一举，编译会报错
{
	fputs("called2: int add(int& const x,int& const y)\n",stdout);
	return x + y;	
}	
#endif

#ifndef IMPLEMENT_TWO
int add(const int& x,const int& y)
{
	fprintf(stderr,"called1: int add(const int& x,const int& y)");
	return x + y;
}
#else
int add(const int& const x,const int& const y)       //VC++编译器支持const int& const类型；GCC编译器则认为加const多此一举，编译会报错
{
	fprintf(stderr,"called1: int add(const int& x,const int& y)");
	return x + y;
}	
#endif

void Test::foo()
{
	fputs("called: void foo()\n",stdout);
}

void Test::foo()const
{
	puts("called: void foo()const");
}