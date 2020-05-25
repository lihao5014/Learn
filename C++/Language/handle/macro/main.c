#include "employee.h"
#include <stdio.h>

int main(void)
{
	HEmployee hemployee = createEmployee("Bob",123456);       //创建雇员对象，返回雇员结构体句柄
	showEmployee(hemployee);
	
	setName(hemployee,"kevin");
	setNum(hemployee,456789);
	showEmployee(hemployee);
	printf("hemployee =%p, name =%s,num =%d\n",hemployee,getName(hemployee),getNum(hemployee));
	destroyEmployee(&hemployee);
	
	HEmployee hemployee1 = createEmployee("Tom",987654);
	showEmployee(hemployee1);
	printf("hemployee1 =%p, name =%s,num =%d\n",hemployee1,getName(hemployee1),getNum(hemployee1));
	destroyEmployee(&hemployee1);
	
	return 0;
}