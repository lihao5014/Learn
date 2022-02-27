#ifndef _PERSON_H
#define _PERSON_H

#include <QObject>

//QObject对象没有提供拷贝构造与赋值运算符，所以继承至QObject的类，也不能实现拷贝构造与赋值运算符。
class Person:public QObject
{
	Q_OBJECT
public:
	Person();
	// Person(const Person& other);
	
public slots:
	void handleNodify(void* ptr = nullptr);
};

#endif  //_PERSON_H