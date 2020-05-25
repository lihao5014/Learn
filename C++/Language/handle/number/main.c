#include "employee.h"
#include <stdio.h>

int main(void)
{
	int hemployee = createEmployee("Bob",123456);       //创建雇员对象，返回雇员结构体句柄
	showEmployee(hemployee);
	
	setName(hemployee,"kevin");
	setNum(hemployee,456789);
	showEmployee(hemployee);
	printf("hemployee =%d, name =%s,num =%d\n",hemployee,getName(hemployee),getNum(hemployee));
	
	int hemployee1 = createEmployee("Tom",987654);
	showEmployee(hemployee1);
	printf("hemployee1 =%d, name =%s,num =%d\n",hemployee1,getName(hemployee1),getNum(hemployee1));
	
	destroyEmployee(hemployee);
	
	int hemployee2 = createEmployee("amy",147258);
	showEmployee(hemployee2);
	printf("hemployee2 =%d, name =%s,num =%d\n",hemployee2,getName(hemployee2),getNum(hemployee2));
	
	destroyEmployee(hemployee1);
	destroyEmployee(hemployee2);
	return 0;
}