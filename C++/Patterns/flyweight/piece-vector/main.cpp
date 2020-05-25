#include "pieceBoard.h"

int main()
{
	PieceBoard board("amy","lisa");
	PiecePos pos(1,2);
	
	board.setPiece(BLACK,pos);
	pos.setXY(3,4);
	board.setPiece(WHITE,pos);

	board.setPiece(BLACK,5,6);
	board.setPiece(WHITE,7,8);
	
	board.showPos();
	
	return 0;
}