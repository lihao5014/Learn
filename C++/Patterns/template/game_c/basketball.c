#include "game.h"
#include <stdio.h>

static void initialize();
static void startPlay();
static void endPlay();

CALLBACK basketball = {
	initialize,
	startPlay,
	endPlay
};

static void initialize()
{
	printf("Basketball game initialized! start playing.\n");
}

static void startPlay()
{
	printf("Basketball game started! enjoy the game.\n");
}

static void endPlay()
{
	printf("Basketball game finished!\n");
}
