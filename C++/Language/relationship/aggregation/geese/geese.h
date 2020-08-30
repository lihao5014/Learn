#ifndef _GEESE_H
#define _GEESE_H

#include "goose.h"
#include <list>
#include <string>

using std::list;
using std::string;

class Geese
{
public:
	Geese(const string departure,const string& destination);
	
	void addGoose(const Goose& goose);
	void removeGoose(const Goose& goose);
	
	void display()const;
private:
	Geese(const Goose& other);
	Goose operator =(const Goose& other);
	
	string departure;
	string destination;
	list<Goose> members;     //能存储在list容器中的类必须重载等号==运算符
};

#endif //_GEESE_H