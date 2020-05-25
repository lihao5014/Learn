#ifndef _GAME_H
#define _GAME_H

#include <stdbool.h>

typedef void (*pFUN)();

typedef struct CallBack
{
	pFUN pinitialize;
	pFUN pstartPlay;
	pFUN pendPlay;
}CALLBACK;

bool register_game(CALLBACK callback);
void play();

#endif //_GAME_H