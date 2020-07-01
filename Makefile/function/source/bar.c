#include "bar.h"
#include <stdio.h>

static pFunc pcallback = NULL;

BOOL register_function(pFunc pfunc)
{
	if(pfunc == NULL)
	{	
		printf("register_function error: pFunc is null\n");
		return FALSE;
	}
	
	pcallback = pfunc;
	return TRUE;
}

void bar(data_t data)
{
	printf("---bar start---\n");
	if(pcallback != NULL)
	{
		pcallback(data);
	}
	else
	{
		printf("bar warn: pcallback is null\n");
	}
	printf("---bar end---\n");	
}