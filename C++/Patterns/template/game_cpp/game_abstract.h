#ifndef _GAME_ABSTRACT_H
#define _GAME_ABSTRACT_H

#include <iostream>

class Game
{
public:
	virtual ~Game(){}
	void play()
	{
		welcome();
		initialize();
		startPlay();
		endPlay();
	}
protected:
	virtual void welcome()
	{
		std::cout<<"welcome playing the game!"<<std::endl;
	}
	virtual void initialize() = 0;
	virtual void startPlay() = 0;
	virtual void endPlay() = 0;
};

#endif //_GAME_ABSTRACT_H