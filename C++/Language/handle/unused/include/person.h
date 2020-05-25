#ifndef _PERSON_H
#define _PERSON_H

struct HPerson__
{
	int unused;
};

typedef void* handle_t;                              //通用句柄
typedef struct HPerson__* HPerson;                   //Person结构体专用句柄,用于标记Person对象

HPerson createPerson(const char name[]);
void destroyPerson(HPerson* hperson);

void setName(HPerson hperson,const char* name);
const char* getName(const HPerson hperson);           //在调用getName前，不能调用destroyPerson函数

void setAge(HPerson hperson,const int age);
int getAge(const HPerson hperson);

void showPerson(const HPerson hperson);

#endif //_PERSON_H