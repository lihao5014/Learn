#ifndef _PIECE_H
#define _PIECE_H

#include "piecePos.h"

class Piece
{
public:
	Piece(Color_t color,const PiecePos& pos):color(color),pos(pos){}
	Piece(const int x,const int y):pos(x,y){}
	Piece(Color_t color,const int x,const int y):color(color),pos(x,y){}
	virtual ~Piece(){}
	void setColor(const Color_t& color){this->color = color;}
	Color_t getColor()const{return color;}
	void setPos(const PiecePos& pos){this->pos = pos;}
	void setPos(const int x,const int y){pos.setX(x);pos.setY(y);}
	PiecePos getPos()const{return pos;}
	virtual void draw() = 0;
protected:
	Color_t color;
	PiecePos pos;
};

class BlackPiece:public Piece
{
public:
	BlackPiece():Piece(BLACK,0,0){}
	BlackPiece(const PiecePos& pos):Piece(BLACK,pos){}
	BlackPiece(const int x,const int y):Piece(x,y){color = BLACK;}
	virtual void draw()override
	{
		std::cout<<"black piece :color ="<<color<<" ,("<<pos.getX()
			<<","<<pos.getY()<<")"<<std::endl;
	}
};

class WhitePiece:public Piece
{
public:
	WhitePiece():Piece(WHITE,0,0){}
	WhitePiece(const PiecePos& pos):Piece(WHITE,pos){}
	WhitePiece(const int x,const int y):Piece(x,y){color = WHITE;}
	virtual void draw()final
	{
		std::cout<<"white piece :color ="<<color<<" ,("<<pos.getX()
			<<","<<pos.getY()<<")"<<std::endl;
	}
};

#endif //_PIECE_H