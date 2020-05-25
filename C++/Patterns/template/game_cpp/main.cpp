#include "game_concrete.h"

int main()
{
	Game *game1 = new Basketball();
	game1->play();
	if(game1 != NULL){
		delete game1;
		game1 = NULL;
	}
	
	Game *game2 = new Football();
	game2->play();
	if(game2 != NULL){
		delete game2;
		game2 = NULL;
	}
}