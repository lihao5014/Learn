#include <stdio.h>
#include <string.h>

#define _CHANGE_WAY_
#undef _CHANGE_WAY_

static char buf[][32] = {
	"*******************\n",
	"*                 *\n",
	"*   hello world   *\n",
	"*                 *\n",
	"*******************\n"
};

static void printUi()
{
	for(int i=0;i<sizeof(buf)/sizeof(buf[0]);++i)
	{
		printf("%s",buf[i]);
	}
}

static void modifyUi(const char* str)
{
	if(str == NULL || (strlen(str) > strlen(buf[0]) - 3))
	{
		puts("modifyUi error: str is null or too long");
		return ;
	}
	
#ifndef _CHANGE_WAY_
	int pos = ((strlen(buf[2])- 3) - strlen(str))/2 + 1;
	memset(&buf[2][1],' ',strlen(buf[2]) - 3);
	memcpy(&buf[2][pos],str,strlen(str));
#else
	const char *p = str;
	for(int i=0;i<strlen(buf[0]);++i)
	{
		if(buf[2][i] == '*')
		{
			continue;
		}
		
		if(buf[2][i] == '\n')
		{
			break;
		}
		
		if(i < ((strlen(buf[0]) - 3) - strlen(str))/2 + 1 || i >= ((strlen(buf[0]) - 3) + strlen(str))/2 + 1)
		{
			buf[2][i] = ' ';
		}
		else
		{
			buf[2][i] = *p++;
		}
	}
#endif
    
	printUi();
}

int main(int argc,char* argv[])
{
	printUi();
	modifyUi("hello c++");
	
	if(argc == 2 && argv != NULL && *argv != NULL)
	{
		modifyUi(argv[1]);
	}

	return 0;
};