#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

static void myprintf(const char* format,...);

static char* intToString(int num);
static char* floatToString(double num);

int main(void)
{
	
	
	return 0;
}

void myprintf(const char* format,...)
{
	if(format == NULL)
	{
		return;
	}
	
	va_list pargs;
	va_start(format,pargs);
	
	const char* 
	while()
}

char* intToString(int num)
{
	
}

char* floatToString(double num)
{
	
}