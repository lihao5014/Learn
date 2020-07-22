#ifndef _LABEL_H
#define _LABEL_H

#include <iostream>

typedef int data_t;

//C语言中结构体也可以通过“=”赋值，其效果等同于C++中的浅拷贝。
typedef struct Position     //C和C++中结构体如果没有实现默认的拷贝构造函数的话，会默认生成一个浅拷贝构造函数。
{
	data_t x;
	data_t y;
}Pos_t;

class Label
{
public:
	explicit Label(const Pos_t& pos);   //只有一个参数的构造函数才会发生默认转换，多个参数的构造函数不会发生默认转换
	Label(data_t x,data_t y);           //只有一个参数的构造函数才需要加explicit，有多个参数的构造函数不需要加explicit
	Label(const Label& other);
	
	void setX(const data_t& x);
	data_t getX()const;
	
	void setY(const data_t& y);
	data_t getY()const;
	
	void setPos(const Pos_t& pos);
	Pos_t getPos()const;
	
	void display()const;
private:
	Pos_t pos;
};

Label::Label(const Pos_t& pos)
	:pos(pos)
{
	
}

Label::Label(data_t x,data_t y)
	:pos{x,y}
{
	
}
Label::Label(const Label& other)
	:pos(other.pos)
{
	
}

void Label::setX(const data_t& x)
{
	pos.x = x;
}

data_t Label::getX()const
{
	return pos.x;
}

void Label::setY(const data_t& y)
{
	pos.y = y;
}

data_t Label::getY()const
{
	return pos.y;
}

void Label::setPos(const Pos_t& pos)
{
	this->pos = pos;
}

Pos_t Label::getPos()const
{
	return pos;
}

void Label::display()const
{
	std::cout<<"("<<pos.x<<","<<pos.y<<")"<<std::endl;
}

#endif //_LABEL_H