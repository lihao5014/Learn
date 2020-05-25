#include "message.h"
#include <string.h>

#define SIZE 512

int main()
{
	Message msg1 = {
		123456,
		'a',
		3.14159,
		"cmd-open"
	};
	showMsg(msg1);
	
	Message msg2;
	sendMsg(msg1);
	recvMsg(&msg2);
	showMsg(msg2);
	
	char buf[SIZE] = {0};
	msgToArray(msg1,buf,sizeof(buf));
	showMsgArr(buf,SIZE);
	
	Message *pmsg = (Message*)buf;
	pmsg->id = 987654;
	pmsg->type = 'b';
	pmsg->value = 2.71828,
	strcpy(pmsg->data,"msg-click");
	showMsgArr(buf,sizeof(buf));
	
	arrayToMsg(buf,SIZE,&msg2);
	showMsg(msg2);
	
	return 0;
}