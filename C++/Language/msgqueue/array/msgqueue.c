#include "msgqueue.h"
#include <stdio.h>
#include <stdlib.h>

Signal_t msgQueue[SIZE];

static void copySignal(Signal_t *dts,const Signal_t src)
{
	if(dts == NULL)
	{
		fprintf(stdout,"copySignal warn: dts is null\n");
		return ;
	}
	
	dts->x = src.x;
	dts->y = src.y;
	dts->action = src.action;
}

void initMsg(const Signal_t msgArr[],int size)
{
	if(size <=0 || size > SIZE)
	{
		puts("initMsg warn: size is illegal");
		return ;
	}
	
	for(int i=0;i<SIZE;++i)
	{
		if(i < size)
		{
			(*(msgQueue + i)).x = msgArr[i].x;
			(*(msgQueue + i)).y = msgArr[i].y;
			(*(msgQueue + i)).action = msgArr[i].action;
			continue;
		}
		msgQueue[i].x = -EPS;
		msgQueue[i].y = -EPS;
		msgQueue[i].action = -1;
	}
}

void inputMsg()
{
	clearMsg();
	
	int opt = -1;
	double x = -EPS,y = -EPS;
	Signal_t signal = {-EPS,-EPS,-1};
	do{
		if(isFull())
		{
			puts("msgLoop warn: message queue is full");
			break;
		}
		printf("请输入两数和操作符：(0-加法，1-减法，2-乘法，3-除法，4-最大值，5-最小值)\n");
		fflush(stdin);                                //吸收getchar() != q中输入的换行键
		scanf("%lf %d %lf",&x,&opt,&y);               //scanf输入float类型使用%f，而输入double类型时必须使用%lf
		
		// DEBUG_FLAG
		signal.x = x;
		signal.y = y;
		signal.action = opt;
		pushMsg(signal);

		getchar();                                    //吸收scanf输入结尾敲的回车键
		puts("按q结束输入，其他键继续输入");
	}while(getchar() != 'q');	
}

void clearMsg()
{
	for(int i=0;i<SIZE;++i)
	{
		msgQueue[i].x = -EPS;
		msgQueue[i].y = -EPS;
		(msgQueue + i)->action = -1;
	}
}

bool isEmpty()
{
	for(int i=0;i<SIZE;++i)
	{
		if(msgQueue[i].action != -1)
		{
			return false;
		}
	}
	
	return true;
}

bool isFull()
{
	for(int i=0;i<SIZE;++i)
	{
		if((*(msgQueue + i)).action == -1)
		{
			return false;
		}
	}
	
	return true;
}

bool pushMsg(const Signal_t msg)
{
	if(isFull())
	{
		fputs("pushMsg warn: message queue is full\n",stdout);
		return false;
	}
	
	for(int i=SIZE-1;i>0;--i)
	{
		msgQueue[i].x = msgQueue[i - 1].x;
		msgQueue[i].y = msgQueue[i - 1].y;
		msgQueue[i].action = msgQueue[i - 1].action;
	}
	msgQueue->x = msg.x;
	msgQueue->y = msg.y;
	(*msgQueue).action = msg.action;
	return true;
}

Signal_t popMsg()
{
	if(isEmpty())
	{
		puts("popMsg warn: message queue is empty");
		exit(-1);
	}
	
	Signal_t ret = {-EPS,-EPS,-1};
	for(int i=0;i<SIZE-1;++i)
	{
		if(msgQueue[i + 1].action == -1)
		{
			ret = msgQueue[i];
			msgQueue[i].x = -EPS;
			(*(msgQueue +i)).y = -EPS;
			(msgQueue + i)->action = -1;
			return ret;
		}
	}
	
	ret = msgQueue[SIZE-1];
	copySignal((msgQueue + SIZE -1 ),ret);
	return ret;
}

int countMsg()
{
	for(int i=0;i<SIZE-1;++i)
	{
		if(msgQueue[i].action == -1)
		{
			return i;
		}
	}
	return SIZE;
}

void processMsg()
{
	Signal_t signal = {-EPS,-EPS,-1};
	while((signal = popMsg()).action != -1)
	{
		doProcess(signal.x,signal.y,signal.action);
	}
}

void showMsg()
{
	for(int i=0;i<SIZE;++i)
	{
		if(msgQueue[i].action != -1)
		{
			printf("x =%f, opt =%d, y =%f\n",msgQueue[i].x,msgQueue[i].action,msgQueue[i].y);
		}
	}
}

void msgLoop()
{
	inputMsg();
	// showMsg();
	// fprintf(stdout,"message queue count is %d\n",countMsg());
	processMsg();
}