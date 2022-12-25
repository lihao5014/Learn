#include <unistd.h>         //read(),write()
#include <arpa/inet.h>      //htons(),ntohs()
#include <netinet/in.h>     //struct sockaddr_in
#include <sys/socket.h>     //struct sockaddr,socket(),bind(),listen(),accept(),connect(),recvfrom(),sendto(),recv(),send()
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFF_SIZE 256

int main()
{
	//创建监听套接字
	int serv_sock = socket(AF_INET,SOCK_DGRAM,IPPROTO_UDP);
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
	
	//通信套接字和IP，端口号绑定
	int ret = bind(serv_sock,(struct sockaddr*)&serv_addr,sizeof(struct sockaddr));
	if(-1 == ret)
	{
		perror("bind");
		close(serv_sock);
		return -1;
	}
	
	//循环从客户端接收数据
	struct sockaddr_in clnt_addr;
	socklen_t addrlen = sizeof(clnt_addr);
	char buf[BUFF_SIZE] = {0};
	for(;;)
	{
		int size = recvfrom(serv_sock,buf,BUFF_SIZE,0,(struct sockaddr*)&clnt_addr,&addrlen);
		if(size < 0)
		{
			perror("read");
			break;
		}
		printf("%s ,ip =%s ,port =%d\n",buf,inet_ntoa(clnt_addr.sin_addr),clnt_addr.sin_port);
		
		if(0 == strcmp(buf,"exit"))
		{
			puts("server exit!");
			break;
		}
		
		memset(buf,0,BUFF_SIZE);
	}
	
	close(serv_sock);
	return 0;
}