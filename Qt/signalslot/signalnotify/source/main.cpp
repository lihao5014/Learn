#include "counter.h"
#include "person.h"
#include "globalconnector.h"
#include "common.h"

int main()
{
	Counter counter;
	Person person;
	counter.triggerNodify(10);
	
	int number = 25;
	GlobalConnector::getInstance()->attach(msg_person_adjust_counter,&counter,SLOT(onChangeCount(void*)));
	GlobalConnector::getInstance()->notify(msg_person_adjust_counter,&number);
	
	int value = 30;
	GlobalConnector::getInstance()->detach(msg_person_adjust_counter,&counter);
	GlobalConnector::getInstance()->notify(msg_person_adjust_counter,&value);
	
	GlobalConnector::getInstance()->detach(msg_counter_notify_person,&person);
	counter.triggerNodify(10);
	
	return 0;
}