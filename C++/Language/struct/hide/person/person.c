#include "person.h"
#include "person_private.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

Person* createPerson(const char* name,int age)
{
	if(strlen(name) >= NAME_SIZE)
	{
		fputs("createPerson error: name is too long\n",stdout);
		return NULL;
	}
	
	Person* pperson = (Person*)malloc(sizeof(Person));
	if(pperson == NULL)
	{
		puts("createPerson error: pperson malloc failed");
		return NULL;
	}
	strcpy(pperson->name,name);
	pperson->age = age;
	
	return pperson;
}

void destroyPerson(Person** ppperson)
{
	if(*ppperson != NULL)
	{
		free(*ppperson);
		*ppperson = NULL;
	}
}

void setName(Person* pperson,const char* name)
{
	if(pperson == NULL || strlen(name) >= NAME_SIZE)
	{
		fprintf(stdout,"setName error: pperson is null,or name is too long\n");
		return ;
	}
	
	memset(pperson->name,0,NAME_SIZE);
	memcpy(pperson->name,name,strlen(name) + 1);
}

const char* getName(const Person* pperson)
{
	if(pperson == NULL)
	{
		printf("getName error: pperson is null\n");
		return NULL;
	}
	
	return pperson->name;
}

void setAge(Person* pperson,int age)
{
	if(pperson == NULL || age < 0)
	{
		fputs("setAge error: pperson is null,or age is less than zero\n",stdout);
		return ;
	}
	
	pperson->age = age;
}

int getAge(const Person* pperson)
{
	assert(pperson != NULL);
	return pperson->age;
}

void showPerson(const Person* pperson)
{
	if(pperson == NULL)
	{
		puts("showPerson error: pperson is null");
		return ;
	}
	
	printf("name =%s, age =%d\n",pperson->name,pperson->age);
}