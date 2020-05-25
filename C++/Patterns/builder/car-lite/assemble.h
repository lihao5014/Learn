#ifndef _ASSEMBLE_H
#define _ASSEMBLE_H

#include "car.h"

class Assemble
{
public:
	virtual ~Assemble(){}
	
	void assembleCar()
	{
		assembleEngine();
		assembleWheel();
		assembleBody();
	}
	
	virtual Car* getCar()
	{
		return car;
	}	
	
	virtual void assembleEngine() = 0;
	virtual void assembleWheel() = 0;
	virtual void assembleBody() = 0;
protected:
	Car* car;
};

class AssembleCarA:public Assemble
{
public:
	AssembleCarA()
	{
		car = new Car();
	}
	
	virtual void assembleEngine()
	{
		if(car != nullptr)
			car->setEngine("EngineA");
	}
	
	void assembleWheel()override
	{
		if(car != nullptr)
			car->setWheel("WheelA");
	}
	
	void assembleBody()final
	{
		if(car != nullptr)
			car->setBody("BodyA");
	}
	
	Car* getCar()
	{
		return car;
	}	
private:
	Car* car;
};

class AssembleCarB:public Assemble
{
public:
	AssembleCarB()
	{
		car = new Car();
	}
	
	virtual void assembleEngine()
	{
		if(car != nullptr)
			car->setEngine("EngineB");
	}
	
	void assembleWheel()override
	{
		if(car != nullptr)
			car->setWheel("WheelB");
	}
	
	void assembleBody()final
	{
		if(car != nullptr)
			car->setBody("BodyB");
	}
	
	Car* getCar()
	{
		return car;
	}	
private:
	Car* car;
};


#endif //_ASSEMBLE_H