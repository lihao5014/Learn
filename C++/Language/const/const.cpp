#include <stdio.h>

#define ERROE
#undef ERROE

#define _GCC_
#undef _GCC_

#define PRINT(expr) printf("%s =%d\n",#expr,(expr))

static void variable_test();
static void pointer_test();
static void reference_test();
static void volatile_test();

int main(int argc,char** argv)
{
	variable_test();
	pointer_test();
	reference_test();
	volatile_test();
	
	return 0;
}

void variable_test()
{
	puts("variable_test()");
	
	int x = 10;                   //普通变量
	const int y = 20;             //const限制变量的值不可改变。const int等效于int const
	int const z = 30;
#ifdef ERROE
	y = 40;
	z = 50;
#endif
	PRINT(x);
	PRINT(y);
	PRINT(z);
}

static void pointer_test()
{
	fputs("pointer_test()\n",stdout);
	int a=0,b=0;
	
	int *p = &a;          //普通指针
	const int *q = &a;    //指针指向的内容是const int类型，即指针指向不可修改的整型变量。指针指向的内容不可以修改，但是指针的指向可以修改。
	int const *r = &a;    //const int*等效于int const*     
	int* const s = &a;    //const指针指向的内容是int类型，即不可修改的指针指向整型变量。指针指向的内容可以修改。但是指针的指向不可以修改。
	const int* const t = &a;   //const指针指向的内容是const int类型。即不可修改的指针指向不可修改的整型变量。指针指向的内容和方向都不可以修改。
#ifdef ERROE
	*q = 1;
	*r = 2;
	*s = &b;
	*t = 3;
	t = &b;
#endif
	PRINT(*q);
	PRINT(*r);
	PRINT(*s);
	PRINT(*t);
}

void reference_test()
{
	printf("reference_test()\n");
	int x=0,y=0;
	
	int &a = x;              //普通引用
	const int& b = x;        //引用绑定的变量时const int类型，即引用不可修改变量的内容
	int const& c = x;        //在VC++中int&，int const&，const int& const三者等效。GCC中不支持int const&和const int& const这两种类型的引用
#ifndef _GCC_
	int& const d = x;        //int&与int& const等效，引用绑定到某个变量上，本来就不可以修改使其绑定到其他变量上。加const只是多此一举，GCC中直接不支持这种引用类型。
	const int& const e = x;
#endif

#ifdef ERROE
	b = 1;
	c = 2;
	e = 3;
#endif
	PRINT(b);
	PRINT(c);
	
	PRINT(d);
	PRINT(e);
}

static void volatile_test()
{
	const int n = 5;
	
//	n = 10;                          //const变量的大小不可以直接修改
//	printf("n=%d\n",n);
	
	int* p = (int*)&n;               //C++语言不能通过指针修改const变量的值，C语言可以
	*p = 20;
	printf("n =%d\n",n);
	
	volatile const int m = 7;
	
	int* q = (int*)&m;               //C++语言可以通过指针修改volatile const变量的值
	*q = 14;
	printf("m =%d\n",m);	
}