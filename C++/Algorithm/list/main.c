#include "list.h"
#include <stdio.h>

int main()
{
	List *list;
	
	list =  createList(20);
	showList(list);
	
	initList(list,5);
	showList(list);
	
	clearList(list);
	showList(list);
	
	insert(list,0,5);
	insert(list,1,6);
	insert(list,2,7);
	insert(list,3,1);
	showList(list);
	
	insert(list,0,5);
	insert(list,0,9);
	insert(list,1,8);
	insert(list,2,8);
	insert(list,3,9);
	showList(list);
	
	append(list,4);
	append(list,4);
	append(list,3);
	showList(list);
	
	prepend(list,1);
	prepend(list,7);
	prepend(list,2);
	showList(list);
	
	int index = -1;
	index = findByData_L(list,8);
	if(index == -1){
		printf("%d can't find\n",8);
	}else{
		printf("%d find_L at %d\n",8,index);
	}
	
	index = findByData_R(list,8);
	if(index == -1){
		printf("%d can't find\n",8);
	}else{
		printf("%d find_R at %d\n",8,index);
	}
	
	data_t num = findByPos(list,5);
	printf("index =%d, num =%d\n",5,num);
	
	deleteByPos(list,7);
	showList(list);
	
	deleteByData(list,8);
	showList(list);
	
	changeByPos(list,8,14);
	showList(list);
	
	changeByData(list,4,7);
	showList(list);
	
	printf("size =%d\n",getSize(list));
	printf("length =%d\n",getLength(list));
	
	reSize(list,9);
	showList(list);
	
	printf("size =%d\n",getSize(list));
	printf("length =%d\n",getLength(list));
	
	destroyList(&list);
	return 0;
}