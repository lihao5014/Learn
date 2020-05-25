#ifndef _PIECE_FACTORY_H
#define _PIECE_FACTORY_H

#include "piece.h"
#include <vector>

class PieceFactory
{
public:
	~PieceFactory();
	static Piece* getPiece(Color_t color);
	static void show();
private:
	static std::vector<Piece*> pieceVector;
};

std::vector<Piece*> PieceFactory::pieceVector;

PieceFactory::~PieceFactory()
{
	std::vector<Piece*>::iterator iter = pieceVector.begin();
	while(iter != pieceVector.end()){
		if((*iter) != nullptr){
			delete *iter;
			*iter = nullptr;
		}
		++iter;
	}
	
	pieceVector.erase(pieceVector.begin(),pieceVector.end());
}

Piece* PieceFactory::getPiece(Color_t color)
{
	std::vector<Piece*>::iterator iter = pieceVector.begin();
	while(iter != pieceVector.end()){
		if((*iter)->getColor() == color){
			return *iter;
		}
		++iter;
	}
	
	Piece* piece = new Piece(color);
	pieceVector.push_back(piece);
	return piece;	
}

void PieceFactory::show()
{
	std::vector<Piece*>::iterator iter = pieceVector.begin();
	while(iter != pieceVector.end()){
		(*iter)->display();
		++iter;
	}	
}

#endif //_PIECE_FACTORY_H