#ifndef _COUNTER_H
#define _COUNTER_H

#include <QObject>

class Counter:public QObject
{
	Q_OBJECT
public:
	Counter(int value);
	// Counter(const Counter& other);  //QObject对象没有提供拷贝构造与赋值运算符，
	                                   //所以继承至QObject的类，也不能实现拷贝构造与赋值运算符。
	void setValue(const int value);
	int value()const;
	void display()const;
signals:
	void valueChange(int value);
public slots:
	void onChangeValue(int value);
private:
	int m_value;
};

#endif //_COUNTER_H