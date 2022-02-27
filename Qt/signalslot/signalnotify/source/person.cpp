#include "person.h"
#include <QDebug>
#include "globalconnector.h"
#include "common.h"

Person::Person()
{
	GlobalConnector::getInstance()->attach(msg_counter_notify_person,this,SLOT(handleNodify(void*)));
}

void Person::handleNodify(void* ptr)
{
	if(ptr != nullptr)
	{
		int* pnumber = static_cast<int*>(ptr);
		qDebug()<<"handleNodify: number ="<<*pnumber;
	}
}