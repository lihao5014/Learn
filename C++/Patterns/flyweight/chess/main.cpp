#include "pieceFactory.h"
#include "chessBoard.h"

int main()
{
	PieceFactory* factory = new PieceFactory();
	Chessboard* chessboard = new Chessboard();
	
	Piece* black_piece = factory->getPiece(BLACK);
	black_piece->setPoint(4,5);
	chessboard->draw(black_piece);
	
	Piece* white_piece = factory->getPiece(WHITE);
	white_piece->setPoint(7,8);	
	chessboard->draw(white_piece);
	
	black_piece = factory->getPiece(BLACK);
	black_piece->setPoint(10,12);
	chessboard->draw(black_piece);
	
	white_piece = factory->getPiece(WHITE);
	white_piece->setPoint(15,16);	
	chessboard->draw(white_piece);
	
	factory->show();
	chessboard->show();
	
	return 0;
}