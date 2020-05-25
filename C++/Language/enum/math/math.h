#ifndef _MATH_H
#define _MATH_H

#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define FOREACH_CMD(cmd)      \
	cmd(UNSPEC)               \
	cmd(ADD)                  \
	cmd(SUB)                  \
	cmd(MULT)                 \
	cmd(DIVI)                 \
	cmd(OVER)

#define GENERATE_ENUM(opt) opt,
#define GENERATE_STRING(str) #str,

typedef enum Operator_t
{
	FOREACH_CMD(GENERATE_ENUM)
}Operator_t;

const char* operator_string[] = {
	FOREACH_CMD(GENERATE_STRING)
};

bool enumToString(const Operator_t opt,char *str)
{
	if(opt < 0 || opt >= OVER || str == NULL)
	{
		printf("enumToString warn: input illegal\n");
		return false;
	}
	
	strcpy(str,operator_string[opt]);
	return true;
}

bool stringToEnum(const char* str,Operator_t *opt)
{
	if(str == NULL || opt == NULL)
	{
		fprintf(stdout,"enumToString warn: input illegal\n");
		return false;
	}
	
	for(int i=0;i<OVER;++i)
	{
		if(0 == strcmp(str,operator_string[i]))
		{
			*opt = (Operator_t)i;
			return true;
		}
	}
	
	return false;
}

#endif //_MATH_H