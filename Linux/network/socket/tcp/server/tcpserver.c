#include <unistd.h>         //read(),write()
#include <arpa/inet.h>      //htons(),ntohs()
#include <netinet/in.h>     //struct sockaddr_in
#include <sys/socket.h>     //struct sockaddr,socket(),bind(),listen(),accept(),connect()
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BUFF_SIZE 256

#define PRINT(str)                              \
	do{                                         \
		time_t currentTime = time(NULL);        \
		char* strTime = ctime(&currentTime);    \
		printf("%s : %s\n",strTime,str);        \
	}while(0)
		

int main()
{
	//创建监听套接字
	int serv_sock = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
	if(-1 == serv_sock)
	{
		perror("socket");
		return -1;
	}
	
	//设置服务端IP和端口号
	struct sockaddr_in serv_addr;
	memset(&serv_addr,0,sizeof(struct sockaddr_in));
	serv_addr.sin_family = AF_INET;                         //使用IPv4地址协议
	serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");     //设置IP
	serv_addr.sin_port = htons(1234);    	                //设置端口号，htons()主机字节序转网络字节序
	
	//将监听套接字和IP，端口号绑定
	int ret = bind(serv_sock,(struct sockaddr*)&serv_addr,sizeof(struct sockaddr));
	if(-1 == ret)
	{
		perror("bind");
		close(serv_sock);
		return -1;
	}
	
	//进入监听状态，等待用户发起连接请求
	ret = listen(serv_sock,10);
	if(-1 == ret)
	{
		perror("listen");
		close(serv_sock);
		return -1;
	}
	
	//接收客户端请求，创建连接套接字。
	struct sockaddr_in clnt_addr;
	socklen_t addrlen = sizeof(clnt_addr);
	int clnt_sock = accept(serv_sock,(struct sockaddr*)&clnt_addr,&addrlen);
	if(-1 == clnt_sock)
	{
		perror("accept");
		close(serv_sock);
		return -1;
	}
	printf("client connect successfully: ip =%s ,port =%d\n",inet_ntoa(clnt_addr.sin_addr),clnt_addr.sin_port);
	
	//有一个客户端连接上了，服务器就关闭监听套接字。这样只有一个客户端可以和该服务器通信。
	close(serv_sock);
	
	//循环从客户端接收数据
	char buf[BUFF_SIZE] = {0};
	for(;;)
	{
		int size = read(clnt_sock,buf,BUFF_SIZE);
		if(size < 0)
		{
			perror("read");
			break;
		}
		else if(size == 0)
		{
			puts("read error: connect break!");
			break;
		}
		
		PRINT(buf);
		
		if(0 == strcmp(buf,"exit"))
		{
			puts("server exit!");
			break;
		}
		
		memset(buf,0,BUFF_SIZE);
	}
	
	close(clnt_sock);
	return 0;
}