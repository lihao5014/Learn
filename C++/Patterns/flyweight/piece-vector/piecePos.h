#ifndef _PIECE_POS_H
#define _PIECE_POS_H

#include <iostream>

enum Color_t{BLACK,WHITE};

struct PiecePos
{
	PiecePos(int x,int y);
	PiecePos(const PiecePos& pos);
	
	void setX(const int x);
	int getX()const;
	void setY(const int y);
	int getY()const;
	void setXY(const int x,const int y);
	bool operator ==(const PiecePos& pos);
	int x;
	int y;
};

PiecePos::PiecePos(int x,int y)
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

bool PiecePos::operator ==(const PiecePos& pos)
{
	return x == pos.x && y == pos.y;
}

void display(const PiecePos& pos)
{
	std::cout<<"("<<pos.x<<","<<pos.y<<")"<<std::endl;
}

#endif //_PIECE_POS_H