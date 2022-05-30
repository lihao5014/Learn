#include "inc.h"
#include "test.h"

void test_person()
{
	Person* personPtr = createPerson("lisa");	
	setPersonAge(personPtr,25);
	setPersonSex(personPtr,GIRL);
	showPerson(personPtr);
	putc('\n',stdout);
	
	setPersonName(personPtr,"jorden");
	printf("name: %s\n",getPersonName(personPtr));
	printf("age: %d\n",getPersonAge(personPtr));
	
	const char* strSex = (getPersonSex(personPtr) == BOY) ? "boy" : "girl";
	printf("Sex: %s\n",strSex);
	puts("\n");
	
	destroyPerson(&personPtr);
}