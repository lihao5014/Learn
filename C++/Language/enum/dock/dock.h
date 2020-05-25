#ifndef _DOCK_H
#define _DOCK_H

// #define _DEBUG_
// #undef _DEBUG_

#define _TRACK_
#undef _TRACK_

#if (defined _DEBUG_) || (defined _TRACK_)
#define DEBUG(expr)      \
	printf("%s =%d\n",#expr,(expr))

#define TRACK(expr)      \
	printf("[%s: %s %d] %s =%d\n",__FILE__,__func__,__LINE__,#expr,(expr))
#else
#define DEBUG(expr)
#define TRACK(expr)
#endif

#define FALSE 0
#define TRUE 1

typedef char BOOL;

#define isDockTop(dock) isDock(dock,TOP)
#define isDockBottom(dock) isDock(dock,BOTTOM)
#define isDockLeft(dock) isDock(dock,LEFT)
#define isDockRight(dock) isDock(dock,RIGHT)

//Dock枚举类型用于描述子窗口停靠在父窗口上的位置。二进制枚举的使用
#if 0
typedef enum
{
	TOP = 1,         //0B0001，TOP表示子窗口上边缘停靠父窗口上边缘，即子窗口与父窗口上边沿重合
	BOTTOM = 2,      //0B0010，BOTTOM表示子窗口下边缘停靠父窗口下边缘，即子窗口与父窗口下边沿重合
	LEFT = 4,        //0B0100，TOP表示子窗口左边缘停靠父窗口左边缘，即子窗口与父窗口左边沿重合
	RIGHT = 8        //0B1000，TOP表示子窗口右边缘停靠父窗口右边缘，即子窗口与父窗口右边沿重合
}Dock;
#elif 0
typedef enum Dock
{
	NONE = 0,        //
	TOP = 1,
	BOTTOM = TOP*2,
	LEFT = BOTTOM*2,
	RIGHT = LEFT*2
}Dock;
#elif 0
typedef enum Dock_t
{
	TOP = 1<<0,
	BOTTOM = 1<<1,
	LEFT = 1<<2,
	RIGHT = 1<<3,
	ALL = TOP|BOTTOM|LEFT|RIGHT
}Dock;
#else
typedef enum
{
	NONE = 0B0000,
	TOP = 0B0001,
	BOTTOM = 0B0010,
	LEFT = 0B0100,
	RIGHT = 0B1000,
	ALL = TOP|BOTTOM|LEFT|RIGHT
}Dock;
#endif

BOOL isDock(Dock dock,Dock dockTo)
{
	return (dock & dockTo) > 0;
}

void showDock(Dock dock)
{
	if(dock & TOP)             //当TOP枚举值不为0时，才可以使用dock&TOP进行判断。使用(dock&TOP) == TOP这不管默认值是否为0都成立
	{
		printf("is dock top: %d\n",(dock & TOP) != 0);
	}
	
	if((dock & BOTTOM) > 0)        //dock满足条件BOTTOM 
	{
		printf("is dock bottom: %d\n",(dock & BOTTOM) > 0);
	}
	
	if((dock & LEFT) == LEFT)     //dock包含条件BOTTOM 
	{
		printf("is dock left: %d\n",(dock & LEFT) == LEFT);
	}
	
	if((dock & RIGHT) == RIGHT)   //优先选用(dock & RIGHT) == RIGHT进行判断
	{
		printf("is dock right: %d\n",(dock & RIGHT) == RIGHT);
	}
	
	putc('\n',stdout);
}

#endif //_DOCK_H