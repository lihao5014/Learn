#include "person.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	union{
		Person public_person;
		char* m_name;
	};
	
	int m_age;
	Sex m_sex;
}PersonInternal;

Person* createPerson(const char name[])
{
	if(name == NULL)
	{
		printf("createPerson() warn: name is null\n");
		return NULL;
	}
	
	PersonInternal* private_person = (PersonInternal*)malloc(sizeof(PersonInternal));
	private_person->m_age = 0;
	private_person->m_sex = BOY;
	
	private_person->m_name = (char*)malloc(strlen(name) + 1);
	memset(private_person->m_name,0,strlen(name) + 1);
	memcpy(private_person->m_name,name,strlen(name) + 1);
	
	return &(private_person->public_person);
}

void destroyPerson(Person** ppersonPtr)
{
	if(ppersonPtr != NULL && *ppersonPtr != NULL)
	{
		free(*ppersonPtr);
		*ppersonPtr = NULL;
	}
}

void setPersonName(Person* personPtr,const char* pname)
{
	if(personPtr == NULL || pname == NULL)
	{
		const char* error = "setPersonName() warn: personPtr or pname is null\n";
		fwrite(error,strlen(error) + 1,1,stderr);
		return;
	}
	
	PersonInternal* private_person = (PersonInternal*)personPtr;
	if(private_person->m_name != NULL)
	{
		free(private_person->m_name);
		private_person->m_name = NULL;
	}
	
	int len = strlen(pname) + 1;
	private_person->m_name = (char*)malloc(len);
	memset(private_person->m_name,0,len);
	strcpy(private_person->m_name,pname);
}

const char* getPersonName(const Person* personPtr)
{
	if(personPtr == NULL)
	{
		fputs("getPersonName() warn: personPtr is null\n",stdout);
		return NULL;
	}
	
	const PersonInternal* private_person = (PersonInternal*)personPtr;
	return private_person->m_name;
}

void setPersonAge(Person* personPtr,int age)
{
	if(personPtr == NULL)
	{
		fprintf(stdout,"setPersonAge() warn: personPtr is null\n");
		return;
	}
	
	if(age < 0 || age > 120)
	{
		puts("setPersonAge() error: input age is illegal");
		return;
	}
	
	PersonInternal* private_person = (PersonInternal*)personPtr;
	private_person->m_age = age;
}

int getPersonAge(const Person* personPtr)
{
	if(personPtr == NULL)
	{
		perror("getPersonAge() warn: personPtr is null\n");
		return -1;
	}
	
	const PersonInternal* private_person = (PersonInternal*)personPtr;
	return private_person->m_age;
}

void setPersonSex(Person* personPtr,Sex sex)
{
	if(personPtr == NULL)
	{
		perror("setPersonSex() warn: personPtr is null\n");
		return;
	}
	
	if(sex != BOY && sex != GIRL)
	{
		puts("setPersonSex() error: input sex is illegal");
		return;
	}
	
	PersonInternal* private_person = (PersonInternal*)personPtr;
	private_person->m_sex = sex;
}

Sex getPersonSex(const Person* personPtr)
{
	if(personPtr == NULL)
	{
		const char* error = "getPersonSex() warn: personPtr is null\n";
		fwrite(error,strlen(error) + 1,1,stdout);
		return UNKNOWN;
	}
	
	const PersonInternal* private_person = (PersonInternal*)personPtr;
	return private_person->m_sex;
}

void showPerson(const Person* personPtr)
{
	if(personPtr == NULL)
	{
		fputs("showPerson() warn: personPtr is null\n",stderr);
		return;
	}

	const PersonInternal* private_person = (PersonInternal*)personPtr;
	if(private_person->m_name != NULL)
	{
		printf("name: %s\n",private_person->m_name);
	}
	else
	{
		printf("name: null\n");
	}
	
	printf("age: %d\n",private_person->m_age);
	
	const char* strSex = private_person->m_sex == BOY ? "boy" : "girl";
	printf("sex: %s\n",strSex);
}