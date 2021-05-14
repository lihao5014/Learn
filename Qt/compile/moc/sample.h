#ifndef _SAMPLE_H
#define _SAMPLE_H

#include <QtCore/QObject>

typedef int data_t;

class Sample:public QObject
{
	Q_OBJECT
public:
	explicit Sample(const data_t& value);
	virtual ~Sample();   //Sample类中没有成员指针，所以可以不需要定义析构函数来回收资源
	
	void setValue(const data_t& value);
	data_t getValue()const;
	void display()const;

signals:
	void changeValue(const data_t& value);

public slots:
	void onChangeValue(const data_t& value);
	
private:
	data_t value;
};

#endif //_SAMPLE_H