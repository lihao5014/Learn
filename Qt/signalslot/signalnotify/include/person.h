#ifndef _PERSON_H
#define _PERSON_H

#include <QObject>

//QObject����û���ṩ���������븳ֵ����������Լ̳���QObject���࣬Ҳ����ʵ�ֿ��������븳ֵ�������
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