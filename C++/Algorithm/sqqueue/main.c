#include "sqqueue.h"
#include <stdio.h>

int main()
{
	SqQueue *sqqueue;
	
	printf("---debug---\n");
	sqqueue =  createSqQueue();
	printf("isEmpty =%d\n",isEmpty(sqqueue));
	
	initSqQueue(sqqueue,7);
	showSqQueue(sqqueue);
	
	clearSqQueue(sqqueue);
	showSqQueue(sqqueue);
	
	printf("isEmpty =%d\n",isEmpty(sqqueue));
	printf("length =%d\n",getLength(sqqueue));
	
	pushSqQueue(sqqueue,5);
	pushSqQueue(sqqueue,6);
	pushSqQueue(sqqueue,7);
	pushSqQueue(sqqueue,7);
	pushSqQueue(sqqueue,2);
	pushSqQueue(sqqueue,3);
	pushSqQueue(sqqueue,1);
	showSqQueue(sqqueue);
	
	pushSqQueue(sqqueue,4);
	pushSqQueue(sqqueue,5);
	pushSqQueue(sqqueue,9);
	pushSqQueue(sqqueue,2);
	pushSqQueue(sqqueue,9);
	pushSqQueue(sqqueue,0);
	pushSqQueue(sqqueue,2);
	pushSqQueue(sqqueue,8);
	pushSqQueue(sqqueue,8);
	pushSqQueue(sqqueue,9);
	showSqQueue(sqqueue);
	printf("length =%d\n",getLength(sqqueue));
	
	popSqQueue(sqqueue);
	popSqQueue(sqqueue);
	showSqQueue(sqqueue);
	
	popSqQueue(sqqueue);
	printf("popSqQueue: %d\n",popSqQueue(sqqueue));
	showSqQueue(sqqueue);
	
	data_t data;
	data = findByPos(sqqueue,6);
	printf("index =%d, data =%d\n",6,data);

	int index;
	index = findByData(sqqueue,2);
	if(index != -1){
		printf("%d be finded at %d\n",2,index);
	}
	
	data = getFront(sqqueue);
	printf("front =%d\n",data);
	
	data = getRear(sqqueue);
	printf("rear =%d\n",data);
	
	pushSqQueue(sqqueue,9);
	data = getFront(sqqueue);
	showSqQueue(sqqueue);
	printf("front =%d\n",data);
	
	printf("length =%d\n",getLength(sqqueue));
	
	changeFront(sqqueue,11);
	showSqQueue(sqqueue);
	
	changeRear(sqqueue,14);
	showSqQueue(sqqueue);
	
	destroySqQueue(&sqqueue);

	return 0;
}