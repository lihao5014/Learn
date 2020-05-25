#include "employee.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define NAME_SIZE 32

typedef struct
{
	char name[NAME_SIZE];
	int num;
}Employee;

HEmployee createEmployee(const char* name,int num)
{
	if(name == NULL || strlen(name) >= NAME_SIZE)
	{
		puts("createEmployee error: name is null,or name is too long");
		return NULL;
	}
	
	Employee* pemployee = (Employee*)malloc(sizeof(Employee));
	if(pemployee == NULL)
	{
		fputs("createEmployee error: pemployee malloc failed\n",stdout);
		return NULL;
	}
	memset(pemployee->name,0,NAME_SIZE);
	memcpy(pemployee->name,name,strlen(name) + 1);
	pemployee->num = num;
	
	return (HEmployee)pemployee;
}

void destroyEmployee(HEmployee *hemployee)
{
	if(*hemployee != NULL)
	{
		free(*hemployee);
		*hemployee = NULL;
	}
}

void setName(HEmployee hemployee,const char* name)
{
	if(hemployee == NULL || name == NULL || strlen(name) >= NAME_SIZE)
	{
		puts("setName error: hemployee or name is illegal");
		return ;
	}
	
	if(hemployee != NULL)
	{
		Employee* pemployee = (Employee*)hemployee;
		memset(pemployee->name,0,NAME_SIZE);
		memcpy(pemployee->name,name,strlen(name) + 1);
	}	
}

const char* getName(HEmployee hemployee)
{
	if(hemployee == NULL)
	{
		fputs("getName error: hemployee is null\n",stdout);
		return NULL;
	}
	
	if(hemployee != NULL)
	{
		Employee* pemployee = (Employee*)hemployee;
		return pemployee->name;
	}
	return NULL;	
}

void setNum(HEmployee hemployee,int num)
{
	if(hemployee == NULL)
	{
		fprintf(stdout,"setNum error: hemployee is null\n");
		return ;
	}

	if(hemployee != NULL)
	{
		Employee* pemployee = (Employee*)hemployee;
		pemployee->num = num;
	}
}

int getNum(HEmployee hemployee)
{
	assert(hemployee != NULL);
	
	Employee* pemployee = (Employee*)hemployee;
	return pemployee->num;	
}

void showEmployee(HEmployee hemployee)
{
	if(hemployee == NULL)
	{
		printf("showEmployee error: hemployee is null\n");
		return ;
	}
	
	if(hemployee != NULL)
	{
		Employee* pemployee = (Employee*)hemployee;
		printf("name =%s, num =%d\n",pemployee->name,pemployee->num);
	}	
}