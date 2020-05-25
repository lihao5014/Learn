#ifndef _GAME_CONCRETE_H
#define _GAME_CONCRETE_H

#include "game_abstract.h"

class Basketball:public Game
{
protected:
	void initialize()
	{
		std::cout<<"Basketball game initialized! start playing."<<std::endl;
	}
	
	void startPlay()
	{
		std::cout<<"Basketball game started! enjoy the game."<<std::endl;
	}
	
	void endPlay()
	{
		std::cout<<"Basketball game finished!"<<std::endl;
	}
};

class Football:public Game
{
public:
	virtual void initialize()
	{
		std::cout<<"Football game initialized! start playing."<<std::endl;
	}
	
	virtual void startPlay()
	{
		std::cout<<"Football game started! enjoy the game."<<std::endl;
	}
	
	virtual void endPlay()
	{
		std::cout<<"Football game finished!"<<std::endl;
	}
	
};

#endif //_GAME_CONCRETE_H