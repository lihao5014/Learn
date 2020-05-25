#include "game.h"
#include <stdio.h>

static void initialize();
static void startPlay();
static void endPlay();

CALLBACK football = {
	initialize,
	startPlay,
	endPlay
};

static void initialize()
{
	printf("Football game initialized! start playing.\n");
}

static void startPlay()
{
	printf("Football game started! enjoy the game.\n");
}

static void endPlay()
{
	printf("Football game finished!\n");
}