#include "sender.h"
#include <QDebug>

void Sender::transNormalPointer()
{
	int value = 10;
	emit sigTransNormalPointer(&value);
	qDebug()<<"transNormalPointer: value ="<<value;
}

void Sender::transCustomPointer()
{
	Data_t *pData = new Data_t{11,0.5,"Data_t* pointer"};
	emit sigTransCustomPointer(pData);
	qDebug()<<"transCustomPointer: "<<pData->m_foo<<" , "<<pData->m_bar<<" , "<<pData->m_qux;	
}

void Sender::transVoidPointer()
{
	Data_t *pData = new Data_t{12,1.5,"void* pointer"};
	emit sigTransVoidPointer(pData);
	qDebug()<<"transVoidPointer: "<<pData->m_foo<<" , "<<pData->m_bar<<" , "<<pData->m_qux;		
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

void Sender::transStdSharedPointer()
{
	std::shared_ptr<Data_t> dataPtr = std::make_shared<Data_t>(Data_t{25,1.414,"hello c"});
	emit sigTransStdSharedPointer(dataPtr);	
}

void Sender::transQSharedPointer()
{
	QSharedPointer<Data_t> dataPtr(new Data_t);
	dataPtr->m_foo = 30;
	dataPtr->m_bar = 9.78;
	dataPtr->m_qux = "hello c++";
	emit sigTransQSharedPointer(dataPtr);	
}