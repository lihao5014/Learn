/*1.孤儿进程:（如果是64位系统，孤儿进程的父进程号并不是1号）
 *（1）父进程运行结束，但子进程还在运行，未运行结束的子进程就称为孤儿进程（Orphan Process）。
 *     孤儿进程最终会被init进程（1号进程）所收养，并由init进程对它们完成状态收集工作。
 *（2）孤儿进程是没有父进程的进程，为避免孤儿进程退出时无法释放所占用的资源而变为僵尸进程，
 *     进程号为1的init进程将会接受这些孤儿进程，这一过程也被称为收养。init进程就好像是一个孤儿院，
 *     专门负责处理孤儿进程的善后工作。每当出现一个孤儿进程的时候，内核就把孤儿进程的父进程设置为init，
 *     而init进程会循环地wait()它的已经退出的子进程。这样当一个孤儿进程凄凉地结束了其生命周期的时候，
 *     init进程就会代表党和政府出面处理它的一切善后工作。因此孤儿进程并不会有什么危害。
 *（3）操作系统当检测到某一个进程变成了孤儿进程，这时候系统中就会有一个固定的进程领养这个孤儿进程。
 *     如果使用Linux没有桌面终端，这个领养孤儿进程的进程就是init进程（PID=1），如果有桌面终端，
 *     这个领养孤儿进程就是桌面进程。
 *（4）在子进程退出的时候, 进程中的用户区可以自己释放, 但是进程内核区的pcb资源自己无法释放，
 *     必须要由父进程来释放子进程的pcb资源，孤儿进程被领养之后，这件事儿干爹就可以代劳了，
 *     这样可以避免系统资源的浪费。
 */

/*2.僵尸进程：
 *（1）进程已运行结束，但进程的占用的资源未被回收，这样的进程称为僵尸进程（Zombie Process）。
 *     子进程已运行结束，父进程未调用wait/waitpid函数回收子进程资源是子进程变为僵尸进程的原因。
 *（2）在每个进程退出的时候，内核释放该进程所有的资源、包括打开的文件、占用的内存等。但是仍然为其保留一定的信息，
 *     这些信息主要指进程控制块的信息（包括进程号、退出状态、运行时间等）。直到父进程通过wait()/waitpid()来获取
 *     其状态并释放。如果父进程不调用wait()/waitpid()的话，那么保留的那段信息就不会释放，其进程号就会一直被占用，
 *     但是系统所能使用的进程号是有限的，如果大量的产生僵死进程，将因为没有可用的进程号而导致系统不能产生新的进程，
 *     此即为僵尸进程的危害，应当避免。
 *（3）一个子进程在调用return或exit()结束自己的生命的时候，其实它并没有真正的被销毁，而是留下一个僵尸进程。
 *     僵尸进程是子进程结束时，父进程又没有回收子进程占用的资源。僵尸进程在消失之前会继续占用系统资源。
 *     如果父进程先退出，子进程被系统接管，子进程退出后系统会回收其占用的相关资源，不会成为僵尸进程。
 *（4）僵尸进程不能将它看成是一个正常的进程，这个进程已经死亡了，用户区资源已经被释放了，只是还占用着一些
 *     内核资源（PCB）。僵尸进程的出现是由于这个已死亡的进程的父进程不作为造成的。
 *（5）消灭僵尸进程的方法是，杀死这个僵尸进程的父进程，这样僵尸进程的资源就被系统回收了。通过kill -9 僵尸进程PID
 *     的方式是不能消灭僵尸进程的，这个命令只对活着的进程有效，僵尸进程已经死了，鞭尸是不能解决问题的。
 */

/*3.僵尸进程产生的过程：
 *（1）父进程调用fork创建子进程后，子进程运行直至其终止，它立即从内存中移除，但进程控制块PCB仍然保留在内核中。
 *（2）子进程的状态变成EXIT_ZOMBIE，并且向父进程发送SIGCHLD信号，父进程此时应该调用wait()系统调用来获取子进程的
 *     退出状态以及其它的信息。在wait调用之后，僵尸进程就完全从内存中移除。
 *（3）因此一个僵尸存在于其终止到父进程调用wait等函数这个时间的间隙，一般很快就消失，但如果父进程从不调用wait等
 *     系统调用来收集僵尸进程，那么这些进程会一直存在内存。
 */

/*4.避免僵尸进程的方法：
 *（1）父进程通过wait()/waitpid()函数等待子进程结束，并回收子进程资源，但这会导致父进程挂起。
 *（2）如果父进程要处理的事情很多，不能够挂起，可以通过signal()函数人为处理SIGCHLD信号。只要有子进程
 *     退出就会自动调用指定好的回调函数。因为子进程结束后，父进程会收到SIGCHLD信号，可以在其回调函数里
 *     调用wait()/waitpid()回收退出的子进程资源。
 *（3）如果父进程不关心子进程什么时候结束，那么可以用signal(SIGCHLD,SIG_IGN)通知内核，自己对子进程的结束
 *     不感兴趣，父进程忽略此信号。那么子进程结束后，内核会将其回收，并不再给父进程发送信号。
 *（4）父进程fork()一个子进程，然后继续工作。子进程再fork()一个孙进程后退出，那么孙进程就会被init进程接管，
 *     孙进程结束后，init进程会回收。不过子进程的回收还要自己做。通过两次fork()避免产生僵尸进程的原理是将
 *     子进程成为孤儿进程，从而其的父进程变为init进程，通过1号进程可以处理僵尸进程。
 */

/*5.exit()与 _exit()函数的使用方法：
 *（1）我们可以通过exit()或 _exit()来结束当前进程。它们的功能和用法是一样的，无非是所包含的头文件不一样。
 *     exit()属于标准库函数，_exit()属于系统调用函数。调用exit()函数退出进程时，会刷新I/O缓冲区，而调用
 *     _exit()结束进程时，不会刷新I/O缓冲区。
 *（2）exit()与 _exit()函数的参数status，是返回给父进程的参数（低8位有效），至于这个参数是多少根据需要来填写。
 */

/*5.wait()函数的使用方法：
 *（1）wait()是一个阻塞函数，如果没有子进程退出，函数会一直阻塞等待。当检测到子进程退出了，该函数阻塞解除
 *     回收子进程资源。wait()被调用一次，只能回收一个子进程的资源，如果有多个子进程需要资源回收，函数需要
 *     被调用多次。
 *（2）wait()成功返回被回收的子进程的进程ID。没有子进程资源可以回收了，函数的阻塞会自动解除，返回-1。
 *     回收子进程资源的时候出现了异常，也返回-1。
 *（3）WIFEXITED(status): 返回1, 进程是正常退出的。
 *（4）WEXITSTATUS(status)：得到进程退出时候的状态码，相当于return后边的数值，或者exit()函数的参数。
 *（5）WIFSIGNALED(status): 返回1, 进程是被信号杀死了。
 *（6）WTERMSIG(status): 获得进程是被哪个信号杀死的，会得到信号的编号。
 */

/*6.waitpid()函数的使用方法：
 *（1）waitpid()函数可以看做是wait()函数的升级版，通过该函数可以控制回收子进程资源的方式是阻塞还是非阻塞，
 *     另外还可以通过该函数进行精准打击，可以精确指定回收某个或者某一类或者是全部子进程资源。
 *（2）waitpid()成功返回被回收的子进程的进程ID。如果函数是非阻塞的，并且子进程还在运行，返回0。没有子进程资源
 *     可以回收了，函数如果是阻塞的，阻塞会解除，直接返回-1。回收子进程资源的时候出现了异常，也返回-1。
 *（3）pid = -1：回收所有的子进程资源和wait()是一样的，无差别回收，并不是一次性就可以回收多个，也是需要循环回收的。
 *（4）pid > 0：指定回收某一个进程的资源，pid是要回收的子进程的进程ID。
 *（5）pid = 0：回收当前进程组的所有子进程ID。
 *（6）pid < -1：pid的绝对值代表进程组ID，表示要回收这个进程组的所有子进程资源。
 *（7）status: 和wait()的参数是一样的，如果不在意结束状态值，则参数status可以设成NULL。
 *（8）options: 控制函数是阻塞还是非阻塞。0函数行为是阻塞的和wait()一样，WNOHANG函数行为是非阻塞的。
 */

#include <unistd.h>       //fork(),sleep(),_exit()
#include <sys/wait.h>     //wait(),waitpid()
#include <sys/types.h>    //pid_t,ssize_t
#include <stdio.h>        //perror()
#include <stdlib.h>       //exit(),abort()
#include <string.h>       //strerror()
#include <errno.h>        //errno

#define _CHANFE_WAY_
#undef _CHANFE_WAY_

typedef void (*pFun)();

typedef struct Message_t
{
	char signal[16];
	pFun handle;
}Message;

static void recycle_process(int signo);

static void orphan_test();
static void zombie_test();

static void wait_recycle();
static void waitpid_recycle();
static void signal_ignore();
static void signal_handle();
static void fork_twice();

static const Message message_map[] = {
	{"orphan",orphan_test},
	{"zombie",zombie_test},
	{"wait",wait_recycle},
	{"waitpid",waitpid_recycle},
	{"ignore",signal_ignore},
	{"handle",signal_handle},
	{"fork",fork_twice}
};

/*C语言中如果函数的参数是值或const指针类型，那么这个参数一定为传入参数。如果函数参数是指针，
 *那么这个参数一般作为传出参数。
 */
int main(int argc,char **argv)
{
	puts("usage: ./special.out orphan/zombie/wait/waitpid/ignore/handle/fork");
	if(argc != 2)
	{
		// orphan_test();
		// zombie_test();
		
		// wait_recycle();
		// waitpid_recycle();
		// signal_ignore();
		// signal_handle();
		fork_twice();
		
		return -1;
	}
	
	for(int i=0;i<sizeof(message_map)/sizeof(message_map[0]);++i)
	{
		if(strcmp(argv[i],message_map[i].signal) == 0)
		{
			message_map[i].handle();
			break;
		}
	};
	
	return 0;
}

void recycle_process(int signo)
{
#ifndef _CHANFE_WAY_
	pid_t pid;
	while((pid = waitpid(-1,NULL,WNOHANG)) > 0)   //处理僵尸进程, -1代表等待任意一个子进程, WNOHANG代表不阻塞
	{
		//只有检验没有僵尸进程，它才会返回0，这样就可以确保所有的僵尸进程都被杀死了。
		printf("child %d terminated.\n", pid);
	}
#else
	puts("deal with child process exit");
	
	/*wait()的参数status用来保存被收集进程退出时的一些状态，它是一个指向int类型的指针。
	 *但如果对子进程是如何死掉的毫不在意，只想把僵尸进程消灭掉，就可以设定这个参数为NULL。
	 *如果wait()成功会返回被收集的子进程的进程ID。如果调用进程没有子进程，调用就会失败，
	 *此时wait()返回-1，同时errno被置为ECHILD。
	 */
	wait(NULL);
#endif
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
		fprintf(stdout,"orphan_test: child process ,pid =%d ,ppid =%d\n",getpid(),getppid());
		
		for(int i=0;i<10;++i)
		{
			fputs("orphan_test: child process running\n",stdout);
			sleep(1);
		}
		
		fputs("orphan_test: child process finish and exit\n",stdout);
		exit(3);
	}
	else if(pid > 0)   //父进程先于子进程退出，子进程就变为了孤儿进程
	{
		printf("orphan_test: parent process ,pid =%d ,spid =%d ,ppid =%d\n",getpid(),pid,getppid());
		
		sleep(2);
		puts("orphan_test: parent process finish and exit");
		_exit(13);
	}
}

void zombie_test()
{
	pid_t pid = fork();
	if(pid == -1)
	{
		printf("orphan_test error: %s\n",strerror(errno));
		exit(-1);
	}
	else if(pid == 0)
	{
		fprintf(stdout,"orphan_test: child process ,pid =%d ,ppid =%d\n",getpid(),getppid());
		sleep(2);
		
		fputs("orphan_test: child process finish and exit\n",stdout);
		_exit(4);
	}
	else if(pid > 0)   //子进程先于父进程退出，且父进程中没有回收子进程退出资源，子进程就变为了僵尸进程
	{
		printf("orphan_test: parent process ,pid =%d ,spid =%d ,ppid =%d\n",getpid(),pid,getppid());
		
		for(int i=0;i<10;++i)
		{
			fputs("orphan_test: parent process running\n",stdout);
			sleep(1);
		}

		puts("orphan_test: parent process finish and exit");
		exit(14);
	}
}

void wait_recycle()
{
	pid_t pid = fork();
	if(pid == -1)
	{
		printf("wait_recycle error: %s\n",strerror(errno));
		exit(-1);
	}
	else if(pid == 0)
	{
		fprintf(stdout,"wait_recycle: child process ,pid =%d ,ppid =%d\n",getpid(),getppid());
		sleep(2);
		
		fputs("wait_recycle: child process finish and exit\n",stdout);
		_exit(5);
	}
	else if(pid > 0)   //子进程先于父进程退出，但父进程中使用wait()回收子进程退出资源，所以子进程不会变为僵尸进程
	{
		printf("wait_recycle: parent process ,pid =%d ,spid =%d ,ppid =%d\n",getpid(),pid,getppid());
		printf("wait_recycle: parent process call wait() recycle child process ,spid =%d\n",pid);

		/*阻塞回收子进程资源。调用一次wait()函数只能回收一个子进程，如果要回收多个子进程，则需要连续调用多次。
		 *wait()函数回收子进程成功返回已经结束子进程的进程号，失败返回-1。参数status用于返回进程退出时的状态信息。
		 *通过status参数传递出的信息判断回收的进程是怎么退出的，如果不需要该信息可以指定为NULL。
		 */
		int status;
		pid_t retpid = wait(&status);  //wait()函数的status参数为传出参数。
		if(retpid == -1)  //当没有子进程资源可以回收了或回收子进程资源的时候出现了异常，wait()都会失败，返回-1。
		{
			fprintf(stdout,"wait_recycle: parent process ,recycle child process faild\n");
			return ;
		}
		
		//取出wait()传出参数status中的数据需要使用一些宏函数：WIFEXITED(),WEXITSTATUS(),WIFSIGNALED(),WTERMSIG()等。
		if(WIFEXITED(status))   //WIFEXITED(status): 返回1, 进程是正常退出的
		{
			//WEXITSTATUS(status)：得到进程退出时候的状态码，相当于return后边的数值，或者exit ()函数的参数
			printf("wait_recycle: parent process ,child process exit code %d\n",WEXITSTATUS(status));
		}
		else
		{
			puts("wait_recycle: parent process, the child process exits unexpectedly");
		}
		
		for(int i=0;i<10;++i)
		{
			fputs("wait_recycle: parent process running\n",stdout);
			sleep(1);
		}

		puts("wait_recycle: parent process finish and exit");
		exit(15);
	}
}

/*（1）waitpid(-1,&status,0)和wait()没区别，阻塞等待子进程退出。
 *（2）waitpid(pid,&status,0)指定阻塞等待进程号为pid的子进程退出。
 *（3）waitpid(pid,&status,WNOHANG)回收进程号为pid的子进程，但是不阻塞。
 */
void waitpid_recycle()
{
	pid_t pid = fork();
	if(pid == -1)
	{
		printf("waitpid_recycle error: %s\n",strerror(errno));
		exit(-1);
	}
	else if(pid == 0)
	{
		fprintf(stdout,"waitpid_recycle: child process ,pid =%d ,ppid =%d\n",getpid(),getppid());
		sleep(2);
		
		fputs("waitpid_recycle: child process finish and exit\n",stdout);
		_exit(6);
	}
	else if(pid > 0)   //子进程先于父进程退出，但父进程中使用wait()回收子进程退出资源，所以子进程不会变为僵尸进程
	{
		printf("waitpid_recycle: parent process ,pid =%d ,spid =%d ,ppid =%d\n",getpid(),pid,getppid());
		printf("waitpid_recycle: parent process call wait() recycle child process ,spid =%d\n",pid);

		int count = 10;
		do
		{
			/*系统调用waitpid()和wait()的作用是完全相同的，但waitpid()多出了两个可由用户控制的参数pid和options，
			 *从而为我们编程提供了另一种更灵活的方式。
			 */
			int status;
			pid_t retpid = waitpid(pid,&status,WNOHANG);  //成功时返回终止的子进程ID（或0），失败时返回-1
			if(retpid == -1)  //没有子进程资源可以回收了，函数如果是阻塞的，阻塞会解除，直接返回-1。回收子进程资源的时候出现了异常也会返回-1。
			{
				fprintf(stdout,"waitpid_recycle: parent process ,recycle child process faild\n");
				break;
			}
			else if(retpid == 0)    //如果函数是非阻塞的，并且子进程还在运行，返回0
			{
				fputs("waitpid_recycle: parent process running\n",stdout);
				sleep(1);
			}
			else if(retpid == pid)   //waitpid()返回子进程pid，说明已经回收了子进程资源
			{
				fprintf(stdout,"waitpid_recycle: parent process capture child process exit ,retpid =%d\n",retpid);
				
				if(WIFEXITED(status))
				{
					fprintf(stdout,"waitpid_recycle: parent process ,child process exit code %d\n",WEXITSTATUS(status));
				}
				else
				{
					fputs("waitpid_recycle: parent process, the child process exits unexpectedly",stdout);
				}
			}
		}while(count--);

		puts("wait_recycle: parent process finish and exit");
		exit(16);
	}
}

void signal_ignore()
{
    //忽略子进程退出信号SIGCHLD，那么子进程结束后，内核会回收子进程，并不再给父进程发送信号。
    signal(SIGCHLD, SIG_IGN);
	
	pid_t pid = fork();
	if(pid == -1)
	{
		perror("signal_ignore error: ");
		_exit(-1);
	}
	else if(pid == 0)
	{
		fprintf(stdout,"signal_ignore: child process ,pid =%d ,ppid =%d\n",getpid(),getppid());
		sleep(2);
		
		fputs("signal_ignore: child process finish and exit\n",stdout);
		_exit(7);
	}
	else if(pid > 0)   //子进程先于父进程退出，且父进程中没有回收子进程退出资源，子进程就变为了僵尸进程
	{
		printf("signal_ignore: parent process ,pid =%d ,spid =%d ,ppid =%d\n",getpid(),pid,getppid());
		
		for(int i=0;i<10;++i)
		{
			fputs("signal_ignore: parent process running\n",stdout);
			sleep(1);
		}

		puts("signal_ignore: parent process finish and exit");
		exit(17);
	}
}

void signal_handle()
{
	//创建捕捉子进程退出信号只要子进程退出，触发SIGCHLD，自动调用recycle_process()
	signal(SIGCHLD,recycle_process);
	
	pid_t pid = fork();
	if(pid == -1)
	{
		perror("signal_handle error: ");
		_exit(-1);
	}
	else if(pid == 0)
	{
		fprintf(stdout,"signal_handle: child process ,pid =%d ,ppid =%d\n",getpid(),getppid());
		sleep(2);
		
		fputs("signal_handle: child process finish and exit\n",stdout);
		_exit(8);
	}
	else if(pid > 0)   //子进程先于父进程退出，且父进程中没有回收子进程退出资源，子进程就变为了僵尸进程
	{
		printf("signal_handle: parent process ,pid =%d ,spid =%d ,ppid =%d\n",getpid(),pid,getppid());
		
		for(int i=0;i<10;++i)
		{
			fputs("signal_handle: parent process running\n",stdout);
			sleep(1);
		}

		puts("signal_handle: parent process finish and exit");
		exit(18);
	}
}

void fork_twice()
{
	pid_t pid = fork();
	if(pid == -1)
	{
		perror("fork_twice 1 error: ");
		exit(-1);
	}
	else if(pid == 0)
	{
		puts("fork_twice: child process create grandchild process");
		
		pid = fork();    //子进程继续fork()创建孙进程
		if(pid == -1)
		{
			printf("fork_twice 2 error: %s\n",strerror(errno));
			_exit(-1);
		}
		else if(pid == 0)  //由孙进程完成真正任务执行。由于孙进程会变为孤儿进程，所以不用管孙进程退出后的资源回收问题。
		{
			fprintf(stdout,"fork_twice: grandchild process ,pid =%d ,ppid =%d\n",getpid(),getppid());
			sleep(2);
		
			fputs("fork_twice: grandchild process finish and exit\n",stdout);
			_exit(9);
		}
		else if(pid > 0)
		{
			/*子进程创建完孙进程以后立即退出，使子进程变为孤儿进程。因为孤儿进程会由init进程为其收尸，
			 *所以使用fork()两次的方法也可以避免僵尸进程的产生。
			 */
			const char* msg = "fork_twice: child process exits immediately\n";
			fwrite(msg,strlen(msg),1,stdout);
			fflush(stdout);     //fwrite()是全缓存的，所以要使打印立即输出到终端上，需要手动刷新缓冲区
			exit(0);
		}
	}
	else if(pid > 0)   //子进程先于父进程退出，且父进程中没有回收子进程退出资源，子进程就变为了僵尸进程
	{
		/*使用fork()两次防止僵尸进程产生的过程中，可以在主进程中使用wait()/waitpid()阻塞等待回收子进程，
		 *是因为我们明确知道子进程只是fork()完孙进程后，很快就退出，而不会执行很长一段时间。所以wait()或
		 *waitpid()也不会阻塞主进程很长时间。
		 */
		const char str[] = "fork_twice: parent process call waitpid() recycle child process\n";
		fwrite(str,strlen(str),1,stdout);
		fflush(stdout);
		waitpid(pid,NULL,0);   //因为明确知道子进程会很快退出，所以可以阻塞等待回收子进程。
		
		printf("fork_twice: parent process ,pid =%d ,spid =%d ,ppid =%d\n",getpid(),pid,getppid());
		for(int i=0;i<10;++i)
		{
			fputs("fork_twice: parent process running\n",stdout);
			sleep(1);
		}

		puts("fork_twice: parent process finish and exit");
		exit(19);
	}
}