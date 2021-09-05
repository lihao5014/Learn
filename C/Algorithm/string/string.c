#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define _CHANGE_WAY_
// #undef _CHANGE_WAY_

static char* strToUpper(char *str);
static char* strToLower(char* str);

int main(void)
{
	char str[] = "abCDeFGh";
	printf("str =%s\n",str);
	
	strToUpper(str);
	printf("str =%s ,Lowercase to uppercase\n",str);
	
	strToLower(str);
	printf("str =%s ,uppercase to lowercase\n",str);
	
	return 0;
}

#ifndef _CHANGE_WAY_
char* strToUpper(char *str)
{
	assert(str != NULL);
	
	char *p = str;
	while(*p != '\0')
	{
		if(*p >= 'a' && *p <= 'z')
		{
			*p -= 'a' - 'A';
		}
		p++;
	}
	
	return str;
}

char* strToLower(char* str)
{
	assert(str != NULL);
	
	char *p = str;
	while(*p != '\0')
	{
		if(*p >= 'A' && *p <= 'Z')
		{
			*p += 'a' - 'A';
		}
		++p;
	}
	
	return str;
}
#else
char* strToUpper(char *str)
{
	if(str == NULL)
	{
		puts("strToUpper error: str is null");
		return NULL;
	}
	
	const char index[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	for(char *p = str;*p != '\0';++p)
	{
		if(*p >= 'a' && *p <= 'z')
		{
			*p = index[*p - 'a'];
		}
	}
	
	return str;
}

char* strToLower(char* str)
{
	if(str == NULL)
	{
		puts("strToLower error: str is null");
		return NULL;
	}
	
	const char index[] = "abcdefghigklmnopqrstuvwxyz";
	for(char *p = str;*p != '\0';++p)
	{
		if(*p >= 'A' && *p <= 'Z')
		{
			*p = index[*p - 'A'];
		}
	}
	
	return str;
}
#endif