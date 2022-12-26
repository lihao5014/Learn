#include <unistd.h>         //read(),write()
#include <arpa/inet.h>      //htons(),ntohs()
#include <netinet/in.h>     //struct sockaddr_in
#include <sys/socket.h>     //struct sockaddr,socket(),bind(),listen(),accept(),connect()
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFF_SIZE 256

int main(void)
{
	//创建套接字
	int clnt_sock = socket(AF_INET,SOCK_STREAM,0);
	if(-1 == clnt_sock)
	{
		perror("socket");
		return -1;
	}
	
	//设置客户端需要连接的服务器IP和端口号
	struct sockaddr_in serv_addr;
	memset(&serv_addr,0,sizeof(struct sockaddr_in));
	serv_addr.sin_family = AF_INET;                         //使用IPv4地址协议
	serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");     //设置IP
	serv_addr.sin_port = htons(1234);                       //设置端口号，htons()主机字节序转网络字节序
	
	//向服务器发起连接请求
	int ret = connect(clnt_sock,(struct sockaddr*)&serv_addr,sizeof(struct sockaddr));
	if(-1 == ret)
	{
		perror("connect");
		close(clnt_sock);
		return -1;
	}
	
	//循环向服务器发送数据
	char buf[BUFF_SIZE] = {0};
	while(1)
	{
		printf(">>");
		scanf("%s",buf);
		getchar();              //吸收scanf()函数输入的'\n'回车键
		
		int len = strlen(buf) + 1;
		if(write(clnt_sock,buf,len) < 0)
		{
			perror("write");
			break;
		}
		
		if(0 == strcmp(buf,"q"))
		{
			puts("client exit");
			write(clnt_sock,"exit",strlen("exit") + 1);
			break;
		}
		
		memset(buf,0,len);
	}
	
	close(clnt_sock);
	return 0;
}