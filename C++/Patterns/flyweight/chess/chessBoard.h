#ifndef _CHESS_BOARD_H
#define _CHESS_BOARD_H

#include "pieceFactory.h"
#include <map>

class Chessboard
{
public:
	~Chessboard();
	void draw(Piece* piece);
	void show();
private:
	std::map<Point,Piece*> pieceMap;
};

Chessboard::~Chessboard()
{
	pieceMap.erase(pieceMap.begin(),pieceMap.end());
}

void Chessboard::draw(Piece* piece)
{
	if(piece == nullptr) return ;
	
	if(piece->getColor() == BLACK){
		std::cout<<"draw black piece : ";
		piece->display();
	}else{
		std::cout<<"draw white piece : ";
		piece->display();
	}
	
	pieceMap.insert(std::pair<Point,Piece*>(piece->getPoint(),piece));
}

void Chessboard::show()
{
	std::map<Point,Piece*>::iterator iter = pieceMap.begin();
	while(iter != pieceMap.end()){
		iter->first.display();
		++iter;
	}
}

#endif //_CHESS_BOARD_H