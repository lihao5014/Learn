#include "direction.h"

int main()
{
#if 1
	Direction dir1 = TOP_LEFT;
#else
	Direction dir1 = UP|LEFT;
#endif
	
	isDirection(dir1,UP);
	showDirection(dir1);
	
	dir1 = dir1 | RIGHT;    // | 运算的打开标志功能
	dir1 = dir1 ^ LEFT;     
	dir1 |= DOWN;
	dir1 &= ~UP;            // & 运算的关闭标志位功能
	
	printf("dir1 contains left: %d\n",isDirection(dir1,LEFT));
	showDirection(dir1);
	
	dir1 = dir1 ^ LEFT;     // ^ 运算的切换标志位功能
	showDirection(dir1);
	
	return 0;
}