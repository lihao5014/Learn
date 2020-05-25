#include "pieceBoard.h"

int main()
{
	PieceBoard board("amy","lisa");
	PiecePos pos(5,6);
	
	board.setPiece(BLACK,1,2);
	board.setPiece(WHITE,3,4);
	board.setPiece(BLACK,pos);
	pos.setXY(7,8);
	board.setPiece(WHITE,pos);
	
	board.show();
	
	return 0;
}