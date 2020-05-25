#ifndef _DERECTION_H
#define _DERECTION_H

#include <stdio.h>

#define DEBUG
#undef DEBUG

#if (defined DEBUG) || (!defined CANCEL)
#define TRACK(expr)   \
	printf("[%s: %s %d] %s = %d\n",__FILE__,__func__,__LINE__,#expr,(expr))
#else
#define TRACK(expr)
#endif

typedef enum BOOL
{
	FALSE = 0,
	TRUE = 1
}BOOL;

#if 1
typedef enum Direction_t
{
	NONE = 0,                            //0 = 0B0000
	UP = 1,                              //1 = 0B0001
	DOWN = UP * 2,                       //2 = 0B0010
	LEFT = DOWN * 2,                     //4 = 0B0100
	RIGHT = LEFT * 2,                    //8 = 0B1000
	
	TOP_LEFT = UP | LEFT,                //0B0101 = 5   
	TOP_RIGHT = UP | RIGHT,              //0B1001 = 9
	BOTTOM_LEFT = DOWN | LEFT,           //0B0110 = 6
	BOTTOM_RIGHT = DOWN | RIGHT          //0B1010 = 10
}Direction;
#else
typedef enum Direction_t
{
	NONE = 0,                            //0 = 0B0000
	UP = 1<<0                            //1 = 0B0001
	DOWN = 1<<1,                         //2 = 0B0010
	LEFT = 1<<2,                         //4 = 0B0100
	RIGHT = 1<<4,                        //8 = 0B1000
	
	TOP_LEFT = UP | LEFT,                //0B0101 = 5   
	TOP_RIGHT = UP | RIGHT,              //0B1001 = 9
	BOTTOM_LEFT = DOWN | LEFT,           //0B0110 = 6
	BOTTOM_RIGHT = DOWN | RIGHT          //0B1010 = 10
}Direction;	
#endif

BOOL isDirection(Direction dir,Direction dstDir)
{
	return (dir & dstDir) == dir;
}

void showDirection(Direction dir)
{
	if(dir & UP)
	{
		printf("top: %d\n",(dir & UP) != 0);
	}
	
	if((dir & DOWN) > 0)
	{
		printf("down: %d\n",(dir & DOWN) > 0);
	}
	
	if((dir & LEFT) == LEFT)
	{
		fprintf(stdout,"left: %d\n",(dir & LEFT) == LEFT);
	}
	
	if((dir & RIGHT) == RIGHT)
	{
		fprintf(stdout,"right: %d\n",(dir & RIGHT) == RIGHT);
	}
	puts("");
}

#endif //_DERECTION_H