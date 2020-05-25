#include "message.h"
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stddef.h>

#define _CHANGE_WAY_
// #undef _CHANGE_WAY_

char socketBuf[BUFF_SIZE] = {0};     //socketBuf的大小可以比Message结构体的大小大

char offsetArr[END_MSG] = {
	[ID] = offsetof(Message,id),
	[TYPE] = offsetof(Message,type),
	[VALUE] = offsetof(Message,value),
	[DATA] = offsetof(Message,data)
};

void showMsg(const Message msg)
{
	printf("id:%d type:%c value:%f data:%s\n",
		msg.id,
		msg.type,
		msg.value,
		msg.data
	);
}

#ifndef _CHANGE_WAY_
void showMsgArr(const char* arr,int size)
{
	assert(arr != NULL);
	assert(size >= MSG_SIZE);
	
	const Message* pmsg = (const Message*)arr;
	fprintf(stdout,"id:%d type:%c value:%f data:%s\n",
		pmsg->id,
		pmsg->type,
		pmsg->value,
		pmsg->data
	);
}
#else
void showMsgArr(const char* arr,int size)
{
	assert(arr != NULL);
	assert(size >= MSG_SIZE);
	
	const char* p = arr;
	fprintf(stdout,"id:%d type:%c value:%f data:%s\n",
		*((int*)(p+offsetArr[ID])),
		*(p+offsetArr[TYPE]),
		*((double*)(p+offsetArr[VALUE])),
		p+offsetArr[DATA]
	);
}	
#endif

#if 0    //总共三种实现方法
void sendMsg(const Message msg)
{
	memset(socketBuf,0,BUFF_SIZE);
	memcpy(socketBuf,&msg,sizeof(Message));
}

void recvMsg(Message *msg)
{
	if(msg == NULL)
	{
		puts("msg is null");
		return ;
	}
	
	memcpy(msg,socketBuf,MSG_SIZE);
	memset(socketBuf,0,BUFF_SIZE);
}

void msgToArray(const Message msg,char* arr,int size)
{
	if(arr == NULL || size < MSG_SIZE)
	{
		fprintf(stdout,"arr is null,or size is less than message size\n");
		return ;
	}
	
	memset(arr,0,size);
	memcpy(arr,&msg,sizeof(Message));
}

void arrayToMsg(const char* arr,int size,Message *msg)
{
	if(arr == NULL || size < sizeof(Message) || msg == NULL)
	{
		printf("arr or msg is null,or size is less than message size\n");
		return ;
	}
	memcpy(msg,arr,MSG_SIZE);
}
#elif 0
void sendMsg(const Message msg)
{
	memset(socketBuf,0,BUFF_SIZE);
	
	Message* pmsg = (Message*)socketBuf;
	pmsg->id = msg.id;
	pmsg->type = msg.type;
	pmsg->value = msg.value;
	strcpy(pmsg->data,msg.data);
}

void recvMsg(Message *msg)
{
	if(msg == NULL)
	{
		fputs("msg is null",stdout);
		return ;
	}
	
	const Message* p = (const Message*)socketBuf;
	msg->id = p->id;
	msg->type = p->type;
	msg->value = p->value;
	memcpy(msg->data,p->data,DATA_SIZE);
	memset(socketBuf,0,BUFF_SIZE);
}

void msgToArray(const Message msg,char* arr,int size)
{
	if(arr == NULL || size < MSG_SIZE)
	{
		fprintf(stdout,"arr is null,or size is less than message size\n");
		return ;
	}
	memset(arr,0,size);
	
	Message* pmsg = (Message*)arr;
	pmsg->id = msg.id;
	pmsg->type = msg.type;
	pmsg->value = msg.value;
	strcpy(pmsg->data,msg.data);
}

void arrayToMsg(const char* arr,int size,Message *msg)
{
	if(arr == NULL || size < sizeof(Message) || msg == NULL)
	{
		printf("arr or msg is null,or size is less than message size\n");
		return ;
	}

	const Message* p = (const Message*)arr;
	msg->id = p->id;
	msg->type = p->type;
	msg->value = p->value;
	memcpy(msg->data,p->data,DATA_SIZE);
}
#else
void sendMsg(const Message msg)
{
	memset(socketBuf,0,BUFF_SIZE);
	
	char* p = socketBuf;
	*((int*)(p+offsetArr[ID])) = msg.id;
	*(p+offsetArr[TYPE]) = msg.type;
	*((double*)(p+offsetArr[VALUE])) = msg.value;
	strcpy(p+offsetArr[DATA],msg.data);
}

void recvMsg(Message *msg)
{
	if(msg == NULL)
	{
		fputs("msg is null",stdout);
		return ;
	}
	
	const char* p = socketBuf;
	msg->id = *((int*)(p+offsetArr[ID]));
	msg->type = *(p+offsetArr[TYPE]);
	msg->value = *((double*)(p+offsetArr[VALUE]));
	memcpy(msg->data,p+offsetArr[DATA],DATA_SIZE);
	memset(socketBuf,0,BUFF_SIZE);
}

void msgToArray(const Message msg,char* arr,int size)
{
	if(arr == NULL || size < MSG_SIZE)
	{
		fprintf(stdout,"arr is null,or size is less than message size\n");
		return ;
	}
	memset(arr,0,size);
	
	char* p = arr;
	*((int*)(p+offsetArr[ID])) = msg.id;
	*(p+offsetArr[TYPE]) = msg.type;
	*((double*)(p+offsetArr[VALUE])) = msg.value;
	strcpy(p+offsetArr[DATA],msg.data);
}

void arrayToMsg(const char* arr,int size,Message *msg)
{
	if(arr == NULL || size < sizeof(Message) || msg == NULL)
	{
		printf("arr or msg is null,or size is less than message size\n");
		return ;
	}

	const char* p = arr;
	msg->id = *((int*)(p+offsetArr[ID]));
	msg->type = *(p+offsetArr[TYPE]);
	msg->value = *((double*)(p+offsetArr[VALUE]));
	memcpy(msg->data,p+offsetArr[DATA],DATA_SIZE);
}
#endif