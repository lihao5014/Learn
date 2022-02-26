#include <QDebug>
#include "sender.h"
#include "reciever.h"

int main(void)
{
	Sender sender;
	Reciever reciever;
	
	QObject::connect(&sender,SIGNAL(sigTransPointer(int*)),&reciever,SLOT(slotTransPointer(int*)));
	sender.transPointer();
	
	int temp1 = 7;
	emit sender.sigTransPointer(&temp1);
	qDebug()<<"temp1 ="<<temp1<<"\n";
	
	QObject::connect(&sender,&Sender::sigTransReference,&reciever,&Reciever::slotTransReference);
	sender.transReference();
	
	double temp2 = 1.414;
	emit sender.sigTransReference(temp2);
	qDebug()<<"temp2 ="<<temp2<<"\n";

	QObject::connect(&sender,SIGNAL(sigTransStruct(Data_t)),&reciever,SLOT(slotTransStruct(Data_t)));
	sender.transStruct();
	
	QObject::connect(&sender,&Sender::sigTransVariant,&reciever,&Reciever::slotTransVariant);
	sender.transVariant();
	
	return 0;
}