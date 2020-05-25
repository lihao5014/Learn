#include "linkQueue.h"
#include <stdio.h>

int main()
{
	LinkQueue *linkQueue;
	
//	printf("---debug---\n");
	linkQueue =  createLinkQueue();
	printf("isEmpty =%d\n",isEmpty(linkQueue));
	
	initLinkQueue(linkQueue,7,5);
	showLinkQueue(linkQueue);
	
	clearLinkQueue(linkQueue);
	showLinkQueue(linkQueue);
	
	printf("isEmpty =%d\n",isEmpty(linkQueue));
	printf("length =%d\n",getLength(linkQueue));
	
	pushLinkQueue(linkQueue,5);
	pushLinkQueue(linkQueue,6);
	pushLinkQueue(linkQueue,7);
	pushLinkQueue(linkQueue,7);
	pushLinkQueue(linkQueue,2);
	pushLinkQueue(linkQueue,3);
	pushLinkQueue(linkQueue,1);
	showLinkQueue(linkQueue);
	
	pushLinkQueue(linkQueue,4);
	pushLinkQueue(linkQueue,5);
	pushLinkQueue(linkQueue,9);
	pushLinkQueue(linkQueue,2);
	pushLinkQueue(linkQueue,9);
	pushLinkQueue(linkQueue,0);
	pushLinkQueue(linkQueue,2);
	pushLinkQueue(linkQueue,8);
	pushLinkQueue(linkQueue,8);
	pushLinkQueue(linkQueue,9);
	showLinkQueue(linkQueue);
	printf("length =%d\n",getLength(linkQueue));
	
	popLinkQueue(linkQueue);
	popLinkQueue(linkQueue);
	showLinkQueue(linkQueue);
	
	popLinkQueue(linkQueue);
	printf("popLinkQueue: %d\n",popLinkQueue(linkQueue));
	showLinkQueue(linkQueue);
	
	data_t data;
	data = findByPos(linkQueue,6);
	printf("index =%d, data =%d\n",6,data);

	int index;
	index = findByData(linkQueue,2);
	if(index != -1){
		printf("%d be finded at %d\n",2,index);
	}
	
	data = getFront(linkQueue);
	printf("front =%d\n",data);
	
	data = getRear(linkQueue);
	printf("rear =%d\n",data);
	
	pushLinkQueue(linkQueue,9);
	data = getFront(linkQueue);
	showLinkQueue(linkQueue);
	printf("front =%d\n",data);
	
	printf("length =%d\n",getLength(linkQueue));
	
	changeFront(linkQueue,11);
	showLinkQueue(linkQueue);
	
	changeRear(linkQueue,14);
	showLinkQueue(linkQueue);
	printf("length =%d\n",getLength(linkQueue));

	destroyLinkQueue(&linkQueue);

	return 0;
}