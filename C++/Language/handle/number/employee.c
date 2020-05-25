#include "employee.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define NAME_SIZE 32
#define ARRAY_SIZE 100

typedef struct
{
	char name[NAME_SIZE];
	int num;
}Employee;

static Employee* employeeArr[ARRAY_SIZE] = {0};

int createEmployee(const char* name,int num)
{
	if(name == NULL || strlen(name) >= NAME_SIZE)
	{
		puts("createEmployee error: name is illegal");
		return -1;
	}
	
	Employee* pemployee = (Employee*)malloc(sizeof(Employee));
	if(pemployee == NULL)
	{
		fputs("createEmployee error: pemployee malloc failed\n",stdout);
		return -1;
	}
	memset(pemployee->name,0,NAME_SIZE);
	memcpy(pemployee->name,name,strlen(name) + 1);
	pemployee->num = num;
	
	for(int i=0;i<ARRAY_SIZE;++i)
	{
		if(employeeArr[i] == NULL)
		{
			employeeArr[i] = pemployee;
			return i;
		}
	}
	
	printf("createEmployee error: employeeArr is filled\n");
	free(pemployee);
	pemployee = NULL;
	return -1;
}

void destroyEmployee(int handle)
{
	if(handle < 0 || handle > ARRAY_SIZE)
	{
		fprintf(stdout,"destroyEmployee error: handle is illegal\n");
		return ;
	}
	
	if(employeeArr[handle] != NULL)
	{
		free(employeeArr[handle]);
		employeeArr[handle] = NULL;
	}
}

void setName(int handle,const char* name)
{
	if(handle < 0 || handle > ARRAY_SIZE || name == NULL || strlen(name) >= NAME_SIZE)
	{
		puts("setName error: handle or name is illegal");
		return ;
	}
	
	if(employeeArr[handle] != NULL)
	{
		memset(employeeArr[handle]->name,0,NAME_SIZE);
		memcpy(employeeArr[handle]->name,name,strlen(name) + 1);
	}
}

const char* getName(int handle)
{
	if(handle < 0 || handle > ARRAY_SIZE)
	{
		fputs("getName error: handle is illegal\n",stdout);
		return NULL;
	}
	
	if(employeeArr[handle] != NULL)
	{
		return employeeArr[handle]->name;
	}
	return NULL;
}

void setNum(int handle,int num)
{
	if(handle < 0 || handle > ARRAY_SIZE)
	{
		fprintf(stdout,"setNum error: handle is illegal\n");
		return ;
	}

	if(employeeArr[handle] != NULL)
	{
		employeeArr[handle]->num = num;
	}
}

int getNum(int handle)
{
	assert(handle >= 0);
	assert(handle < ARRAY_SIZE);
	assert(employeeArr[handle] != NULL);
	
	return employeeArr[handle]->num;
}

void showEmployee(int handle)
{
	if(handle < 0 || handle > ARRAY_SIZE)
	{
		printf("showEmployee error: handle is illegal\n");
		return ;
	}
	
	if(employeeArr[handle] != NULL)
	{
		printf("name =%s, num =%d\n",employeeArr[handle]->name,employeeArr[handle]->num);
	}
}