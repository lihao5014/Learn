#ifndef _WELCOME_H
#define _WELCOME_H

//直接将界面打印在终端上
extern void showWelcome();

//先将需要打印的UI信息先绘制到frame buffer上，在一次性将内存中的数据打印在屏幕上
extern void drawWelcome();

#endif //_WELCOME_H