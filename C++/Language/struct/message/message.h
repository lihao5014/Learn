#ifndef _MESSAGE_H
#define _MESSAGE_H

/*
 *结构体转化为数组以后，对数组的访问有两种方式：
 *1.将数组转换为结构体，使用结构体指针去访问。（这种访问方式最简单）
 *2.通过char类型的指针加上结构体中个变量的偏移量去访问。
 */

#define DATA_SIZE 256
#define BUFF_SIZE 1024
#define MSG_SIZE sizeof(Message)

//Message不是字节对齐结构体，所以只能转化为char buf[]
typedef struct Message
{
	int id;
	char type;
	double value;
	char data[DATA_SIZE];
}Message;

typedef enum Message_t
{
	ID,
	TYPE,
	VALUE,
	DATA,
	END_MSG
}Message_t;

extern char socketBuf[];
extern char offsetArr[];

void showMsg(const Message msg);
void showMsgArr(const char* arr,int size);

void sendMsg(const Message msg);
void recvMsg(Message *msg);

void msgToArray(const Message msg,char* arr,int size);
void arrayToMsg(const char* arr,int size,Message *msg);

#endif //_MESSAGE_H