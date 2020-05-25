#include <stdio.h>

#define _DEBUG_
// #undef _DEBUG_
#include "dock.h"

#define _IS_CPP_
// #undef _IS_CPP_

#define _USE_ENUM_
// #undef _USE_ENUM_

int main(int argc,char* argv[])
{
#ifdef _IS_CPP_
	Dock dock1 = (Dock)10;             //C++语言中不能对枚举型变量直接赋整数值或枚举值得组合，必须进行强制类型转换
	Dock dock2 = Dock(TOP | LEFT);
#else
	Dock dock1 = 10;                   //C语言中可以对枚举型变量直接赋整数值或枚举值得组合
	Dock dock2 = TOP | LEFT;
#endif
	DEBUG(dock1);
	TRACK(dock2);

#ifndef _USE_ENUM_
	BOOL isTop = TRUE;                //直接使用bool型变量表示父子窗口之间的方位时，需要定义4个布尔型变量。
	BOOL isBottom = FALSE;
	BOOL isLeft = TRUE;
	BOOL isRIGHT = FALSE;
	
	printf("is dock top: %d\n",isTop);
	printf("is dock bottom: %d\n",isBottom);
	printf("is dock right: %d\n",isRIGHT);
	printf("is dock left: %d\n",isLeft);
#else
	char dock3 = TOP|LEFT;             //使用二进制枚举可以减少bool类型变量定义

	printf("is dock top: %d\n",isDockTop((Dock)dock3));
	printf("is dock bottom: %d\n",isDockBottom((Dock)dock3));
	printf("is dock left: %d\n",isDockLeft(static_cast<Dock>(dock3)));
	printf("is dock right: %d\n\n",isDockRight(static_cast<Dock>(dock3)));
	
	fputs("test add and delete1\n",stdout);
	char dock4 = Dock(TOP | BOTTOM | LEFT);   //因为TOP|LEFT类型不在Dock枚举类型范围内，所以定义一个char类型变量。
	showDock(Dock(dock4));
	
	dock4 |= RIGHT;     //添加一个枚举值RIGHT，即添加一个条件
	showDock((Dock)dock4);
	
	dock4 ^= BOTTOM;    //移除一个枚举值BOTTOM，即移除一个选项。异或操作相同为0，相异异为1
	showDock((Dock)dock4);
	
	dock4 &= ~LEFT;     //删除一个枚举值LEFT，即删除一个权限
	showDock((Dock)dock4);
	
	puts("test add and delete2");
	int dock5 = (Dock)((BOTTOM | LEFT | RIGHT) ^ BOTTOM);      //定义为int是为了避免，使用过程中增加或者删除项时产生的中间值不在枚举值中
	showDock(Dock(dock5));
	
	dock5 = dock5 ^ BOTTOM;      //异或操作两又会把值添加回来
	dock5 = dock5 & (~LEFT);     //连续操作多少次都不会不值重新设置回来
	dock5 = dock5 | TOP;
	showDock(Dock(dock5));
#endif
	
	return 0;
}
