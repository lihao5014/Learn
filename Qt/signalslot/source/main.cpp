#include <QDebug>
#include "counter.h"

#define _APP_
#undef _APP_

#ifdef _APP_
#include <QCoreApplication>
#endif

#define UNUSED(x) (void)x

static void updataValue(int value);

int main(int argc,char* argv[])
{
#ifdef _APP_
	QCoreApplication app(argc,argv);     //单线程信号槽可以不依赖事件循环就可以正常工作
#endif

	Counter counterA(10),counterB(20);
	QObject::connect(&counterA,SIGNAL(valueChange(int)),&counterB,SLOT(onChangeValue(int)));
	counterA.setValue(11);
	counterB.display();
	qDebug()<<"";
	
	QObject::connect(&counterA,&Counter::valueChange,updataValue);    //信号连接普通函数
	counterA.setValue(12);
	qDebug()<<"";
	
	counterB.display();
	QObject::connect(&counterA,&Counter::valueChange,               //信号连接lambda表达式
		[&counterB](int value){
			qDebug()<<"lambda: value ="<<value;
			counterB.setValue(value);
		}
	);
	counterA.setValue(13);
	counterB.display();

#ifdef _APP_
	return app.exec();   //如果Qt程序中没有GUI部分，且信号槽为单线程信号槽，那么就可以不用开启Qt的事件循环
#else
	return 0;
#endif
}

void updataValue(int value)
{
	qDebug()<<"updataValue: value ="<<value;
}