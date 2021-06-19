/*进程是一个独立的资源分配单元，不同进程之间的资源是独立的，没有关联，不能在一个进程中直接访问另一个进程的资源。
 *但进程不是孤立的，不同进程需要进行信息的交互和状态的传递等，因此需要进程间通信(IPC：Inter Processes Communication)。
 */

/*1.进程间通信的目的：
 *（1）数据传输：一个进程需要将它的数据发送给另一个进程。
 *（2）通知事件：一个进程需要向另一个或一组进程发送消息，通知它们发生了某种事件。如子进程终止时要通知父进程。
 *（3）资源共享：多个进程之间共享同样的资源。为了做到这一点，需要内核提供互斥和同步机制。
 *（4）进程控制：有些进程希望完全控制另一个进程的执行（如Debug进程），此时控制进程希望能够拦截另一个进程的
 *     所有陷入和异常，并能够及时知道它的状态改变。
 */

/*2.Linux系统中进程间通信的6种方式：
 *（1）管道：包括无名管道（pipe）及命名管道（named pipe），无名管道可用于具有父进程和子进程之间的通信。
 *     命名管道克服了管道没有名字的限制，因此除具有管道所具有的功能外，它还允许无亲缘关系进程间的通信。
 *（2）消息队列（message）：进程可以向队列中添加消息，其它的进程则可以读取队列中的消息。
 *（3）信号（signal）：信号用于通知其它进程有某种事件发生。信号的应用场景非常多，主要用于进程的控制，
 *     如通知正在运行中的后台服务程序退出。
 *（4）共享内存（shared memory）：多个进程可以访问同一块内存空间。同一系统中进程之间采用共享内存交换数据的
 *     效率是最高的，但是共享内存没有加锁的机制，所以经常与信号灯结合一起来使用。在高性能的网络服务端程序中，
 *     可以用共享内存作为的数据缓存cache。
 *（5）信号量（semaphore）：也叫信号灯，用于进程之间对共享资源进行加锁。
 *（6）套接字（socket）：可用于不同计算机之间的进程通信。其完全可以代替只能在同一系统中进程之间通信的管道和消息队列。
 */

/*3.让程序在后台运行的2种方法：
 *（1）加“&”符号：如果想让程序在后台运行，执行程序的时候，命令的最后面加“&”符号，如./a.out &。
 *     在后台运行的程序，用Ctrl+c无法中断，并且就算终端退出了，程序仍在后台运行。如果终端退出了，
 *     后台运行的程序将由系统托管。
 *（2）采用fork：主程序执行fork，生成一个子进程，然后父进程退出，留下子进程继续运行，子进程将由系统托管。
 */

/*4.中止后台运行程序的2种方法：（程序在后台运行，离开了终端控制，用Ctrl+c上也无法中止）
 *（1）killall 程序名。
 *（2）先用“ps -ef | grep 程序名”找到程序的进程编号，然后用“kill 进程编号”。
 */

/*5.signal信号：（信号是进程控制的一部分）
 *（1）signal信号是进程之间相互传递消息的一种方法，信号全称为软中断信号，也称作软中断。它的实质和使用很象中断。
 *（2）软中断信号signal用来通知进程发生了事件。进程之间可以通过调用kill库函数发送软中断信号。Linux内核也可能给
 *     进程发送信号，通知进程发生了某个事件，如内存越界。注意信号只是用来通知某进程发生了什么事件，无法给进程
 *     传递任何数据。
 *（3）信号是在软件层次上对中断机制的一种模拟。在原理上一个进程收到一个信号与处理器收到一个中断请求可以说是一样的。
 *（4）信号是异步的，一个进程不必通过任何操作来等待信号的到达，事实上进程也不知道信号到底什么时候到达。
 *（5）信号可以直接进行用户空间进程和内核进程之间的交互，内核进程也可以利用它来通知用户空间进程发生了哪些系统事件。
 *     它可以在任何时候发给某一个进程，而无需知道该进程的状态。如果该信号当前并未处于执行态，则该信号由内核保存起来，
 *     直到该进程恢复执行再传递给它为止。如果一个信号被进程设置为阻塞，则该信号的传递被延迟，直到其阻塞被取消时才被
 *     传递给进程。
 *（6）信号是进程间通信机制中唯一的异步通信机制，可以看作是异步通知，通知接收信号的进程有哪些事件发生了。信号机制除了
 *     基本通知外，还可以传递附加信息。
 */

/*6.信号事件发生的来源：
 *（1）硬件来源：如我们按下了键盘上的按钮或者出现其他硬件故障；
 *（2）软件来源：最常用发送信号的系统函数有kill()、raise()、alarm()、setitimer()和sigqueue()等。
 *               软件来源还包括一些非法运算等操作。
 */
 
/*7.Linux中产生信号的常规操作：
 *（1）通过键盘操作产生信号：用户按下“Ctrl + c”这个快捷键会产生SIGINT信号，这个信号会杀死对应的某个进程。
 *（2）通过shell命令产生信号：通过“kill -9 进程PID”命令终止某一个进程会产生SIGKILL信号。
 *（3）通过函数调用产生信号：调用函数sleep()，进程会收到SIGSTOP信号，被迫挂起。
 *（4）通过对硬件进行非法访问产生信号：正在运行的程序访问了非法内存，发生段错误，进程退出。
 */

/*8.进程对信号的3种处理方法：
 *（1）SIG_IGN忽略信号：对信号不做任何处理，就像未发生过一样。但SIGKILL和SIGSTOP这两个信号不能被忽略，
 *     它们向超级用户提供了一种终止或停止进程的方法。
 *（2）捕捉信号：定义信号处理函数，当信号发生时，执行响应的处理函数。
 *（3）SIG_DFL执行默认动作：对该信号的处理采用系统的默认操作，大部分的信号的默认操作是终止进程。
 */

/*9.信号的生命周期：
 *一个完整的信号生命周期可以分为3个重要阶段，这3个阶段由4个重要事件来刻画的；信号产生、信号在进程中注册、
 *信号在进程中注销、执行信号处理函数。这里信号的产生、注册、注销是指信号的内部实现机制，而不是信号的函数实现。
 *因此信号是否注册与发送信号函数kill()及信号安装函数signal()无关，只与信号值有关。相邻两个事件的时间间隔构成
 *信号生命周期的一个阶段。信号处理有多种方式，一般是由内核完成的，当然也可以由用户进程来完成。信号的处理包括
 *信号的发送、捕捉和处理，它们有各自相对应的函数。
 */

/*10.信号处理相关函数：
 *（1）发送信号的函数: kill()、raise()。 
 *（2）捕捉信号的函数: alarm()、pause()。
 *（3）处理信号的函数: signal()、sigaction()。
 */

/*11.信号发送函数kill()、raise()和abort()：
 *（1）kill()函数同kill系统命令一样，可以发送信号给进程或进程组，实际上kill命令只是kill()函数的一个用户接口。
 *     kill()函数不仅可以通过发出SIGKILL信号终止进程，也可以向进程发送其他信号。raise()与kill()函数功能相似，
 *     但raise()函数只能向进程自身发送信号。
 *（2）kill()函数的用法：
 *  ①函数原型：int kill(pid_t pid, int sig)。
 *  ②功能：发送指定的信号到指定的进程，即给某一个进程发送一个信号。
 *  ③参数：pid - 进程ID，sig - 要发送的信号。
 *  ④举例：自己杀死自己 - kill(getpid(),9)。子进程杀死自己的父进程 - kill(getppid(),10)。
 *（3）raise()函数的用法：
 *  ①函数原型：int raise(int sig)。
 *  ②功能：给当前进程发送指定的信号，即给自己发送某一个信号。
 *  ③参数：sig - 给当前进程发送的信号。
 *（4）abort()函数的用法：
 *  ①函数原型：void abort()。
 *  ②功能：给当前进程发送一个固定信号SIGABRT。这是一个中断函数, 调用这个函数, 
 *          发送一个固定信号SIGABRT, 杀死当前进程。
 */

/*12.信号捕捉函数alarm()和pause()：
 *（1）alarm()也称为闹钟函数，它可以在进程中设置一个定时器，当定时器指定的时间到时，它就向进程发送SIGALARM信号。
 *     注意一个进程只能有一个闹钟时间，如果在调用alarm()之前已设置过闹钟时间，则任何以前的闹钟时间都被新值所代替。
 *（2）pause()函数用于将调用进程挂起直至捕捉到信号为止。通常可以用于判断信号是否已到。
 *（3）alarm()函数的用法：
 *  ①函数原型：unsigned int alarm(unsigned int seconds)。
 *  ②功能：alarm()函数只能进行单次定时，定时完成发射出一个信号。
 *  ③参数：倒计时seconds秒，倒计时完成发送一个信号SIGALRM，当前进程会收到这个信号。SIGALRM信号默认的处理动作是
 *          中断当前进程。
 *  ④返回值：大于0表示倒计时还剩多少秒，返回值为0表示倒计时完成，信号被发出。
 *（4）pause()函数的用法：
 *  ①函数原型：int pause()。
 *  ②功能：使调用进程挂起直至捕捉到一个信号。只有执行了一个信号处理函数后，挂起才结束。
 */

/*13.信号处理的2种主要方法：
 *（1）使用signal()函数。
 *（2）使用信号集函数组，再配合sigaction()函数。
 */

/*14.信号处理函数signal()和sigaction()：
 *（1）使用signal()函数处理时，只需指出要处理的信号和处理函数即可。它主要用于前32种非实时信号的处理，
 *     且不支持信号传递信息。Linux还支持一个更健壮、更新的信号处理函数sigaction()，推荐使用这个函数。
 *（2）signal()函数原型整体指向一个无返回值并且带一个整形参数的函数指针，也就是信号的原始配置函数。
 *     接着该原型又带有两个参数，其中第2个参数可以是用户自定义的信号处理函数的函数指针。
 *（3）使用signal()函数可以捕捉进程中产生的信号，并且修改捕捉到的信号函数行为。信号的自定义处理动作是一个回调函数，
 *     内核通过signal()得到这个回调函数的地址，在信号产生之后该函数会被内核调用。
 *（4）sigaction()函数和signal()函数的功能是一样的，用于捕捉进程中产生的信号，并将用户自定义的信号行为函数（回调函数）
 *     注册给内核，内核在信号产生之后调用这个处理动作。sigaction()可以看做是signal()函数是加强版，函数参数更多更复杂，
 *     函数功能也更强一些。
 *（5）sigaction()函数中第2个和第3个参数需要用到sigaction结构体，以指定对信号集的处理。
 *（6）signal()函数的用法：
 *  ①函数原型：typedef void (*sighandler_t)(int)。
 *              sighandler_t signal(int signum, sighandler_t handler);。
 *  ②功能：程序中什么时候产生信号是不清楚的，因此不能在信号产生之后再去处理。在信号产生之前，提供一个注册函数， 
 *          用来捕捉信号。假设将来这个信号产生了，就委托内核进行捕捉，并取消执行信号的默认动作。而执行什么样的
 *          处理动作在signal函数中指定。如果这个信号不产生，回调函数永远不会被调用。
 *  ③signum参数：需要捕捉的信号。
 *  ④handler参数：信号捕捉到之后的处理动作，是一个函数指针。这个回调函数是需要程序员写的，但是程序员不调用，
 *                 由内核调用。内核调用回调函数的时候，会给它传递一个实参，该实参的值就是捕捉的那个信号值。
 *（7）sigaction()函数的用法：
 *  ①函数原型：int sigaction(int signum, const struct sigaction *act, struct sigaction *oldact)。
 *  ②功能：检查或修改与指定信号相关联的处理动作。
 *  ③signum参数：要捕捉的信号。
 *  ④act参数：捕捉到信号之后的处理动作。
 *  ⑤oldact参数：上一次调用该函数进行信号捕捉设置的信号处理动作，该参数一般指定为NULL。
 *  ⑥返回值：函数调用成功返回0，失败返回-1。
 */

/*15.siaction结构体的定义：
 * struct sigaction {
 *     void     (*sa_handler)(int signum);                                    //旧的信号处理函数指针。
 *     void     (*sa_sigaction)(int signum, siginfo_t *info, void *context);  //新的信号处理函数指针。
 *     sigset_t  sa_mask;                                                     //信号阻塞集。初始化为空即可, 处理函数执行期间不屏蔽任何信号。
 *     int       sa_flags;	                                                  //信号处理的方式。
 *     void     (*sa_restorer)(void);                                         //不用
 * };
 *
 *（1）sa_handler：是一个函数指针，指定信号处理函数。除了可以使用自定义的处理函数外，还可以为SIG_DFL默认处理方式
 *                 或SIG_IGN忽略信号。它的处理函数只有一个参数，即信号值。
 *（2）sa_sigaction: 是一个函数指针，指向的函数就是捕捉到的信号的处理动作。
 *（2）sa_mask：是一个信号集，它可以指定在信号处理程序执行过程中哪些信号应当被屏蔽。在调用信号捕获函数前，
 *              该信号集要加入到信号的信号屏蔽集中。
 *（3）sa_flags：中包含了很多标志位，是对信号进行处理的各个选择项。
 */

#include <unistd.h>       //fork(),pause(),sleep(),alarm(),getpid()
#include <signal.h>       //kill(),signal(),raise()
#include <sys/types.h>    //pid_t,ssize_t
#include <sys/wait.h>     //wait(),waitpid()
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define _CHANGE_WAY_
#undef _CHANGE_WAY_

static void handle(int signo);
static void safeexit(int signo);
static void mysleep(int second);

static void pause_test();
static void raise_test();
static void kill_test1();
static void kill_test2();
static void alarm_test1();
static void alarm_test2();
static void mysleep_test();

int main(int argc,char* argv[])
{
	// pause_test();
	// raise_test();
	// kill_test1();
	// kill_test2();
	// alarm_test1();
	alarm_test2();
	// mysleep_test();
	
	return 0;
}

void handle(int signo)
{
	printf("handle: deal with signal ,signo =%d\n",signo);
}

/*服务程序运行在后台，如果想中止它，强行杀掉不是个好办法。因为程序被杀的时候，程序突然死亡，
 *没有释放资源，会影响系统的稳定。用Ctrl+c中止与杀程序是相同的效果。如果能向后台程序发送一个信号，
 *后台程序收到这个信号后，调用一个函数，在函数中释放资源，程序就可以有计划的退出，安全而体面。
 */
void safeexit(int signo)
{
	fflush(stdout);
	
	if(signo == SIGINT)
	{
		printf("\nSIGINT: ctrl + c\n");
	}
	else if(signo == SIGQUIT)
	{
		puts("\nSIGQUIT: ctrl + \\");
	}
	else if(signo == SIGTERM)
	{
		fputs("\nSIGTERM: kill + pid\n",stdout);
	}
	
	printf("process safe exit ,signo =%d\n",signo);
	exit(5);
}

//调用系统调用的进程将处于阻塞状态，直到有信号递达将其唤醒。
void mysleep(int second)
{
	/*处理定时器超时信号SIGALRM。如果程序中没有及时处理定时器超时信号，
	 *那么当SIGALRM信号到来时，它的默认行为是终止进程，软件退出。
	 */
	signal(SIGALRM,handle);    //修改SIGALRM信号的默认行为，以避免信号到来时终止进程。
	alarm(second);
	
	//没有产生信号前，进程一直阻塞在pause()不会往下执行。假如我们按“Ctrl+c”，pause()会捕获到SIGTERM信号，中断当前进程。
	pause();
}

//pause()函数只有一个返回值，只有成功返回且为-1，同时errno的值置为EINTR。
void pause_test()
{
#ifndef _CHANGE_WAY_
    //如果没有为SIGUSE1信号指定处理方式，那么它的默认动作为杀死进程。
	signal(SIGUSR1,handle);   //使用kill -SIGUSE1 进程号，可以使pause()的进程被唤醒继续执行。
#endif

	fprintf(stdout,"pause_test: pause before ,pid =%d\n",getpid());
	
	/*只有当一个信号递达且处理方式为被捕捉时，pause()函数引起挂起操作的进程才会被唤醒，
	 *而且只有当信号处理完后（调用完用户处理函数），pause函数才返回-1，且errno置EINTR，
	 *进程被唤醒继续执行后面的程序。
	 */
	pause();   //pause()收到的信号不能被屏蔽，如果被屏蔽，那么它就不能被唤醒。
	
	/*如果信号的处理方式为默认处理方式或忽略，那么pause()函数不会返回值。当信号的默认动作是终止进程，
	 *那么进程将立即退出，不再执行pause()后的语句。如果信号被丢弃，那么进程不会被激活，而是一直阻塞。
	 */
	for(int i=0;i<10;++i)
	{
		puts("pause_test: do some work");
		sleep(1);
	}
	
	printf("pause_test: pause after ,pid =%d\n",getpid());
}

void raise_test()
{
	fprintf(stdout,"raise_test: raise(SIGSTOP) before ,pid =%d\n",getpid());
	
	//调用raise()函数，使进程向自身发送SIGSTOP信号，以阻塞进程，使进程主动放弃cpu。
	raise(SIGSTOP);    //终端中使用kill -SIGCONT 进程号，可以是SIGSTOP信号阻塞的进程被唤醒，继续执行。
	for(int i=0;i<10;++i)
	{
		puts("raise_test: do some work");
		sleep(1);
	}
	
	printf("raise_test: raise(SIGSTOP) after ,pid =%d\n",getpid());
}

void kill_test1()
{
	pid_t pid = fork();
	if(pid == -1)
	{
		perror("kill_test1 error: ");
		_exit(-1);
	}
	else if(pid == 0)
	{
		fprintf(stdout,"kill_test1: child process ,pid =%d ,ppid =%d\n",getpid(),getppid());
		puts("kill_test1: child process stop runing and wait signal");
		
		raise(SIGSTOP);  //子进程中使用raise()函数向自身发送SIGSTOP信号，使子进程暂停。
		for(int i=0;i<5;++i)
		{
			printf("kill_test1: child process do some work ,i =%d\n",i);
			sleep(1);
		}
		
		fputs("kill_test1: child process run finished and exit\n",stdout);
		exit(3);
	}
	else if(pid > 0)
	{
		fprintf(stdout,"kill_test1: parent process ,pid =%d ,spid =%d ,ppid =%d\n",getpid(),pid,getppid());
		
		sleep(2);  //让父进程休眠，使子进程先执行。
		puts("kill_test1: inter process communicate");
		
#ifndef _CHANGE_WAY_
		if(kill(pid,SIGKILL) == 0)  //调用kill()函数向子进程发送SIGKILL信号，杀死子进程。
		{
			fputs("kill_test1: kill child process successfully\n",stdout);
		}
		else
		{
			puts("kill_test1: kill child process failed\n");
		}
#else
		if(kill(pid,SIGCONT) == 0)  //调用kill()函数向子进程发送SIGCONT信号，使子进程继续执行。
		{
			fputs("kill_test1: make child process to run successfully\n",stdout);
		}
		else
		{
			puts("kill_test1: make child process to run failed\n");
		}
#endif
		int count = 10;
		do{
			int status;
			pid_t retpid = waitpid(pid,&status,WNOHANG);  //使用waitpid()轮询，回收子进程的退出资源，防止僵尸进程的产生
			if(retpid == -1)    //若没有子进程可以回收了或回收子进程过程中出错，waipid()返回-1。
			{
				puts("kill_test1: don't have child process");
				break;
			}
			else if(retpid == 0)  //若子进程还在执行中，waipid()返回0。
			{
				const char* str = "kill_test: child process is running\n";
				fwrite(str,strlen(str),1,stdout);
				
				str = "kill_test1: parent process do some work\n";
				write(STDOUT_FILENO,str,strlen(str));
				
				sleep(1);
			}
			else if(retpid == pid)  //若回收到子进程，waipid()返回子进程pid。
			{
				fputs("kill_test1: parent process capture child process exit\n",stdout);
				
				if(WIFEXITED(status))  //判断子进程是否正常退出。WIFEXITED()进程是正常退出的返回1。
				{
					//WEXITSTATUS()得到进程退出时候的状态码
					printf("kill_test1: child process exit normally ,exit code =%d\n",WEXITSTATUS(status));
				}
				
				if(WIFSIGNALED(status))  //判断子进程是否被信号杀死。WIFSIGNALED()进程是被信号杀死了返回1。
				{
					//WTERMSIG()获得进程是被哪个信号杀死的，会得到信号的编号。
					printf("kill_test1: child process exit by signal ,signal number =%d\n",WTERMSIG(status));
				}
				
				break;
			}
		}while(count--);
		
		fputs("kill_test1: parent process run finished and exit",stdout);
		exit(6);
	}
}

/*（1）程序一般只需要关注SIGINT、SIGTERM和SIGKILL这三个信号。
 *（2）在运行中的进程，如果按Ctrl+c，将向程序发出SIGINT信号，信号编号是2。
 *（3）采用“kill 进程编号”或“killall 程序名”向程序发出的是SIGTERM信号，信号编号是15。
 *（4）采用“kill -9 进程编号”向程序发出的是SIGKILL信号，信号编号是9。SIGKILL信号不能被忽略，
 *     也无法捕获，程序将突然死亡。所以程序只要设置SIGINT和SIGTERM两个信号的处理函数就可以了，
 *     这两个信号可以使用同一个处理函数释放资源。
 */
void kill_test2()
{
	printf("kill_test2 error: start ,pid =%d\n",getpid());
	
	//屏蔽全部的信号，不希望程序被干扰
	for(int i=1;i<=64;++i) signal(i,SIG_IGN);
	
	//重新设置关心的信号
	signal(SIGINT,safeexit);     //ctrl + c
	signal(SIGQUIT,safeexit);    //ctrl + '\'
	signal(SIGTERM,safeexit);    //kill + 进程号，即kill默认发出的信号就是SIGTERM
	
	printf("kill_test2: process is runing");  //printf是带行缓存的，没有加'\n'，打印信息不会立即输出。
	while(1) sleep(2);   //程序陷入死循环
}

void alarm_test1()
{
	fprintf(stdout,"alarm_test1: alarm before ,pid =%d\n",getpid());

	alarm(5);   //alarm()函数不会引起进程阻塞，而sleep()函数会阻塞调用进程。
	fputs("alarm_test1: continue to run\n",stdout);
	
#ifndef _CHANGE_WAY_
    /*阻塞进程，等待定时器信号SIGALRM。因为没有指定SIGALRM信号的处理方式，所以即使pause()函数等到了
	 *SIGALRM信号的到来，进程也不会继续往下执行了，而是会执行SIGALRM信号的默认动作，终止进程。
	 */
	pause();
#endif

	for(int i=0;i<10;++i)
	{
		puts("alarm_test1: do some work");
		sleep(1);    //运行了5s以后，当定时器信号SIGALRM到来，进程就会被终止。
	}

	printf("alarm_test1: alarm after ,pid =%d\n",getpid());  //进程运行5s后就会被杀死，而执行不到这一条语句
}

/*（1）直接通过终端输出：time ./signal.out
 *  real	0m1.009s      //实际数数用的总时间
 *  user	0m0.046s      //用户区代码使用的时间
 *  sys	    0m0.691s      //内核区使用的时间
 *  real = user + sys + 消耗的时间(频率的从用户区到内核区进程切换)
 *  
 *（2）不直接写终端, 将数据重定向到磁盘文件中：time ./signal.out > test.txt
 *  real	0m1.034s      //用户实际数数的时间变长了
 *  user	0m0.000s
 *  sys	    0m0.229s
 */

/*文件IO操作需要进行用户区到内核区的切换，处理方式不同，二者之间切换的频率也不同。
 *也就是说对文件IO操作进行优化是可以提供程序的执行效率的。
 */
void alarm_test2()
{
	printf("alarm_test2: alarm before ,pid =%d\n",getpid());
	
	alarm(1);    //使用alarm()定时器函数，检查计算机1s之内可以输出多少数
	
	int i = 0;
	while(1)
	{
		printf("%d\n",++i);
	}
	
	fprintf(stdout,"alarm_test2: alarm before ,pid =%d\n",getpid());
}

void mysleep_test()
{
	printf("mysleep_test: start ,pid =%d\n",getpid());
	
	puts("mysleep_test: do some work");
	mysleep(5);
	
	fprintf(stdout,"mysleep_test: end ,pid =%d\n",getpid());
}