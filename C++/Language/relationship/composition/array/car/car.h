#ifndef _CAR_H
#define _CAR_H

#include "engine.h"
#include "wheel.h"
#include "door.h"
#include <array>

#define WHEEL_COUNT 4
#define DOOR_COUNT 4

using std::array;

class Car
{
public:
	Car(const char* brand,const string& color,data_t size);
	Car(const Engine& engine,const Door& door,const Wheel& wheel);
	Car(const Car& other);
	
	void detail()const;
private:
	Engine engine;
	array<Wheel,WHEEL_COUNT> wheels;
	array<Door,DOOR_COUNT> doors;
};

Car::Car(const char* brand,const string& color,data_t size)
	:engine(brand)
	,doors{color,color,color,color}
	,wheels{size,size,size,size}
{
	
}

Car::Car(const Engine& engine,const Door& door,const Wheel& wheel)
	:engine(engine)
	,doors{door,door,door,door}
	,wheels{wheel,wheel,wheel,wheel}
{
	
}

Car::Car(const Car& other)
	:engine(other.engine)
	,doors(other.doors)
	,wheels(other.wheels)
{
	
}

void Car::detail()const
{
	engine.show();
	
	for(int i=0;i<WHEEL_COUNT;++i)
	{
		wheels[i].print();
	}
	
	for(int j=0;j<DOOR_COUNT;++j)
	{
		doors[j].display();
	}
}

#endif  //_CAR_H