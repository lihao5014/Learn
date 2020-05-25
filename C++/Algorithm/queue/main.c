#include "queue.h"
#include <stdio.h>

int main()
{
	Queue *queue;
	
//	printf("---debug---\n");
	queue =  createQueue(20);
	printf("isEmpty =%d\n",isEmpty(queue));
	
	initQueue(queue,7);
	showQueue(queue);
	
	clearQueue(queue);
	showQueue(queue);
	
	printf("isEmpty =%d\n",isEmpty(queue));
	printf("length =%d\n",getLength(queue));
	
	pushQueue(queue,5);
	pushQueue(queue,6);
	pushQueue(queue,7);
	pushQueue(queue,7);
	pushQueue(queue,2);
	pushQueue(queue,3);
	pushQueue(queue,1);
	showQueue(queue);
	
	pushQueue(queue,4);
	pushQueue(queue,5);
	pushQueue(queue,9);
	pushQueue(queue,2);
	pushQueue(queue,9);
	pushQueue(queue,0);
	pushQueue(queue,2);
	pushQueue(queue,8);
	pushQueue(queue,8);
	pushQueue(queue,9);
	showQueue(queue);
	printf("length =%d\n",getLength(queue));
	
	popQueue(queue);
	popQueue(queue);
	showQueue(queue);
	
	popQueue(queue);
	printf("popQueue: %d\n",popQueue(queue));
	showQueue(queue);
	
	data_t data;
	data = findByPos(queue,6);
	printf("index =%d, data =%d\n",6,data);

	int index;
	index = findByData(queue,2);
	if(index != -1){
		printf("%d be finded at %d\n",2,index);
	}
	
	data = getFront(queue);
	printf("front =%d\n",data);
	
	data = getRear(queue);
	printf("rear =%d\n",data);
	
	pushQueue(queue,9);
	data = getFront(queue);
	showQueue(queue);
	printf("front =%d\n",data);
	
	printf("length =%d\n",getLength(queue));
	
	changeFront(queue,11);
	showQueue(queue);
	
	changeRear(queue,14);
	showQueue(queue);
	printf("length =%d\n",getLength(queue));
	printf("size =%d\n",getSize(queue));
	
	reSize(queue,25);
	showQueue(queue);
	printf("length =%d\n",getLength(queue));
	printf("size =%d\n",getSize(queue));
	
	reSize(queue,18);
	showQueue(queue);
	printf("length =%d\n",getLength(queue));
	printf("size =%d\n",getSize(queue));
	
	reSize(queue,10);
	showQueue(queue);
	printf("length =%d\n",getLength(queue));
	printf("size =%d\n",getSize(queue));
	
	popQueue(queue);
	popQueue(queue);
	popQueue(queue);
	popQueue(queue);
	popQueue(queue);
	popQueue(queue);
	showQueue(queue);
	
	pushQueue(queue,4);
	pushQueue(queue,5);
	pushQueue(queue,9);
	pushQueue(queue,9);
	showQueue(queue);
	printf("length =%d\n",getLength(queue));
	printf("size =%d\n",getSize(queue));
	
	reSize(queue,5);
	showQueue(queue);
	printf("length =%d\n",getLength(queue));
	printf("size =%d\n",getSize(queue));

	destroyQueue(&queue);

	return 0;
}