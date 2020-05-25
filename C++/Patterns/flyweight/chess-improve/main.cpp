#include "pieceFactory.h"
#include "chessBoard.h"

int main()
{
	Chessboard* chessboard = new Chessboard();
	
	chessboard->draw(BLACK,4,5);
	chessboard->draw(WHITE,7,8);
	chessboard->draw(BLACK,10,12);
	chessboard->draw(WHITE,15,16);
		
	chessboard->show();
	
	return 0;
}