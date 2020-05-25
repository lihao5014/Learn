#include "director.h"

int main()
{
	PersonBuilder* builder = new FatPersonBuilder();
	Director director(builder);
	director.createPerson();
	Person* person = director.getPerson();
	person->show();
	delete person;
	delete builder;
	
	builder = new ThinPersonBuilder();
	director.setBuilder(builder);
	director.createPerson();
	person = director.getPerson();
	person->show();
	delete person;
	delete builder;		
	
	return 0;
}