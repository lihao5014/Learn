#include "sqstack.h"
#include <stdio.h>

int main()
{
	SqStack *sqstack;
	
	sqstack =  createSqstack();
	printf("isEmpty =%d\n",isEmpty(sqstack));
	
	initSqstack(sqstack,7);
	showSqstack(sqstack);
	
	clearSqstack(sqstack);
	showSqstack(sqstack);
	
	printf("isEmpty =%d\n",isEmpty(sqstack));
	printf("length =%d\n",getLength(sqstack));
	
	pushSqstack(sqstack,5);
	pushSqstack(sqstack,6);
	pushSqstack(sqstack,7);
	pushSqstack(sqstack,7);
	pushSqstack(sqstack,2);
	pushSqstack(sqstack,3);
	pushSqstack(sqstack,1);
	showSqstack(sqstack);
	
	pushSqstack(sqstack,4);
	pushSqstack(sqstack,5);
	pushSqstack(sqstack,9);
	pushSqstack(sqstack,2);
	pushSqstack(sqstack,9);
	pushSqstack(sqstack,0);
	pushSqstack(sqstack,2);
	pushSqstack(sqstack,8);
	pushSqstack(sqstack,8);
	pushSqstack(sqstack,9);
	showSqstack(sqstack);
	printf("length =%d\n",getLength(sqstack));
	
	popSqstack(sqstack);
	popSqstack(sqstack);
	showSqstack(sqstack);
	
	popSqstack(sqstack);
	popSqstack(sqstack);
	showSqstack(sqstack);
	
	data_t data;
	data = findByPos(sqstack,6);
	printf("index =%d, data =%d\n",6,data);

	int index;
	index = findByData(sqstack,2);
	if(index != -1){
		printf("%d be finded at %d\n",2,index);
	}
	
	data = getTop(sqstack);
	printf("top =%d\n",data);
	
	pushSqstack(sqstack,9);
	data = getTop(sqstack);
	showSqstack(sqstack);
	printf("top =%d\n",data);
	
	printf("length =%d\n",getLength(sqstack));
	
	changeTop(sqstack,11);
	showSqstack(sqstack);
	
	destroySqstack(&sqstack);
	return 0;
}