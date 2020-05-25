#ifndef _ASSEMBLE_H
#define _ASSEMBLE_H

#include "car.h"

class Assemble
{
public:
	virtual ~Assemble(){}
	virtual void assembleEngine() = 0;
	virtual void assembleWheel() = 0;
	virtual void assembleBody() = 0;
	virtual Car* getCar() = 0;
};

class AssembleCarA:public Assemble
{
public:
	AssembleCarA()
	{
		carA = new Car();
	}
	
	virtual void assembleEngine()
	{
		if(carA != nullptr)
			carA->setEngine("EngineA");
	}
	
	void assembleWheel()override
	{
		if(carA != nullptr)
			carA->setWheel("WheelA");
	}
	
	void assembleBody()final
	{
		if(carA != nullptr)		
			carA->setBody("BodyA");
	}
	
	Car* getCar()
	{
		return carA;
	}	
private:
	Car* carA;
};

class AssembleCarB:public Assemble
{
public:
	AssembleCarB()
	{
		carB = new Car();
	}
	
	virtual void assembleEngine()
	{
		if(carB != nullptr)	
			carB->setEngine("EngineB");
	}
	
	void assembleWheel()override
	{
		if(carB != nullptr)
			carB->setWheel("WheelB");
	}
	
	void assembleBody()final
	{
		if(carB != nullptr)
			carB->setBody("BodyB");
	}
	
	Car* getCar()
	{
		return carB;
	}	
private:
	Car* carB;
};


#endif //_ASSEMBLE_H