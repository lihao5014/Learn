#ifndef _GEESE_H
#define _GEESE_H

#include <list>
#include <string>
#include "goose.h"

class Geese
{
public:
	Geese(const std::string departure,const std::string& destination);
	
	void addGoose(const Goose& goose);
	void removeGoose(const Goose& goose);
	
	void display()const;
private:
	Geese(const Goose& other);
	Goose operator =(const Goose& other);
	
	std::string departure;
	std::string destination;
	std::list<Goose> members;     //能存储在list容器中的类必须重载等号==运算符
};

#endif //_GEESE_H