#include "geese.h"
#include <iostream>

using namespace std;

Geese::Geese(const string departure,const string& destination)
	:departure(departure)
	,destination(destination)
{
	
}

void Geese::addGoose(const Goose& goose)
{
	members.push_back(goose);
}

void Geese::removeGoose(const Goose& goose)
{
	members.remove(goose);
}

void Geese::display()const
{
	list<Goose>::const_iterator citer = members.cbegin();
	for(;citer != members.cend();++citer)
	{
		cout<<"goose: "<<citer->getNumber()<<" fly from "<<departure<<" to "<<destination<<endl;
		citer->show();
	}
}