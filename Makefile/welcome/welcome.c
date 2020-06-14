#include "welcome.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define _CHANGE_WAY_
// #undef _CHANGE_WAY_

#define TOP_SIDE "********************"
#define MID_SIDE "*                  *"

#define WIDTH 20
#define HEIGHT 7

#ifndef _CHANGE_WAY_
void showWelcome()
{
	system("cls");
	puts("********************");
	puts("*                  *");
	puts("*                  *");
	puts("*   Hello World    *");
	puts("*                  *");
	puts("*                  *");
	puts("********************");
	putc('\n',stdout);
	system("pause");
}
#else
void showWelcome()
{
	system("cls");
	printf("%s\n",TOP_SIDE);
	printf("%s\n",MID_SIDE);
	printf("%s\n",MID_SIDE);
	printf("*   Hello World    *\n",MID_SIDE);
	printf("%s\n",MID_SIDE);
	printf("%s\n",MID_SIDE);
	printf("%s\n",TOP_SIDE);
	puts("");
	system("pause");
}
#endif

void drawWelcome()
{
	char frameBuffer[HEIGHT][WIDTH] = {0};            //创建一个绘图区
	for(int i=0;i<HEIGHT;++i)                         //绘制矩形边框
	{
		for(int j=0;j<WIDTH;++j)
		{
			if(i == 0 || i == (HEIGHT - 1) || j == 0 || j == (WIDTH - 1))
			{
				frameBuffer[i][j] = '*';
				continue;
			}
			frameBuffer[i][j] = ' ';
		}
	}
	memcpy(frameBuffer[HEIGHT/2],"*   Hello World    *",WIDTH);     //绘制Hello World文本
	
	system("cls");
	for(int i=0;i<HEIGHT;++i)                         //打印窗口
	{
		for(int j=0;j<WIDTH;++j)
		{
			printf("%c",frameBuffer[i][j]);
		}
		putc('\n',stdout);
	}
	putchar('\n');
	system("pause");
}