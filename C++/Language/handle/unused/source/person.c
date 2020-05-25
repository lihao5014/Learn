#include "person.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define NAME_SIZE 32

typedef struct Person_t
{
	char name[NAME_SIZE];
	int age;
}Person;

HPerson createPerson(const char name[])
{
	if(strlen(name) >= NAME_SIZE)
	{
		puts("createPerson warn: name is too long");
		return NULL;
	}
	
	Person* pperson = (Person*)malloc(sizeof(Person));
	if(pperson == NULL)
	{
		fputs("createPerson warn: pperson malloc failed\n",stdout);
		return NULL;
	}
	memset(pperson->name,0,NAME_SIZE);                 //在为字符数组赋值时，最好先将其清空
	memcpy(pperson->name,name,strlen(name) + 1);
	pperson->age = 0;
	
	return (HPerson)pperson;
}

void destroyPerson(HPerson* hperson)
{
	if(*hperson != NULL)
	{
		free(*hperson);
		*hperson = NULL;
	}
}

void setName(HPerson hperson,const char* name)
{
	if(hperson == NULL || name == NULL || strlen(name) >= NAME_SIZE)
	{
		printf("setName error: hperson or name is null,or name is too long\n");
		return ;
	}
	
	Person* pperson = (Person*)hperson;
	memset(pperson->name,0,NAME_SIZE);                //在为字符数组赋值时，最好先将其清空
	strcpy(pperson->name,name);
}

const char* getName(const HPerson hperson)
{
	if(hperson == NULL)
	{
		fprintf(stdout,"getName error: hperson is null\n");
		return NULL;
	}
	
	const Person* pperson = (Person*)hperson;
	return pperson->name;
}

void setAge(HPerson hperson,const int age)
{
	if(hperson == NULL || age < 0)
	{
		fprintf(stdout,"setAge error: hperson is null,or age is less than zero\n");
		return ;
	}
	
	Person* pperson = (Person*)hperson;
	pperson->age = age;
}

int getAge(const HPerson hperson)
{
	assert(hperson != NULL);
	
	Person* pperson = (Person*)hperson;
	return pperson->age;
}

void showPerson(const HPerson hperson)
{
	if(hperson == NULL)
	{
		puts("hperson is null");
		return ;
	}
	
	Person* pperson = (Person*)hperson;
	printf("name =%s, age =%d\n",pperson->name,pperson->age);
}