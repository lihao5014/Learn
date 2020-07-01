#include "common.h"
#include "foo.h"
#include "bar.h"
#include "qux.h"
#include <stdio.h>

static void echo();
static void square(data_t data);

int main(void)
{
	foo(echo);

	register_function(square);
	bar(5);
	
	CallBack callback = {echo,square};
	register_callback(callback);
	baz();
	qux(10);
	
	return 0;
}

void echo()
{
	puts("hello world");
}

void square(data_t data)
{
	printf("%d x %d = %d\n",data,data,data * data);
}