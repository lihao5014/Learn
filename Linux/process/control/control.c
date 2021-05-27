/*1.并发和并行的区别：
 *（1）并发的同时运行是一个假象。CPU在某一个时间点只能为某一个个体来服务，因此不可能同时处理多任务，
 *     并发看上去就像多个进程同时运行，其实是通过计算机的CPU快速的时间片切换实现的。
 *（2）并发是针对某一个硬件资源而言的，在某个时间段之内处理的任务的总量，量越大效率越高。
 *（3）并行的多进程同时运行是真实存在的，可以在同一时刻同时运行多个进程
 *（4）并行需要依赖多个CPU硬件资源，单个CPU是无法实现的。
 */

/*2.单个CPU并行处理多任务的实现原理：
 *  CPU会给每个进程被分配一个时间段，进程得到这个时间片之后才可以运行，使各个程序从表面上看是同时进行的。
 *  如果在时间片结束时进程还在运行，CPU的使用权将被收回，该进程将会被中断挂起等待下一个时间片。如果进程
 *  在时间片结束前阻塞或结束，则CPU当即进行切换，这样就可以避免CPU资源的浪费。因此在我们使用的计算机中
 *  启动的多个程序，从宏观上看是同时运行的，从微观上看由于CPU一次只能处理一个进程，所以它们是轮流执行的，
 *  只不过切换速度太快，我们感觉不到罢了，因此CPU的核数越多计算机的处理效率越高。
 */
 
/*3.PCB（Processing Control Block）进程控制块：（Linux内核的进程控制块本质上是一个叫做task_struct的结构体）
 *（1）进程id：每一个进程都一个唯一的进程ID，类型为pid_t, 本质是一个整形数。
 *（2）进程的状态：进程有不同的状态，状态是一直在变化的，有就绪、运行、挂起、停止等状态。
 *（3）进程对应的虚拟地址空间的信息。
 *（4）描述控制终端的信息，进程在哪个终端启动默认就和哪个终端绑定。
 *（5）当前工作目录：默认情况下，启动进程的目录就是当前的工作目录
 *（6）umask掩码：在创建新文件的时候，通过这个掩码屏蔽某些用于对文件的操作权限。
 *（7）文件描述符表：每个被分配的文件描述符都对应一个已经打开的磁盘文件
 *（8）信号相关的信息：在Linux中调用函数、键盘快捷键、执行shell命令等操作都会产生信号。
 *（9）阻塞信号集：记录当前进程中阻塞哪些已产生的信号，使其不能被处理。
 *（10）未决信号集：记录在当前进程中产生的哪些信号还没有被处理掉。
 *（11）用户id和组id：当前进程属于哪个用户，属于哪个用户组。
 *（12）会话（Session）和进程组：多个进程的集合叫进程组，多个进程组的集合叫会话。
 *（13）进程可以使用的资源上限：可以使用shell命令ulimit -a查看详细信息。
 */
 
/*在多进程序中，进程的执行顺序是没有规律的，因为所有的进程都需要在就绪态争抢CPU时间片，抢到了就执行，
 *抢不到就不执行，但是不用担心，默认进程的优先级是相同的，操作系统不会让某一个进程一直抢不到CPU时间片。
 */

/*4.执行多进程程序时，造成终端显示混乱原因：（孤儿进程就会造成，程序运行结束后终端显示混乱问题。而僵尸进程则不会）
 *（1）a.out进程启动之后，共创建了多个子进程，其实a.out也是有父进程的就是当前的终端。
 *（2）终端只能检测到a.out进程的状态，在a.out执行期间终端切换到后台，a.out执行完毕之后终端切换回前台。
 *（3）当终端切换到前台时，a.out的子进程还没有执行完毕。子进程输出的信息就显示到终端命令提示符的后边了，
 *     导致终端显示有问题，但是此时终端是可以接收键盘输入的，只是看起来不美观而已。
 *（4）解决该问题需要让所有子进程退出之后再退出父进程，比如：在父进程代码中调用sleep()/wait()/waitpid()。
 */

/*5.进程控制：（进程控制主要是指进程的退出、进程的回收、进程的特殊状态——孤儿进程和僵尸进程）
 *（1）结束进程：如果想要直接退出某个进程可以在程序的任何位置调用exit()或者_exit()函数。函数的参数相当于退出码。
 *     在main()函数中直接使用return语句也可以退出进程，假如是在一个普通函数中调用return只能返回到调用者的位置，
 *     而不能退出进程。
 *（2）回收进程资源：为了避免僵尸进程的产生，一般我们会在父进程中进行子进程的资源回收。回收方式有两种，
 *     一种是阻塞方式wait()；一种是非阻塞方式waitpid()。
 *（3）孤儿进程：在一个启动的进程中创建子进程，这时候父子进程同时运行，但是父进程由于某种原因先退出了，
 *     子进程还在运行，这时候这个子进程就可以被称之为孤儿进程
 *（4）僵尸进程：在一个启动的进程中创建子进程，这时候就有了父子两个进程。如果父进程正常运行，子进程先于父进程结束，
 *     子进程无法释放自己的PCB资源，需要父进程来做这个件事儿，但是如果父进程也不管，这时候子进程就变成了僵尸进程。
 */

#include <unistd.h>     //fork(),sleep(),_exit()
#include <sys/types.h>
#include <sys/wait.h>   //wait(),waitpid(),WIFEXITED(),WEXITSTATUS()
#include <stdio.h>
#include <stdlib.h>     //exit()
#include <string.h>     //strerror()
#include <errno.h>

#define BUFF_SIZE 512

#define PRINT_INFO(str)  \
	write(STDOUT_FILENO,str,strlen(str))

#define ERROR_INFO(str)  \
	write(STDERR_FILENO,str,strlen(str))

#define SAVE_INFO(fb,str)  \
	write(STDERR_FILENO,str,strlen(str))

typedef void (*pFun)();

typedef enum Signal_t
{
	EXIT,
	WAIT,
	WAITPID,
	ZOMBIE,
	ORPHAN,
	SIGNAL_COUNT
}Signal_t;

static void exit_test();
static void wait_test();
static void waitpid_test();
static void zombie_test();    //测试僵尸进程
static void orphan_test();    //测试孤儿进程

#ifndef _CHANGE_WAY_
static const char* signal_str[SIGNAL_COUNT] = {
	[EXIT] = "exit",
	[WAIT] = "wait",
	[WAITPID] = "waitpid",
	[ZOMBIE] = "zombie",
	[ORPHAN] = "orphan"
};

typedef struct Message_t
{
	Signal_t signal;
	pFun handle;
}Message_t;

static const Message_t message_map[SIGNAL_COUNT] = {
	{EXIT,exit_test},
	{WAIT,wait_test},
	{WAITPID,waitpid_test},
	{ZOMBIE,zombie_test},
	{ORPHAN,orphan_test}
};
#else
typedef struct Message_t
{
	char signal[16];
	pFun handle;
}Message_t;

static const Message_t message_map[SIGNAL_COUNT] = {
	{"exit",exit_test},
	{"wait",wait_test},
	{"waitpid",waitpid_test},
	{"zombie",zombie_test},
	{"orphan",orphan_test}
};
#endif

int main(int argc,char* argv[])
{
	puts("usage: ./control.out exit/wait/zombie/orphan");
	if(argc != 2)
	{
		fputs("input argument illegal or default run zombie_test\n",stdout);
#ifndef _CHANGE_WAY_
		//默认测试僵尸进程的产生
		message_map[ZOMBIE].handle();
#else
		//默认测试孤儿进程的产生
		message_map[ORPHAN].handle();
#endif
		return 0;
	}

#ifndef _CHANGE_WAY_
#	pragma message("---undefined _CHANGE_WAY_---")
	for(int i=0;i < SIGNAL_COUNT;++i)
	{
		if(strcmp(argv[1],signal_str[i]) == 0 
			&& message_map[i].signal == i)
		{
			message_map[i].handle();
			return 0;
		}
	}
#else
#	pragma message("---defined _CHANGE_WAY_---")
	for(int i=0;i < SIGNAL_COUNT;++i)
	{	
		if(strcmp(argv[1],message_map[i].signal) == 0)
		{
			message_map[i].handle();
			return 0;
		}
	}
#endif
	
	return 0;
}

void exit_test()
{
#ifndef _CHANGE_WAY_
	printf("using exit()...\n");
	printf("this content will be output on exit");
	exit(0);
#else
	printf("using _exit()...\n");
	printf("this content can't be print on _exit");
	_exit(0);
#endif
}

void wait_test()
{
	pid_t pid = fork();
	if(pid == -1)
	{
		ERROR_INFO("wait_test: fork faild\n");
		return ;
	}
	else if(pid == 0)
	{
		printf("wait_test: child process ,pid =%d ,ppid =%d\n",getpid(),getppid());
		for(int i=0;i<8;++i)
		{
			puts("wait_test: child process runing");
			sleep(1);
		}
		
		PRINT_INFO("wait_test: child process run finished and exit\n");
		exit(100);
	}
	else if(pid > 0)
	{
		fprintf(stdout,"wait_test: parent process ,pid =%d ,spid =%d ,ppid =%d\n",getpid(),pid,getppid());
		fprintf(stdout,"wait_test: parent process ,wait recycle child process ,spid =%d\n",pid);
		
		int status;
#ifndef _CHANGE_WAY_
		pid_t retpid = wait(&status);   //wait(&status)底层实现就是waitpid(-1,&status,0)
#else
		pid_t retpid = waitpid(-1,&status,0);
#endif
		if(retpid == -1)
		{
			PRINT_INFO("wait_test: parent process ,recycle child process faild\n");
			return ;
		}
		
		if(WIFEXITED(status))   //判断子进程是否正常退出
		{
			printf("wait_test: parent process, the child process exits normally - %d\n",WEXITSTATUS(status));   //获取子进程的退出码
		}
		else
		{
			puts("wait_test: parent process, the child process exits unexpectedly");
		}
		
		fputs("wait_test: parent process exit\n",stdout);
	}
}

void waitpid_test()
{
	pid_t pid = fork();
	if(pid == -1)
	{
		ERROR_INFO("waitpid_test: fork faild\n");
		return ;
	}
	else if(pid == 0)
	{
		printf("waitpid_test: child process ,pid =%d ,ppid =%d\n",getpid(),getppid());
		for(int i=0;i<8;++i)
		{
			puts("waitpid_test: child process runing");
			sleep(1);
		}
		
		PRINT_INFO("waitpid_test: child process run finished and exit\n");
		_exit(150);
	}
	else if(pid > 0)
	{
		fprintf(stdout,"waitpid_test: parent process ,pid =%d ,spid =%d ,ppid =%d\n",getpid(),pid,getppid());
		fprintf(stdout,"waitpid_test: parent process ,waitpid recycle child process ,spid =%d\n",pid);
		
		int status;
		pid_t retpid;
		do{
			retpid = waitpid(pid,&status,WNOHANG);    //使用waitpid非阻塞回收子进程退出资源时，需要轮询等待
			if(retpid == -1)
			{
				PRINT_INFO("waitpid_test: parent process ,recycle child process faild\n");
				return ;
			}
			else if(retpid == 0)
			{
				printf("waitpid_test: parent process ,child process runing, pid =%d ,spid =%d\n",getpid(),pid);
				PRINT_INFO("waitpid_test: parent process ,do other work\n");
				sleep(2);
			}
			else if(retpid == pid)
			{
				printf("waitpid_test: parent process ,capture child process exit ,pid =%d, spid =%d\n",getpid(),pid);
				break;
			}
		}while(1);
		
		if(WIFEXITED(status))   //判断子进程是否正常退出
		{
			printf("waitpid_test: parent process, the child process exits normally - %d\n",WEXITSTATUS(status));   //获取子进程的退出码
		}
		else
		{
			puts("waitpid_test: parent process, the child process exits unexpectedly");
		}
		
		puts("waitpid_test: parent process exit");
	}
}

void zombie_test()
{
	pid_t pid = fork();
	if(pid == -1)
	{
		fprintf(stdout,"zombie_test error: %s\n",strerror(errno));
		exit(-1);
	}
	else if(pid == 0)
	{
		printf("zombie_test: child process ,pid =%d ,ppid =%d\n",getpid(),getppid());
		puts("zombie_test: child process run finished and exit");
		
		/*子进程先与父进程执行完，调不调用exit/_exit函数退出子进程，
		 *子进程都会变为僵尸进程，等待父进程为其收尸。
		 */
		exit(0);
	}
	else if(pid > 0)
	{
		printf("zombie_test: parent process ,pid =%d ,spid =%d ,ppid =%d\n",getpid(),pid,getppid());
		
		for(int i=0;i<15;++i)
		{
			puts("zombie_test: parent process runing");
			sleep(1);
		}
		puts("zombie_test: parent process run finished");
	}
}

void orphan_test()
{
	pid_t pid = fork();
	if(pid == -1)
	{
		perror("orphan_test error: ");
		_exit(-1);
	}
	else if(pid == 0)
	{
		printf("orphan_test: child process ,pid =%d ,ppid =%d\n",getpid(),getppid());
		
		for(int i=0;i<15;++i)   //强迫子进程后于父进程退出, 使子进程变成了孤儿进程
		{
			fprintf(stdout,"orphan_test: child process runing, pid =%d ,ppid =%d\n",getpid(),getppid());
			sleep(1);
		}
		fputs("orphan_test: child process run finished\n",stdout);
	}
	else if(pid > 0)
	{
		printf("orphan_test: parent process ,pid =%d ,spid =%d ,ppid =%d\n",getpid(),pid,getppid());
		sleep(2);   //父进程延时2s退出，以便使用ps -ef | grep control.out命令查看父子进程的状态
		puts("orphan_test: parent process run finished");
	}
}