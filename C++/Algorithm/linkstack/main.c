#include "linkStack.h"
#include <stdio.h>

int main()
{
	LinkStack *linkStack;
	
	linkStack =  createLinkStack();
	printf("isEmpty =%d\n",isEmpty(linkStack));
	
	initLinkStack(linkStack,7,5);
	showLinkStack(linkStack);
	
	clearLinkStack(linkStack);
	showLinkStack(linkStack);
	
	printf("isEmpty =%d\n",isEmpty(linkStack));
	printf("length =%d\n",getLength(linkStack));
	
	pushLinkStack(linkStack,5);
	pushLinkStack(linkStack,6);
	pushLinkStack(linkStack,7);
	pushLinkStack(linkStack,7);
	pushLinkStack(linkStack,2);
	pushLinkStack(linkStack,3);
	pushLinkStack(linkStack,1);
	showLinkStack(linkStack);
	
	pushLinkStack(linkStack,4);
	pushLinkStack(linkStack,5);
	pushLinkStack(linkStack,9);
	pushLinkStack(linkStack,2);
	pushLinkStack(linkStack,9);
	pushLinkStack(linkStack,0);
	pushLinkStack(linkStack,2);
	pushLinkStack(linkStack,8);
	pushLinkStack(linkStack,8);
	pushLinkStack(linkStack,9);
	showLinkStack(linkStack);
	printf("length =%d\n",getLength(linkStack));
	
	popLinkStack(linkStack);
	popLinkStack(linkStack);
	showLinkStack(linkStack);
	
	popLinkStack(linkStack);
	printf("popLinkStack: %d\n",popLinkStack(linkStack));
	showLinkStack(linkStack);
	
	data_t data;
	data = findByPos(linkStack,6);
	printf("index =%d, data =%d\n",6,data);

	int index;
	index = findByData(linkStack,2);
	if(index != -1){
		printf("%d be finded at %d\n",2,index);
	}
	
	data = getTop(linkStack);
	printf("top =%d\n",data);
	
	pushLinkStack(linkStack,9);
	showLinkStack(linkStack);
	data = getTop(linkStack);
	printf("top =%d\n",data);
	
	printf("length =%d\n",getLength(linkStack));
	
	changeTop(linkStack,11);
	showLinkStack(linkStack);
	
	destroyLinkStack(&linkStack);

	return 0;
}