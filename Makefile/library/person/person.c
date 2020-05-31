#include "person.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_SIZE 32

struct Person
{
	char name[NAME_SIZE];
	int age;
};

Person* createPerson(const char* name,int age)
{
	if(name == NULL || age < 0 || strlen(name) >= NAME_SIZE)
	{
		puts("createPerson error: input arguments is illegal");
		return NULL;
	}
	
	Person* pperson = (Person*)malloc(sizeof(Person));
	if(pperson == NULL)
	{
		perror("createPerson error: pperson malloc failed\n");
		return NULL;
	}
	memset(pperson->name,0,NAME_SIZE);
	strncpy(pperson->name,name,strlen(name));
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

void setName(Person *pthis,const char* name)
{
	if(pthis == NULL || name == NULL || strlen(name) >= NAME_SIZE)
	{
		fputs("setName error: pthis or name is null,or name is too long\n",stdout);
		return ;
	}
	
	memset(pthis->name,0,sizeof(Person));
	strcpy(pthis->name,name);
}

const char* getName(const Person *pthis)
{
	if(pthis == NULL)
	{
		printf("getName error: pthis is null");
		return NULL;
	}
	
	return pthis->name;
}

void setAge(Person *pthis,const int age)
{
	if(pthis == NULL || age < 0)
	{
		printf("setAge error: pthis is null,or age is less than zero\n");
		return ;
	}
	
	pthis->age = age;
}

int getAge(const Person *pthis)
{
	if(pthis == NULL)
	{
		fprintf(stdout,"getAge error: pthis is null\n");
		return -1;
	}
	
	return pthis->age;
}

void showPerson(const Person* pthis)
{
	if(pthis == NULL)
	{
		puts("showPerson error: pthis is null");
		return ;
	}
	
	printf("name =%s, age =%d\n",pthis->name,pthis->age);
}