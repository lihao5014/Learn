#include "macro_utils.h"
#include <string.h>
#include <stddef.h>

#define IS_GCC 1

#define X 123
#define Y 456

typedef struct FooBar
{
	char foo;
	int bar;
	double baz;
	float qux;
}FooBar;

int main(int argc,char **argv)
{
	Debug("hello world");
	Warn_IF(1 > 0);
	Assert(1 > 0);

#if IS_GCC
	puts(LinkStr("hello","world"));
#else	
	puts(Conn("hello","world"));       //Gcc编译器中不可以使用##连两字符串，但是VC++编译器可以 
#endif
	printf("%d\n",Conn(123,456));
	fprintf(stdout,"%d\n",CONN(X,Y));
	
	fputs(ToString(hello world\n),stdout);
	puts(TOSTRING(X));
	
	int num = 100;
	Show_Integer(num);
	ShowValue(num,d);
	
	printf("The maximum of 5 and 6 is %d\n",Max(5,6));
	fprintf(stdout,"The minimum of 5 and 6 is %d\n",Min(5,6));
	
	int x = 10;
	int y = 20;
	printf("swap before: x =%d, y = %d\n",x,y);
	Swap(x,y);
	printf("swap after: x =%d, y = %d\n",x,y);
	
	int temp = 0;
	SWAP(x,y,temp);
	printf("swap again: x =%d, y = %d\n",x,y);
	
	char *p = Malloc(strlen("hello world\n")+1,char);
	strcpy(p,"hello world\n");
	ShowValue(p,s);
	Free(p);
	if(p == NULL)
	{
		puts("p == NULL");
	}

	FooBar fooBar;
	printf("sizeof(%s) =%d, TypeSize(%s) =%d\n","FooBar",sizeof(FooBar),"FooBar",TypeSize(fooBar));
	printf("sizeof(%s) =%d, MemberSize(%s,%s) =%d\n","FooBar",sizeof(double),"FooBar","baz",MemberSize(FooBar,baz));
	printf("offsetof(%s,%s) =%d, OffsetSize(%s,%s) =%d\n","FooBar","baz",offsetof(FooBar,baz),"FooBar","baz",OffsetSize(FooBar,baz));
	
	Loop(1,10) Print(i);
	
	return 0;
}