#ifndef _PERSON_BUILDER_H
#define _PERSON_BUILDER_H

#include "person.h"

class PersonBuilder
{
public:
	virtual ~PersonBuilder(){}
	Person* getPerson(){return person;}
	
	virtual void buildHead() = 0;
	virtual void buildBody() = 0;
	virtual void buildFoot() = 0;
	virtual void buildHand() = 0;
protected:
	Person* person;
};

class FatPersonBuilder:public PersonBuilder
{
public:
	FatPersonBuilder()
	{
		person = new Person();
	}
	
	void buildHead()
	{
		if(person != nullptr)
			person->setHead("fat head");
	}
	
	virtual void buildBody()
	{
		if(person != nullptr)
			person->setBody("fat body");		
	}
	
	void buildFoot()override
	{
		if(person != nullptr)
			person->setFoot("fat foot");		
	}
	
	void buildHand()final
	{
		if(person != nullptr)
			person->setHand("fat hand");		
	}	
};

class ThinPersonBuilder:public PersonBuilder
{
public:
	ThinPersonBuilder()
	{
		person = new Person();
	}
	
	void buildHead()
	{
		if(person != nullptr)
			person->setHead("thin head");
	}
	
	virtual void buildBody()
	{
		if(person != nullptr)
			person->setBody("thin body");		
	}
	
	void buildFoot()override
	{
		if(person != nullptr)
			person->setFoot("thin foot");		
	}
	
	void buildHand()final
	{
		if(person != nullptr)
			person->setHand("thin hand");		
	}	
};

class NormalPersonBuilder:public PersonBuilder
{
public:
	NormalPersonBuilder()
	{
		person = new Person();
	}
	
	void buildHead()
	{
		if(person != nullptr)
			person->setHead("normal head");
	}
	
	virtual void buildBody()
	{
		if(person != nullptr)
			person->setBody("normal body");		
	}
	
	void buildFoot()override
	{
		if(person != nullptr)
			person->setFoot("normal foot");		
	}
	
	void buildHand()final
	{
		if(person != nullptr)
			person->setHand("normal hand");		
	}	
};

#endif //_PERSON_BUILDER_H