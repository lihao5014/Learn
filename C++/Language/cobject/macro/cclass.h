#ifndef _CCLASS_H
#define _CCLASS_H

#include <stdlib.h>
#include <stdio.h>

#define Conn(x,y) x##y
#define CONN(x,y) Conn(x,y)

#define ToString(x) #x
#define TOSTRING(x) ToString(x)

#define CLASS(type)                  \
typedef struct type type;            \
void* type##_New();                  \
void type##_Delete(type** cthis);    \
struct type

#define CTOR(type)                                                          \
void* type##_New()                                                          \
{                                                                           \
	struct type *cthis;                                                     \
	cthis = (struct type*)malloc(sizeof(struct type));                      \
	if(cthis == NULL)                                                       \
	{                                                                       \
		printf("%s warn: malloc failed!\n",TOSTRING(CONN(type,_New)));      \
		exit(-1);                                                           \
	}

#define END_CTOR(type)              \
	return (void*)cthis;            \
}                                   \
                                    \
void type##_Delete(type** cthis)    \
{                                   \
	if(*cthis != NULL)              \
	{                               \
		free(*cthis);               \
		*cthis = NULL;              \
	}                               \
}						 

#define FUNCTION_SETTING(fun,foo)   \
	cthis->fun = foo;

#endif //_CCLASS_H