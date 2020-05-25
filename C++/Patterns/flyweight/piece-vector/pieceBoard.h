#ifndef _PIECE_BOARD_H
#define _PIECE_BOARD_H

#include "piece.h"
#include <string>
#include <vector>

class PieceBoard
{
public:
	PieceBoard(std::string blackUser,std::string whiteUser);
	void setPiece(Color_t color,const PiecePos& pos);
	void setPiece(Color_t color,const int x,const int y);
	void showPos();
private:
	std::string blackUser;
	std::string whiteUser;
	BlackPiece blackPiece;
	WhitePiece whitePiece;
	std::vector<PiecePos> posVecter;
};

PieceBoard::PieceBoard(std::string blackUser,std::string whiteUser)
	:blackUser(blackUser),whiteUser(whiteUser),blackPiece(0,0),whitePiece(0,0)
{
	
}

void PieceBoard::setPiece(Color_t color,const PiecePos& pos)
{
	if(color == BLACK){
		blackPiece.setPos(pos);
		std::cout<<blackUser<<"---";
		blackPiece.draw();
	}else if(color == WHITE){
		whitePiece.setPos(pos);
		std::cout<<whiteUser<<"---";
		whitePiece.draw();
	}	
	
	std::vector<PiecePos>::iterator iter = posVecter.begin();
	if(iter != posVecter.end()){
		if(*iter == pos){
			return ;
		}
		++iter;
	}

	posVecter.push_back(pos);
}

void PieceBoard::setPiece(Color_t color,const int x,const int y)
{
	PiecePos pos(x,y);
	setPiece(color,pos);
}

void PieceBoard::showPos()
{
	for(auto pos:posVecter){
		display(pos);
	}
}

#endif //_PIECE_BOARD_H