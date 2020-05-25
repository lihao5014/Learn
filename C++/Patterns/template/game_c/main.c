#include "game.h"

extern CALLBACK basketball;
extern CALLBACK football;

int main()
{
	register_game(basketball);
	play();
	
	register_game(football);
	play();
}