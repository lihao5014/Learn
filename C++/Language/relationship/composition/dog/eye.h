#ifndef _EYE_H
#define _EYE_H

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class Eye
{
public:
	Eye(const string& color);
	Eye(const Eye& other);
	
	void show()const;
private:
	string color;
};

Eye::Eye(const string& color)
	:color(color)
{
	
}

Eye::Eye(const Eye& other)
	:color(other.color)
{
	
}

void Eye::show()const
{
	cout<<"eye color ="<<color<<endl;
}

#endif //_EYE_H