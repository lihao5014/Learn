#include "add.h"
#include <stdio.h>

#define ERROR
#undef ERROR

#define PRINT(expr) printf("%s =%d\n",#expr,(expr))

int main(int argc,char* argv[])
{
	int x = 3;
	int y = 4;

#ifdef ERROR
	int& z = 5;           //引用是变量的别名，所以只有变量才有引用，常量没有引用
#else
	const int& z = 5;     //C++规定const引用可以直接引用常量，当常引用绑定常量时，会新建一个临时变量temp，常引用绑定的实际上是这个临时变量。
                          //const int& z=5 <--> int temp =5; const int& z=temp。正是由于这个规定，才是C++的引用传递可以完全替代值传递。
#endif

	// PRINT(add(3,4));   //有歧义，可以调用int add(int,int) 或 int add(const int&,const int&)
	// PRINT(add(x,y));   //有歧义，可以调用int add(int,int) 或 int add(int&,int&)
	
	Test test1;
	test1.foo();
	
	const Test test2;
	test2.foo();
	
	return 0;
}