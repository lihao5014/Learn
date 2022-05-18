#ifndef _PERSON_H_
#define _PERSON_H_

#ifdef __cplusplus
#pragma message("C++ language")
extern "C" {
#endif

typedef enum Sex_t
{
	UNKNOWN = 0,
	BOY,
	GIRL
}Sex;

typedef struct Person_t
{
	void* m_placeholder;
}Person;

Person* createPerson(const char name[]);
void destroyPerson(Person** ppersonPtr);

void setPersonName(Person* personPtr,const char* pname);
const char* getPersonName(const Person* personPtr);

void setPersonAge(Person* personPtr,int age);
int getPersonAge(const Person* personPtr);

void setPersonSex(Person* personPtr,Sex sex);
Sex getPersonSex(const Person* personPtr);

void showPerson(const Person* personPtr);

#ifdef __cplusplus
}
#endif

#endif  //_PERSON_H_