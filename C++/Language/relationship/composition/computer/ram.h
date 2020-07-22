#ifndef _RAM_H
#define _RAM_H

#include <iostream>

class Ram
{
public:
	Ram(int capacity);
	Ram(const Ram& other);
	
	void setCapacity(const int capacity);
	int getCapacity()const;
	
	void print()const;
private:
	int capacity;
};

Ram::Ram(int capacity)
	:capacity(capacity)
{
	
}

Ram::Ram(const Ram& other)
	:capacity(other.capacity)
{
	
}

void Ram::setCapacity(const int capacity)
{
	this->capacity = capacity;
}

int Ram::getCapacity()const
{
	return capacity;
}

void Ram::print()const
{
	std::cout<<"ram capacity is: "<<capacity<<"G"<<std::endl;
}
	
#endif //_RAM_H