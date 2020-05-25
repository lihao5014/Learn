#include "student.h"
#include <stdio.h>
#include <string.h>
#include <assert.h>

#define _CHANGE_WAY_
// #undef _CHANGE_WAY_

const int offsetArr[PROPERTY_COUNT] = 
{
	[NUM] = offsetof(Student,num),
	[NAME] = offsetof(Student,name),
	[SEX] = offsetof(Student,sex),
	[AGE] = offsetof(Student,age),
	[SCORE] = offsetof(Student,score),
	[ADDRESS] = offsetof(Student,addr),
	[TELEPHONE] = offsetof(Student,tel),
};

void showStudent(const Student student)
{
	fprintf(stdout,"%d %s %d %d %f %s %s\n",
		student.num,
		student.name,
		student.sex,
		student.age,
		student.score,
		student.addr,
		student.tel
	);
}

#ifndef _CHANGE_WAY_
void showArray(const char arr[],int size)
{
	if(size != STUDENT_SIZE)
	{
		puts("arr is't student array");
		return ;
	}
	
	const char* p = arr;
	char name[NAME_SIZE] = {0};
	memcpy(name,p+offsetArr[NAME],NAME_SIZE);
	
	char addr[ADDRESS_SIZE] = {0};
	memcpy(addr,p+offsetArr[ADDRESS],ADDRESS_SIZE);
	
	char tel[TELEPHONE_SIZE] = {0};
	memcpy(tel,p+offsetArr[TELEPHONE],TELEPHONE_SIZE);
	
	printf("%d %s %d %d %f %s %s\n",
		*((int*)(p+offsetArr[NUM])),
		name,
		*((Sex*)(p+offsetArr[SEX])),
		*(p+offsetArr[AGE]),
		*((double*)(p+offsetArr[SCORE])),
		addr,
		tel
	);
}

void studentToArray(const Student student,char* arr,int arrSize)
{
	if(arr == NULL || arrSize < STUDENT_SIZE)
	{
		fputs("arr is null,or arrSize less than student size\n",stdout);
		return ;
	}
	
	char* p = arr;
	*((int*)(p+offsetArr[NUM])) = student.num;
	memcpy(p+offsetArr[NAME],student.name,NAME_SIZE);
	*((Sex*)(p+offsetArr[SEX])) = student.sex;
	*(p+offsetArr[AGE]) = student.age;
	*((double*)(p+offsetArr[SCORE])) = student.score;
	memcpy(p+offsetArr[ADDRESS],student.addr,sizeof(student.addr));
	memcpy(p+offsetArr[TELEPHONE],student.tel,sizeof(student.tel));
}

void arrayToStudent(const char* arr,int arrSize,Student* student)
{
	if(arr == NULL || arrSize < STUDENT_SIZE || student == NULL)
	{
		puts("arr or student is null,or arrSize less than student size");
		return ;
	}
	
	const char* p = arr;
	student->num = *((int*)(p+offsetArr[NUM]));
	memcpy(student->name,p+offsetArr[NAME],NAME_SIZE);
	student->sex = *((Sex*)(p+offsetArr[SEX]));
	student->age = *(p+offsetArr[AGE]);
	student->score = *((double*)(p+offsetArr[SCORE]));
	memcpy(student->addr,p+offsetArr[ADDRESS],ADDRESS_SIZE);
	memcpy(student->tel,p+offsetArr[TELEPHONE],TELEPHONE_SIZE);
}
#else
void showArray(const char arr[],int size)
{
	if(size != STUDENT_SIZE)
	{
		puts("arr is't student array");
		return ;
	}
	
	const Student* pstudent = (Student*)arr;
	printf("%d %s %d %d %f %s %s\n",
		pstudent->num,
		pstudent->name,
		pstudent->sex,
		pstudent->age,
		pstudent->score,
		pstudent->addr,
		pstudent->tel
	);
}

void studentToArray(const Student student,char* arr,int arrSize)
{
	if(arr == NULL || arrSize < STUDENT_SIZE)
	{
		fputs("arr is null,or arrSize less than student size\n",stdout);
		return ;
	}
	
	Student* pstudent = (Student*)arr;
	pstudent->num = student.num;
	memcpy(pstudent->name,student.name,NAME_SIZE);
	pstudent->sex = student.sex;
	pstudent->age = student.age;
	pstudent->score = student.score;
	memcpy(pstudent->addr,student.addr,sizeof(student.addr));
	memcpy(pstudent->tel,student.tel,sizeof(student.tel));
}

void arrayToStudent(const char* arr,int arrSize,Student* student)
{
	if(arr == NULL || arrSize < STUDENT_SIZE || student == NULL)
	{
		puts("arr or student is null,or arrSize less than student size");
		return ;
	}
	
	const Student* pstudent = (Student*)arr;
	student->num = pstudent->num;
	memcpy(student->name,pstudent->name,NAME_SIZE);
	student->sex = pstudent->sex;
	student->age = pstudent->age;
	student->score = pstudent->score;
	memcpy(student->addr,pstudent->addr,sizeof(pstudent->addr));
	memcpy(student->tel,pstudent->tel,sizeof(pstudent->tel));
}
#endif

void structToArray(void* arr,const void* pstruct,int size)
{
	if(arr == NULL || pstruct == NULL || size <= 0)
	{
		fprintf(stdout,"arr or pstruct is null,or size is less than zero\n");
		return ;
	}
	
	char* p = (char*)arr;
	const char* q = (const char*)pstruct;
	while(size--)
	{
		*p++ = *q++;
	}
}

void arrayToStruct(void* pstruct,const void* arr,int size)
{
	assert(pstruct != NULL);
	assert(arr != NULL);
	assert(size > 0);
	
	char* p = (char*)pstruct;
	const char* q = (const char*)arr;
	for(int i=0;i<size;++i)
	{
		*p++ = *q++;
	}
}