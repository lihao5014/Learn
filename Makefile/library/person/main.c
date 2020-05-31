#include "person.h"

int main(void)
{
	Person* pperson = createPerson("Tom",25);
	showPerson(pperson);
	
	destroyPerson(&pperson);
	return 0;
}