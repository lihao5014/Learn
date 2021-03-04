#include <stdio.h>
#include <iostream>
#include <QDebug>

#define _CHANGE_WAY_
// #undef _CHANGE_WAY_

using namespace std;

int main(int argc,char** argv)
{
#ifndef _CHANGE_WAY_
	qDebug()<<"qDebug : hello world"<<endl;
#else
	cout<<"std::cout : hello world"<<endl;
#endif

	getchar();    //防止程序运行完以后终端闪退
	return 0;
}