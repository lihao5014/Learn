#ifndef _PIECE_H
#define _PIECE_H

#include "point.h"

enum Color_t{BLACK,WHITE};

class Piece
{
public:
	Piece(Color_t color):color(color){}
	Piece(Color_t color,Point point):color(color),point(point){}
	Piece(Color_t color,int x,int y):color(color){point.setX(x);point.setY(y);}
	Piece(const Piece& piece){color = piece.color;point = piece.point;}

	Piece clone()const{return Piece(*this);}
	Color_t getColor()const{return color;}
	void setPoint(const Point& point){this->point = point;}
	void setPoint(const int x,const int y){point.setX(x);point.setY(y);}
	Point getPoint()const{return point;}
	
	void display()const
	{
		std::cout<<"color ="<<color<<" , ";
		point.display();
	}
protected:
	Color_t color;
	Point point;
};

#endif //_PIECE_H