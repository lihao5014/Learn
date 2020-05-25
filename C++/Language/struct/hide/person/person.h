#ifndef _PERSON_H
#define _PERSON_H

struct Person;
typedef struct Person Person;

Person* createPerson(const char* name,int age);
void destroyPerson(Person** ppperson);

void setName(Person* pperson,const char* name);
const char* getName(const Person* pperson);

void setAge(Person* pperson,int age);
int getAge(const Person* pperson);

void showPerson(const Person* pperson);

#endif //_PERSON_H