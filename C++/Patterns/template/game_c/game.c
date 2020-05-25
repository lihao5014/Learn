#include "game.h"
#include <stdio.h>

static CALLBACK callBack = {NULL};

static void welcome();
static void initialize();
static void startPlay();
static void endPlay();

bool register_game(CALLBACK callback)
{
	if(callback.pinitialize==NULL 
		|| callback.pstartPlay==NULL
		|| callback.pendPlay==NULL){
		return false;
	}
	callBack.pinitialize = callback.pinitialize;
	callBack.pstartPlay = callback.pstartPlay;
	callBack.pendPlay = callback.pendPlay;
}

void play()
{
	if(callBack.pinitialize==NULL 
		|| callBack.pstartPlay==NULL
		|| callBack.pendPlay==NULL){
		return ;
	}
	welcome();
	callBack.pinitialize();
	callBack.pstartPlay();
	callBack.pendPlay();
}

void welcome()
{
	printf("welcome playing the game!\n");
}

void initialize()
{
	if(callBack.pinitialize == NULL) return ;
	
	callBack.pinitialize();
}

void startPlay()
{
	if(callBack.pstartPlay == NULL) return ;
	
	callBack.pstartPlay();
}

void endPlay()
{
	if(callBack.pendPlay == NULL) return ;
	
	callBack.pendPlay();
}