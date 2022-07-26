#include <QDebug>
#include "sender.h"
#include "reciever.h"

#define _CHANGE_WAY_
#undef _CHANGE_WAY_

#ifndef _CHANGE_WAY_
#pragma message("using: Q_DECLARE_METATYPE")
//Qt�źŲ�Ҫ��������ָ�룬����ʹ��qRegisterMetaType()������Q_DECLARE_METATYPE��ע��Ԫ�������͡�
Q_DECLARE_METATYPE(std::shared_ptr<Data_t>)
Q_DECLARE_METATYPE(QSharedPointer<Data_t>)
#endif

int main(void)
{
	Sender sender;
	Reciever reciever;
	
	QObject::connect(&sender,SIGNAL(sigTransNormalPointer(int*)),&reciever,SLOT(slotTransNormalPointer(int*)));
	sender.transNormalPointer();
	
	int temp1 = 7;
	emit sender.sigTransNormalPointer(&temp1);
	qDebug()<<"temp1 ="<<temp1<<"\n";
	
	/*Qt�źŲ۴����Զ�����������ָ��Data_t*����ʱ������Ҫʹ��Q_DECLARE_METATYPE(Data_t*)
	 *��ע��Ԫ�������͡���Ϊ32λϵͳ������ָ��Ĵ�С����ȷ����4�ֽڣ�����Qt�źŲ۴�������
	 *����ָ��ʱ������Ҫʹ��qRegisterMetaType()��Q_DECLARE_METATYPE���������͵�Ԫ���ݡ�
	 */
	QObject::connect(&sender,SIGNAL(sigTransCustomPointer(Data_t*)),&reciever,SLOT(slotTransCustomPointer(Data_t*)));
	sender.transCustomPointer();
	
	QObject::connect(&sender,&Sender::sigTransVoidPointer,&reciever,&Reciever::slotTransVoidPointer);
	sender.transVoidPointer();
	
	QObject::connect(&sender,&Sender::sigTransReference,&reciever,&Reciever::slotTransReference);
	sender.transReference();
	
	double temp2 = 1.414;
	emit sender.sigTransReference(temp2);
	qDebug()<<"temp2 ="<<temp2<<"\n";

	QObject::connect(&sender,SIGNAL(sigTransStruct(Data_t)),&reciever,SLOT(slotTransStruct(Data_t)));
	sender.transStruct();
	
	QObject::connect(&sender,&Sender::sigTransVariant,&reciever,&Reciever::slotTransVariant);
	sender.transVariant();
	
#ifdef _CHANGE_WAY_
#pragma message("using: qRegisterMetaType()")
	qRegisterMetaType<std::shared_ptr<Data_t>>("std::shared_ptr<Data_t>");
	qRegisterMetaType<QSharedPointer<Data_t>>("QSharedPointer<Data_t>");
#endif
	
	QObject::connect(&sender,SIGNAL(sigTransStdSharedPointer(std::shared_ptr<Data_t>)),&reciever,SLOT(slotTransStdSharedPointer(std::shared_ptr<Data_t>)));
	sender.transStdSharedPointer();
	
	QObject::connect(&sender,&Sender::sigTransQSharedPointer,&reciever,&Reciever::slotTransQSharedPointer);
	sender.transQSharedPointer();
	
	return 0;
}