#include "linklist.h"
#include <stdio.h>

int main()
{
	LinkList *list;
	
	list =  createLinkList();
	printf("isNull =%d\n",isNull(list));
	
	initLinkList(list,5,7);
	showLinkList(list);
	
	clearLinkList(list);
	showLinkList(list);
	
	printf("isNull =%d\n",isNull(list));
	printf("isEmpty =%d\n",isEmpty(list));
	printf("length =%d\n",getLength(list));
	
	insert(list,0,5);
	insert(list,1,6);
	insert(list,2,7);
	insert(list,3,1);
	showLinkList(list);
	
	insert(list,0,5);
	insert(list,0,9);
	insert(list,1,8);
	insert(list,2,8);
	insert(list,3,9);
	showLinkList(list);
	
	append(list,4);
	append(list,4);
	append(list,3);
	showLinkList(list);
	
	prepend(list,1);
	prepend(list,7);
	prepend(list,2);
	showLinkList(list);
	
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
	showLinkList(list);
	
	deleteByData(list,8);
	showLinkList(list);
	
	changeByPos(list,8,14);
	showLinkList(list);
	
	changeByData(list,4,7);
	showLinkList(list);
	
	printf("isNull =%d\n",isNull(list));
	printf("isEmpty =%d\n",isEmpty(list));
	printf("length =%d\n",getLength(list));
	
	destroyLinkList(&list);
	return 0;
}