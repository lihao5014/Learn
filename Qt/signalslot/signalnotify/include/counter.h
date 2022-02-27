#ifndef _COUNTER_H
#define _COUNTER_H

#include <QObject>

//QObject对象没有提供拷贝构造与赋值运算符，所以继承至QObject的类，也不能实现拷贝构造与赋值运算符。
class Counter:public QObject
{
	Q_OBJECT
public:
	Counter();
	// Counter(const Counter& other);

	void triggerNodify(int number);
	
public slots:
	void onChangeCount(void* ptr = nullptr);
};

#endif //_COUNTER_H