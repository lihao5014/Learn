#ifndef _PIECE_BOARD_H
#define _PIECE_BOARD_H

#include "piece.h"
#include <string>
#include <map>

class PieceBoard
{
public:
	PieceBoard(std::string blackUser,std::string whiteUser);
	void setPiece(Color_t color,const PiecePos& pos);
	void setPiece(Color_t color,const int x,const int y);
	void show();
private:
	std::string blackUser;
	std::string whiteUser;
	BlackPiece blackPiece;
	WhitePiece whitePiece;
	std::map<PiecePos,Color_t> pieceMap;
};

PieceBoard::PieceBoard(std::string blackUser,std::string whiteUser)
	:blackUser(blackUser),whiteUser(whiteUser),blackPiece()
{
	
}

void PieceBoard::setPiece(Color_t color,const PiecePos& pos)
{
	std::map<PiecePos,Color_t>::iterator iter = pieceMap.find(pos);
	if(iter != pieceMap.end()){
		if((iter->second = color) == BLACK){
			blackPiece.setPos(pos);
			blackPiece.draw();
		}else if((iter->second = color) == WHITE){
			whitePiece.setPos(pos);
			whitePiece.draw();
		}
		return ;
	}
	
	if(color == BLACK){
		blackPiece.setPos(pos);
		blackPiece.draw();		
	}else if(color == WHITE){
		whitePiece.setPos(pos);
		whitePiece.draw();		
	}
	pieceMap.insert(std::pair<PiecePos,Color_t>(pos,color));
}

void PieceBoard::setPiece(Color_t color,const int x,const int y)
{
	PiecePos pos(x,y);
	setPiece(color,pos);
}

void PieceBoard::show()
{
	std::cout<<"----"<<blackUser<<"----"<<std::endl;
	std::map<PiecePos,Color_t>::iterator iter = pieceMap.begin();
	while(iter != pieceMap.end()){
		if(iter->second == BLACK){
			std::cout<<iter->second<<" , "<<iter->first<<std::endl;
		}
		++iter;
	}
	
	std::cout<<"----"<<whiteUser<<"----"<<std::endl;
	iter = pieceMap.begin();
	while(iter != pieceMap.end()){
		if(iter->second == WHITE){
			std::cout<<iter->second<<" , "<<iter->first<<std::endl;
		}
		++iter;
	}	
}

#endif //_PIECE_BOARD_H