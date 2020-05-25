#include "person.h"
#include <stdio.h>

int main(void)
{
	HPerson hperson = createPerson("Tom");      //获取Person对象的句柄，并使用句柄去操作对象
	setAge(hperson,25);
	showPerson(hperson);
	
	destroyPerson(&hperson);
	return 0;
}