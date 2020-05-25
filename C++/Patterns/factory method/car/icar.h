#ifndef _ICAR_H
#define _ICAR_H

#include <string>

class ICar
{
public:
	virtual ~ICar(){}
	virtual std::string getName()const = 0;
	virtual void show() = 0;
};


#endif //_CAR_H