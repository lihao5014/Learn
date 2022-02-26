#include "reciever.h"
#include <QDebug>

void Reciever::slotTransPointer(int *ptr)
{
	if(ptr != nullptr)
	{
		qDebug()<<"slotTransPointer: *ptr ="<<*ptr;
		
		*ptr += 10;
		qDebug()<<"slotTransPointer modify: *ptr ="<<*ptr;
	}
}

void Reciever::slotTransReference(double &ref)
{
		qDebug()<<"slotTransReference: ref ="<<ref;
		
		ref *= 10;
		qDebug()<<"slotTransReference modify: ref ="<<ref;	
}

void Reciever::slotTransStruct(Data_t data)
{
	qDebug()<<"slotTransStruct: "<<data.m_foo<<" , "<<data.m_bar<<" , "<<data.m_qux;
}

void Reciever::slotTransVariant(QVariant var)
{
	Data data = var.value<Data_t>();
	qDebug()<<"slotTransVariant: "<<data.m_foo<<" , "<<data.m_bar<<" , "<<data.m_qux;
}