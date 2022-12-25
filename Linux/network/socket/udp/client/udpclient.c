#include <unistd.h>         //read(),write()
#include <arpa/inet.h>      //htons(),ntohs()
#include <netinet/in.h>     //struct sockaddr_in
#include <sys/socket.h>     //struct sockaddr,socket(),bind(),listen(),accept(),connect(),recvfrom(),sendto(),recv(),send()
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFF_SIZE 256

int main(void)
{
	//创建套接字
	int clnt_sock = socket(AF_INET,SOCK_DGRAM,0);
	if(-1 == clnt_sock)
	{
		perror("socket");
		return -1;
	}
	
	//设置客户端发送数据给的服务器IP和端口号
	struct sockaddr_in serv_addr;
	memset(&serv_addr,0,sizeof(struct sockaddr_in));
	serv_addr.sin_family = AF_INET;                         //使用IPv4地址协议
	serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");     //设置IP
	serv_addr.sin_port = htons(1234);                       //设置端口号，htons()主机字节序转网络字节序
	
	//循环向服务器发送数据
	char buf[BUFF_SIZE] = {0};
	while(1)
	{
		printf(">>");
		scanf("%s",buf);
		getchar();                 //吸收scanf()函数输入的'\n'回车键
		
		int len = strlen(buf) + 1;
		if(sendto(clnt_sock,buf,len,0,(struct sockaddr*)&serv_addr,sizeof(struct sockaddr)) < 0)
		{
			perror("sendto");
			break;
		}
		
		if(0 == strcmp(buf,"q"))
		{
			puts("client exit");
			const char* text = "exit";
			len = strlen(text) + 1;
			sendto(clnt_sock,text,len,0,(struct sockaddr*)&serv_addr,sizeof(struct sockaddr));
			break;
		}
		
		memset(buf,0,len);
	}
	
	close(clnt_sock);
	return 0;
}