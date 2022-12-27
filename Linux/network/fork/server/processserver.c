#include <unistd.h>         //read(),write(),fork()
#include <sys/wait.h>       //wait(),waitpid()
#include <sys/types.h>      //pid_t,ssize_t
#include <arpa/inet.h>      //htons(),ntohs()
#include <netinet/in.h>     //struct sockaddr_in
#include <sys/socket.h>     //struct sockaddr,socket(),bind(),listen(),accept(),connect()
#include <errno.h>          //errno
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

static void recycle_subprocess(int signo);

static void service_task(int sockfd);

int main()
{
	pid_t mainpid = getpid();
	printf("main process pid =%d\n",mainpid);
	
	//通过捕捉子进程退出信号SIGCHLD的方式，回收子进程资源，以避免产生僵尸进程。
	signal(SIGCHLD,recycle_subprocess);
	
	//创建监听套接字
	int listenfd = socket(AF_INET,SOCK_STREAM,0);
	if(-1 == listenfd)
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
	int ret = bind(listenfd,(struct sockaddr*)&serv_addr,sizeof(struct sockaddr));
	if(-1 == ret)
	{
		perror("bind");
		close(listenfd);
		return -1;
	}
	
	//进入监听状态，等待客户端发起连接请求
	ret = listen(listenfd,10);
	if(-1 == ret)
	{
		perror("listen");
		close(listenfd);
		return -1;
	}
	
	//一个进程处理一个客户端连接。
	for(;;)
	{
		//接收客户端请求，创建连接套接字。
		struct sockaddr_in clnt_addr;
		socklen_t addrlen = sizeof(clnt_addr);
		int connfd = accept(listenfd,(struct sockaddr*)&clnt_addr,&addrlen);
		if(-1 == connfd)
		{
			if(errno == EINTR)   //accept()会被SIGCHLD信号中断，解除阻塞，返回-1
			{
				continue;        //由于SIGCHLD信号造成的accept()函数返回-1，就重新再调用accept()。
			}
			
			perror("accept");
			break;
		}
		printf("client connect successfully: connfd =%d, ip =%s, port =%d\n",connfd,inet_ntoa(clnt_addr.sin_addr),clnt_addr.sin_port);
		
		pid_t pid = fork();
		if(pid == -1)
		{
			perror("fork error");
			return -1;
		}
		else if(pid > 0)
		{
			close(connfd);
		}
		else if(pid == 0)
		{
			close(listenfd);
			service_task(connfd);
			exit(0);
		}
	}
	
	close(listenfd);
	return 0;
}

void recycle_subprocess(int signo)
{
	pid_t pid;
	while((pid = waitpid(-1,NULL,WNOHANG)) > 0)
	{
		printf("child die, pid =%d\n",pid);
	}
	
	printf("recycle_subprocess signo =%d\n",signo);
}

void service_task(int connfd)
{
	pid_t pid = getpid();
	pid_t ppid = getppid();
	char text[BUFF_SIZE] = {0};
	sprintf(text,"child process pid =%d, ppid =%d, connfd =%d",pid,ppid,connfd);
	puts(text);
	
	char buf[BUFF_SIZE] = {0};
	while(1)
	{
		char info[BUFF_SIZE] = {0};
		strcpy(info,text);
		strcat(info," : ");
		
		int size = read(connfd,buf,BUFF_SIZE);
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
			printf("service child process %d exit!\n",pid);
			break;
		}
		memset(buf,0,BUFF_SIZE);
	}
	
	close(connfd);
}