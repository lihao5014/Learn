#ifndef _WHEEL_H
#define _WHEEL_H

#include <iostream>

typedef double data_t;

class Wheel
{
public:
	Wheel(const data_t size);
	Wheel(const Wheel& other);
	
	void print()const;
private:
	data_t size;
};

Wheel::Wheel(const data_t size =0)       //默认参数可以写在函数声明处，也可写在函数实现处，但不能两个地方都写。一般都写在声明处方便观看
	:size(size)
{
	
}

Wheel::Wheel(const Wheel& other)
	:size(other.size)
{
	
}

void Wheel::print()const
{
	std::cout<<"wheel size ="<<size<<std::endl;
}

#endif //_WHEEL_H