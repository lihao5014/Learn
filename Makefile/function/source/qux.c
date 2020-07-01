#include "qux.h"
#include <stdio.h>

static CallBack s_callback = {NULL,NULL};

BOOL register_callback(CallBack callback)
{
	if(callback.pfun == NULL || callback.pfunc == NULL)
	{
		fputs("register_callback: callback.pfun or callback.pfunc is null\n",stdout);
		return FALSE;
	}
	
	s_callback.pfun = callback.pfun;
	s_callback.pfunc = callback.pfunc;
}

void baz()
{
	fputs("---baz start---\n",stdout);
	if(s_callback.pfun != NULL)
	{
		s_callback.pfun();
	}
	fputs("---baz end---\n",stdout);
}

void qux(data_t data)
{
	fprintf(stdout,"---qux start---\n");
	if(s_callback.pfunc != NULL)
	{
		s_callback.pfunc(data);
	}
	fprintf(stdout,"---qux end---\n");
}