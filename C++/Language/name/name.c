//foo,bar,baz,bax,qur,qux,quz在编程中被用作占位符的名字，表示当前命名无关紧要，不影响当前代码的表达。
//类似于中文中的张三，李四，王五这类词汇。

#include <stdio.h>

void foo(const char* str)
{
	if(str != NULL)
	{
		printf("foo: %s\n",str);
	}
}

void bar(const char str[])
{
	if(str != NULL)
	{
		printf("bar: %s\n",str);
	}
}

int main(int argc,char **argv)
{
	const char baz[] = "Hello";
	const char* qux = "World";

	foo("foo method");
	bar("bar method");
	printf("variable: baz =%s,qux =%s\n",baz,qux);
	
	return 0;
}