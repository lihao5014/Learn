#include <unistd.h>         //read(),write()
#include <arpa/inet.h>      //htons(),ntohs()
#include <netinet/in.h>     //struct sockaddr_in
#include <sys/socket.h>     //struct sockaddr,socket(),bind(),listen(),accept(),connect()
#include <pthread.h>        //pthread_create(),pthread_join(),pthread_detach(),pthread_exit(),pthread_self()
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BUFF_SIZE 256

#define PRINT(str)                                \
	do{                                           \
		time_t currentTime = time(NULL);          \
		char* strTime = ctime(&currentTime);      \
		char buf[BUFF_SIZE] = {0};                \
		memcpy(buf,strTime,strlen(strTime) - 1);  \
		printf("%s : %s\n",buf,str);              \
	}while(0)

static void* service_task(void* param);

int main()
{
	pthread_t mainThreadId = pthread_self();
	printf("main thread id =%ld\n",mainThreadId);
	
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
	
	//进入监听状态，等待客户端发起连接请求
	ret = listen(serv_sock,10);
	if(-1 == ret)
	{
		perror("listen");
		close(serv_sock);
		return -1;
	}
	
	//一个线程处理一个客户端连接。
	struct sockaddr_in clnt_addr;
	socklen_t addrlen = sizeof(clnt_addr);
	for(;;)
	{
		//接收客户端请求，创建连接套接字。
		int clnt_sock = accept(serv_sock,(struct sockaddr*)&clnt_addr,&addrlen);
		if(-1 == clnt_sock)
		{
			perror("accept");
			break;
		}
		printf("client connect successfully: ip =%s ,port =%d\n",inet_ntoa(clnt_addr.sin_addr),clnt_addr.sin_port);
		
		pthread_t th;
		pthread_create(&th,NULL,service_task,&clnt_sock);
		pthread_detach(th);
	}
	
	close(serv_sock);
	return 0;
}

void* service_task(void* param)
{
	if(param == NULL)
	{
		return NULL;
	}
	
	int clnt_sock = *((int*)param);
	pthread_t threadId = pthread_self();
	char text[BUFF_SIZE] = {0};
	sprintf(text,"child thread id =%lu ,clnt_sock =%d",threadId,clnt_sock);
	puts(text);
	
	char buf[BUFF_SIZE] = {0};
	while(1)
	{
		char info[BUFF_SIZE] = {0};
		strcpy(info,text);
		strcat(info," : ");
		
		int size = read(clnt_sock,buf,BUFF_SIZE);
		if(-1 == size)
		{
			perror("read");
			break;
		}
		else if(0 == size)
		{
			printf("error: %s ,connect break!\n",text);
			break;
		}
		else
		{
			strcat(info,buf);
			PRINT(info);
		}
		
		if(0 == strcmp(buf,"exit"))
		{
			puts("service thread exit!");
			break;
		}
		memset(buf,0,BUFF_SIZE);
	}
	
	close(clnt_sock);
	return NULL;
}