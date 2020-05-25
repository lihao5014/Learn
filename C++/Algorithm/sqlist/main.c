#include "sqlist.h"
#include <stdio.h>

int main()
{
	SqList *sqlist;
	
	sqlist =  createSqlist();
	showSqlist(sqlist);
	
	initSqlist(sqlist,5);
	showSqlist(sqlist);
	
	clearSqlist(sqlist);
	showSqlist(sqlist);
	
	insert(sqlist,0,5);
	insert(sqlist,1,6);
	insert(sqlist,2,7);
	insert(sqlist,3,1);
	showSqlist(sqlist);
	
	insert(sqlist,0,5);
	insert(sqlist,0,9);
	insert(sqlist,1,8);
	insert(sqlist,2,8);
	insert(sqlist,3,9);
	showSqlist(sqlist);
	
	append(sqlist,4);
	append(sqlist,4);
	append(sqlist,3);
	showSqlist(sqlist);
	
	prepend(sqlist,1);
	prepend(sqlist,7);
	prepend(sqlist,2);
	showSqlist(sqlist);
	
	int index = -1;
	index = findByData_L(sqlist,8);
	if(index == -1){
		printf("%d can't find\n",8);
	}else{
		printf("%d find_L at %d\n",8,index);
	}
	
	index = findByData_R(sqlist,8);
	if(index == -1){
		printf("%d can't find\n",8);
	}else{
		printf("%d find_R at %d\n",8,index);
	}
	
	data_t num = findByPos(sqlist,5);
	printf("index =%d, num =%d\n",5,num);
	
	deleteByPos(sqlist,7);
	showSqlist(sqlist);
	
	deleteByData(sqlist,8);
	showSqlist(sqlist);
	
	changeByPos(sqlist,8,14);
	showSqlist(sqlist);
	
	changeByData(sqlist,4,7);
	showSqlist(sqlist);
	
	printf("size =%d\n",getSize(sqlist));
	printf("length =%d\n",getLength(sqlist));
	
	destroySqlist(&sqlist);
	return 0;
}