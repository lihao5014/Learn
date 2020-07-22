#ifndef _FAN_H
#define _FAN_H

#include <iostream>

class Fan
{
public:
	Fan(const int power);
	Fan(const Fan& other);
	
	void setPower(const int power);
	int getPower()const;
	
	void show()const;
private:
	int power; 
};

Fan::Fan(const int power)
	:power(power)
{
	
}

Fan::Fan(const Fan& other)
	:power(other.power)
{
	
}

void Fan::setPower(const int power)
{
	this->power = power;
}

int Fan::getPower()const
{
	return power;
}

void Fan::show()const
{
	std::cout<<"fan power is: "<<power<<"W"<<std::endl;
}

#endif //_FAN_H