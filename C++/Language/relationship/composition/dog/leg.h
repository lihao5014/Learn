#ifndef _LEG_H
#define _LEG_H

#include <iostream>

using namespace std;

class Leg
{
public:
	Leg(const int length);
	Leg(const Leg& other);
	
	void print()const;
private:
	int length;
};

Leg::Leg(const int length)
	:length(length)
{
	
}

Leg::Leg(const Leg& other)
	:length(other.length)
{

}

void Leg::print()const
{
	cout<<"Leg length ="<<length<<endl;
}

#endif //_LEG_H