#include "array.h"
#include <stdio.h>

int main()
{
	Array array;
	
	printf("--debug--\n");
	Array_Ctor(&array,10);	
	initArray(&array,5);
	displayArray(&array);
	
	int size = getSize(&array);
	printf("size = %d\n",size);
	
	data_t n = at(&array,4);
	printf("at(%d) = %d\n",4,n);
	
	setData(&array,1,1);
	setData(&array,3,3);
	setData(&array,5,5);
	setData(&array,7,7);
	setData(&array,9,3);
	displayArray(&array);
	
	int index = findData_L(&array,5);
	printf("findData_L(%d) = %d\n",5,index);
	
	index = findData_R(&array,5);
	printf("findData_L(%d) = %d\n",5,index);

	deleteData(&array,5);
	displayArray(&array);
	
	changeData(&array,3,8);
	displayArray(&array);
	
	reSize(&array,7);
	displayArray(&array);
	
	initArray(&array,4);
	displayArray(&array);	

	clearArray(&array);
	displayArray(&array);
	
	Array_Dtor(&array);
	return 0;
}