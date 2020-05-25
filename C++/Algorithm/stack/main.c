#include "stack.h"
#include <stdio.h>

int main()
{
	Stack *stack;
	
	stack =  createStack(20);
	printf("isEmpty =%d\n",isEmpty(stack));
	
	initStack(stack,7);
	showStack(stack);
	
	clearStack(stack);
	showStack(stack);
	
	printf("isEmpty =%d\n",isEmpty(stack));
	printf("length =%d\n",getLength(stack));
	
	pushStack(stack,5);
	pushStack(stack,6);
	pushStack(stack,7);
	pushStack(stack,7);
	pushStack(stack,2);
	pushStack(stack,3);
	pushStack(stack,1);
	showStack(stack);
	
	pushStack(stack,4);
	pushStack(stack,5);
	pushStack(stack,9);
	pushStack(stack,2);
	pushStack(stack,9);
	pushStack(stack,0);
	pushStack(stack,2);
	pushStack(stack,8);
	pushStack(stack,8);
	pushStack(stack,9);
	showStack(stack);
	printf("length =%d\n",getLength(stack));
	
	popStack(stack);
	popStack(stack);
	showStack(stack);
	
	popStack(stack);
	printf("popStack: %d\n",popStack(stack));
	showStack(stack);
	
	data_t data;
	data = findByPos(stack,6);
	printf("index =%d, data =%d\n",6,data);

	int index;
	index = findByData(stack,2);
	if(index != -1){
		printf("%d be finded at %d\n",2,index);
	}
	
	data = getTop(stack);
	printf("top =%d\n",data);
	
	pushStack(stack,9);
	data = getTop(stack);
	showStack(stack);
	printf("top =%d\n",data);
	
	printf("length =%d\n",getLength(stack));
	
	changeTop(stack,11);
	showStack(stack);
	
	destroyStack(&stack);

	return 0;
}