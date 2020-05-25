#ifndef _ADD_H
#define _ADD_H

//这五种类型函数参数都可以构造函数重载，但调用的时候可能会有歧义

/*
1.const int x=5 等价于 int const x=5
2.const int& x=y 等价于 int& const x=y
3.const int* x=&y 不等于 int* const x=&y
*/

/* 
C++规定const int& x=5合法以后，int add(int x,int y)与int add(const int& x,const int& y)的功能完全相同，
并且引用传递的效率比值传递的高，不用多一次变量拷贝。所以C++建议函数传参都使用引用传递。
*/

//

int add(int x,int y);                   //等价于 int add(const int x,const int y)

int add(int* x,int* y);                 //等价于 int add(int* const x,int* const y)
int add(const int* x,const int* y);     //等价于 int add(const int* const x,const int* const y)

int add(int& x,int& y);                 //在VC++编译器中等价于 int add(int& const x,int& const y)，在GCC编译器中int& const类型编译不通过。
										//如果传入的参数是非cosnt变量，则优先调用int&版本。
										
int add(const int& x,const int& y);     //在VC++编译器中等价于 int add(const int& const x,const int& const y)，在GCC编译器中const int& const类型编译不通过。
			                            //如果传入的参数是cosnt变量，则优先调用const int&版本


class Test
{
public:
	void foo();
	void foo()const;
};

#endif //_ADD_H