#ifndef _DOOR_H
#define _DOOR_H

#include <iostream>
#include <string.h>

using namespace std;

class Door
{
public:
	Door(const string& color = "black");       //默认参数可以写在函数声明处，也可写在函数实现处，但不能两个地方都写。一般都写在声明处方便观看
	Door(const Door& other);
	
	void display()const;
private:
	string color;
};

Door::Door(const string& color)
	:color(color)
{
	
}

Door::Door(const Door& other)
	:color(other.color)
{
	
}

void Door::display()const
{
	cout<<"door color ="<<color<<endl;
}

#endif //_DOOR_H