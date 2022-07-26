#include "reciever.h"
#include <QDebug>

void Reciever::slotTransNormalPointer(int *ptr)
{
	if(ptr != nullptr)
	{
		qDebug()<<"slotTransNormalPointer: *ptr ="<<*ptr;
		
		*ptr += 10;
		qDebug()<<"slotTransNormalPointer modify: *ptr ="<<*ptr;
	}
}

void Reciever::slotTransCustomPointer(Data_t *pData)
{
	if(pData != nullptr)
	{
		qDebug()<<"slotTransCustomPointer: "<<pData->m_foo<<" , "<<pData->m_bar<<" , "<<pData->m_qux;
		
		pData->m_foo += 20;
		pData->m_bar += 20;
		qDebug()<<"slotTransCustomPointer modify: "<<pData->m_foo<<" , "<<pData->m_bar<<" , "<<pData->m_qux;
	}
}

void Reciever::slotTransVoidPointer(void *ptr)
{
	Data_t* pData = static_cast<Data_t*>(ptr);
	if(pData != nullptr)
	{
		qDebug()<<"slotTransVoidPointer: "<<pData->m_foo<<" , "<<pData->m_bar<<" , "<<pData->m_qux;
		
		pData->m_foo += 30;
		pData->m_bar += 30;
		qDebug()<<"slotTransVoidPointer modify: "<<pData->m_foo<<" , "<<pData->m_bar<<" , "<<pData->m_qux;
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

void Reciever::slotTransStdSharedPointer(std::shared_ptr<Data_t> dataPtr)
{
	if(dataPtr == nullptr)
	{
		return;
	}
	
	qDebug()<<"slotTransStdSharedPointer: "<<dataPtr->m_foo<<" , "<<dataPtr->m_bar<<" , "<<dataPtr->m_qux;
}

void Reciever::slotTransQSharedPointer(QSharedPointer<Data_t> dataPtr)
{
	if(dataPtr == nullptr)
	{
		return;
	}
	
	qDebug()<<"slotTransStdSharedPointer: "<<dataPtr->m_foo<<" , "<<dataPtr->m_bar<<" , "<<dataPtr->m_qux;
}