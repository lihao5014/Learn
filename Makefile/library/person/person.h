#ifndef _PERSON_H
#define _PERSON_H

struct Person;
typedef struct Person Person;

extern Person* createPerson(const char* name,int age);
extern void destroyPerson(Person** ppperson);

extern void setName(Person *pthis,const char* name);
extern const char* getName(const Person *pthis);

extern void setAge(Person *pthis,const int age);
extern int getAge(const Person *pthis);

extern void showPerson(const Person* pthis);

#endif //_PERSON_H
