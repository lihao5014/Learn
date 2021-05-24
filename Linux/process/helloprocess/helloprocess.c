#include <unistd.h>       //write(),sleep(),getpid(),getppid()
#include <sys/types.h>    //pid_t
#include <sys/wait.h>
#include <stdio.h>
#include <string.h>

#define BUFF_SIZE 1024

#define PRINT_INFO(str)  \
	write(STDOUT_FILENO,str,strlen(str))

int main(void)
{
	PRINT_INFO("---start main---\n");
	
	char buf[BUFF_SIZE] = {0};
	sprintf(buf,"main process id: %d\n",getpid());
	PRINT_INFO(buf);
	
	int var = 0;  //变量var在父子进程的栈空间中都存在，且在父子进程空间中的地址都相同
	
	/*fork()创建的子进程完整的拷贝了主进程的4G内存空间，包括堆栈信息、代码段和数据段，
	 *所以父子进程包含相同的运行代码、全局变量、静态变量和字符串常量。
	 */
	pid_t pid = fork();   //fork()成功后在主进程中返回子进程pid，在子进程中返回0。fork()失败返回-1
	if(pid == -1)
	{
		perror("fork error: ");
		return -1;
	}
	else if(pid > 0)   //fork()成功后父子进程都会执行这条else if(pid > 0)判断。
	{
		/*父子进程的代码段中都具有else if(pid > 0)判断的语句块，只是由于父进程中pid才大于0，
		 *所以只有父进程才能走进来，子进程由于pid等于0，所以不会执行这一段代码块。
		 */
		++var;
		int mainpid = getpid();   //获取当前进程id，由于当前进程为主进程，所以为获取主进程id
		memset(buf,0,sizeof(buf));
		sprintf(buf,"this is main process, pid =%d,mainpid =%d, var =%d, &var =%p\n",pid,mainpid,var,&var);
		
		PRINT_INFO(buf);
		var++;
	}
	else if(pid == 0)  //fork()成功后父子进程都会执行这条else if(pid = 0)判断。
	{
		/*父子进程的代码段中都具有else if(pid == 0)判断的语句块，只是由于子进程中pid才等于0，
		 *所以只有子进程才能走进来，父进程由于pid大于0，所以不会执行这一段代码块。
		 */
		++var;
		int subpid = getpid();   //获取当前进程id，由于当前进程为子进程，所以为获取子进程id
		memset(buf,0,sizeof(buf));
		sprintf(buf,"this is child process,pid =%d,subpid =%d, var =%d, &var =%p\n",pid,subpid,var,&var);
		
		PRINT_INFO(buf);
		var += 1;
	}
	
	//由于没有区分父子进程pid，所以主进程和子进程都会执行这一段代码。
	memset(buf,0,BUFF_SIZE);
	sprintf(buf,"var will print twice, var =%d, &var =%p, pid =%d, getpid() =%d\n\n",var,&var,pid,getpid());
	PRINT_INFO(buf);
	
	//阻塞主进程和子进程，方便使用ps -ef | grep helloprocess.out查看进程id
	sleep(10);
	PRINT_INFO("---end main---\n");
	
	return 0;
}