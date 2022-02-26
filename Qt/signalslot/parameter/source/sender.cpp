#include "sender.h"
#include <QDebug>

void Sender::transPointer()
{
	int value = 10;
	emit sigTransPointer(&value);
	qDebug()<<"transPointer: value ="<<value;
}

void Sender::transReference()
{
	double number = 3.14;
	emit sigTransReference(number);
	qDebug()<<"transReference: number ="<<number;
}

void Sender::transStruct()
{
	Data_t data = {15,0.618,"hello c++"};
	emit sigTransStruct(data);
}

void Sender::transVariant()
{
	Data_t data = {20,2.718,"hello qt"};
	QVariant var;
	var.setValue(data);      //可以显示指定函数模板参数，var.setValue<Data_t>(data)
	emit sigTransVariant(var);
}