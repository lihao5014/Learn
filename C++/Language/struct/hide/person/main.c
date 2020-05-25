#include "person.h"
#include <stdio.h>

int main(void)
{
	Person* pperson = createPerson("amy",24);
	showPerson(pperson);
	
	setName(pperson,"kevin");
	setAge(pperson,32);
	showPerson(pperson);
	
	puts("");
	printf("name =%s\n",getName(pperson));
	printf("age =%d\n",getAge(pperson));
	
	destroyPerson(&pperson);
	return 0;
}
