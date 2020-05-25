#include <iostream>

#define Print(expr) printf("%s =%d\n",#expr,(expr))

int foo1(int x)              //形参是普通变量，在函数内部可以修改变量大小，且修改了形参大小不影响实参大小。
{
	x *= x;
	return x;
}

int foo2(const int x)       //形参是const变量，在函数内部不可以修改变量大小。
{
	// x *= x;
	return x * x;
}

int bar1(int* x)            //形参是指针，在函数内部可以修改指针指向的内容大小，且修改了形参指向的内容大小后，实参指向的内容大小也会变化。
{                            //也可以修改了指针指向的地址，但是修改了形参指针指向的地址以后，再修改指针指向的内容，实参指针指向的内容将不会被改变。
	*x *= *x;
	return *x;
}

int bar2(const int* x)      //形参是const指针，在函数内部不可以修改指针指向的内容大小。但是可以修改形参指针指向地址。
{
	// *x *= *x;
	return (*x)*(*x);
}

int qux1(int& x)            //形参是引用，在函数内部可以修改引用变量大小。当函数传参是引用时，实参和形参是同一个变量，形参只是实参的别名。
{
	x *= x;
	return x;
}

int qux2(const int& x)     //形参是const引用，在函数内部不可以修改引用变量大小。当函数传参是const引用时，实参和形参是同一个变量，形参只是实参的别名。
{
	// x *= x;
	return x * x;
}

#if 0
static int baz(int x);
#else
static int baz(const int x);
#endif

int main()
{
	int x = 3;
	Print(x);
	Print(foo1(x));
	Print(x);
	Print(foo2(x));
	Print(x);
	puts("");
	
	x = 4;
	Print(x);
	Print(bar1(&x));
	Print(x);
	Print(bar2(&x));
	Print(x);
	putc('\n',stdout);
	
	x = 5;
	Print(x);
	Print(qux1(x));
	Print(x);
	Print(qux2(x));
	Print(x);
	fputs("\n",stdout);
	
	x = 6;
	Print(x);
	Print(baz(x));
	
	return 0;
}

int baz(const int x)
{
	return x * x;
}