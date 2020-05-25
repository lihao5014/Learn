#ifndef _PIECE_POS_H
#define _PIECE_POS_H

#include <iostream>

enum Color_t{BLACK,WHITE};

class PiecePos
{
public:
	PiecePos(const int x,const int y);
	PiecePos(const PiecePos& pos);
	
	void setX(const int x);
	int getX()const;
	void setY(const int y);
	int getY()const;
	void setXY(const int x,const int y);
	void display()const;
	bool operator ==(const PiecePos& pos)const;    //std::map中必须支持关系运算符
	
	bool operator <(const PiecePos& pos)const;
	bool operator >(const PiecePos& pos)const;
	friend std::ostream& operator <<(std::ostream& os,const PiecePos& pos);
private:
	int x;
	int y;
};

PiecePos::PiecePos(const int x,const int y)
{
	this->x = x;
	this->y = y;
}

PiecePos::PiecePos(const PiecePos& pos)
{
	x = pos.x;
	y = pos.y;
}

void PiecePos::setX(const int x)
{
	this->x = x;
}

int PiecePos::getX()const
{
	return x;
}

void PiecePos::setY(const int y)
{
	this->y = y;
}
int PiecePos::getY()const
{
	return y;
}

void PiecePos::setXY(const int x,const int y)
{
	this->x = x;
	this->y = y;	
}

void PiecePos::display()const
{
	std::cout<<"("<<x<<","<<y<<")"<<std::endl;
}

bool PiecePos::operator ==(const PiecePos& pos)const
{
	return (x == pos.x && y == pos.y) ? true : false;
}

bool PiecePos::operator <(const PiecePos& pos)const
{
	if(x < pos.x){
		return true;
	}else if(x == pos.x){
		return y < pos.y;
	}
	
	return false;
}

bool PiecePos::operator >(const PiecePos& pos)const
{
	if(x > pos.x){
		return true;
	}else if(x == pos.x){
		return y > pos.y;
	}
	
	return false;	
}

std::ostream& operator <<(std::ostream& os,const PiecePos& pos)
{
	os<<"("<<pos.x<<","<<pos.y<<")";
	return os;
}

#endif //_PIECE_POS_H