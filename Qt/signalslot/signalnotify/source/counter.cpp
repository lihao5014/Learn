#include "counter.h"
#include <QDebug>
#include "globalconnector.h"
#include "common.h"

Counter::Counter()
{

}

void Counter::triggerNodify(int number)
{
	qDebug()<<"triggerNodify: number ="<<number;
	GlobalConnector::getInstance()->notify(msg_counter_notify_person,&number);
}

void Counter::onChangeCount(void* ptr)
{
	if(ptr != nullptr)
	{
		int* pnumber = static_cast<int*>(ptr);
		qDebug()<<"onChangeCount: number ="<<*pnumber;
	}
}