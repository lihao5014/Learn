/*1.任务、进程和线程之间的关系：
 *（1）任务是一个逻辑概念,指由一个软件完成的任务，或者是一系列共同达到某一目的的操作。
 *     通常一个任务是一个程序的一次执行，一个任务包含一个或多个完成独立功能的子任务，
 *	   这个独立的子任务就是进程或线程。
 *（2）进程是指一个具有独立功能的程序在某个数据集上的一次动态执行过程，它是系统进行资源
 *     分配和调度的最小单元。进程是一个独立的可调度的任务，是一个抽象实体。当系统在执行
 *     某个程序时，会以进程为单位分配和释放的各种资源。
 *（3）线程是进程内独立的一条运行路线，是处理器调度的最小单元，也可以成为轻量级进程。
 *（4）通常一个任务是一个程序的一次执行，一个任务包含一个或多个完成独立功能的子任务，
 *     这个独立的子任务就是进程或线程。一个进程可以拥有多个线程，每个线程必须有一个父进程。   
 */
 
/*2.多任务机制的实现：
 *（1）多任务处理是指可以同一时间内运行多个应用程序，每个应用程序被称作一个任务。Linux就是一个支持多任务
 *     的操作系统，比起单任务系统它的功能增强了许多。
 *（2）多任务操作系统使用某种调度策略支持多个任务的并发执行。事实上单核处理器在某一时刻只能执行一个任务。
 *     每个任务创建时被分配时间片（几十到上百毫秒），任务执行（占用CPU）时，时间片递减。操作系统会在当前
 *     任务的时间片用完时调度执行其他的任务，由于任务会频繁的切换执行，且分配的时间片都是几十到上百毫秒，
 *     因此给用户多个任务同时运行的错觉。多任务操作系统中通常有三个概念：任务、进程和线程。
 *（4）多个程序交替执行的方法，就是CPU管理多个进程的基本思想。对于一个支持多进程的系统，CPU会从一个进程快速
 *     切换至另一个进程，其间每个进程各运行几十或几百个毫秒。虽然单核的CPU在某一个瞬间，只能运行一个进程。
 *     但在1秒钟期间，它可能会运行多个进程，这样就产生并行的错觉，实际上这是并发。
 *（5）CPU可以从一个进程切换到另外一个进程，在切换前必须要记录当前进程中运行的状态信息，以备下次切换回来的
 *     时候可以恢复执行。
 */

/*3.进程的概念：
 *（1）我们编写的代码只是一个存储在硬盘的静态文件，通过编译后就会生成二进制可执行文件，当我们运行这个可执行文件后，
 *     它会被装载到内存中，接着CPU会执行程序中的每一条指令，那么这个运行中的程序，就被称为进程。
 *（2）在Linux操作系统是通过进程去完成一个一个的任务，进程是管理事务的基本单元。进程拥有自己独立的处理环境和系统资源。
 *（3）进程是指一个具有独立功能的程序在某个数据集合上的一次动态执行过程，它是操作系统进行资源分配和调度的基本单位。
 *     一个任务的运行可以激活若干个进程，这些进程来互相合作完成该任务的功能。　
 *（4）进程不仅包括程序的指令和数据，而且包括程序计数器值、CPU的所有寄存器值以及存储临时数据的进程堆栈。
 *（5）因为Linux是一个多任务的操作系统，所以其它的进程必须等到操作系统将处理器使用权分配给自己之后才能运行。
 *     当正在运行的进程需要等待其它的系统资源时，Linux内核将取得处理器的控制权，按照某种调度算法将处理器分配
 *     给某个正在等待执行的进程。
 *（6）内核将所有进程存放在双向循环链表（进程链表）中，链表的每一项都是task_struct，称为进程控制块的结构。
 *     该结构包含了与一个进程相关的所有信息，在<include/Linux/sched.h>文件中定义。task_struct内核结构比较大，
 *     它能完整的描述一个进程，如进程的状态、进程的基本信息、进程标识符、内存相关信息、父进程相关信息、与进程
 *     相关的终端信息、当前工作目录、打开的文件信息、所接收的信号信息等。
 *（7）进程间靠优先级获得CPU资源，时间片段轮换来更新优先级，以保证不会一个进程占据CPU时间过长。每个进程都得到轮换运行，
 *     因为这个时间非常短，所以给我们就好像是系统在同时运行好多进程。
 */

/*4.进程的主要特征：
 *（1）并发性：指的是系统中多个进程可以同时并发执行，相互之间互不受干扰。
 *（2）动态性：指的是进程具有完整的生命周期，而且在进程的生命周期内，进程的状态是不断变化的，
 *     另外进程具有动态的地址空间（包括代码、数据和进程控制块等）。
 *（3）交互性：指的是进程在执行过程中可能会与其他进程发生直接或间接的通信（IPC），如进程同步或进程互斥等，
 *     需要为此添加一定的进程处理机制。
 *（4）独立性：指的是进程是一个相对完整的资源分配和调度的基本单位，各个进程的地址空间是相互独立的，
 *     因此只有采取某些特定的通信机制才能实现进程之间的通信。
 *（5）Linux系统是一个多进程的系统，它的进程之间具有并行性、互不干扰等特点。每个进程都是一个独立的运行单位，
 *     拥有各自的权利和责任。其中各个进程都运行在独立的虚拟地址空间，因此即使一个进程发生异常，它也不会影响
 *     到系统中的其他进程。
 */

/*4.程序和进程的比较：
 *（1）我们平时写的C语言代码，通过编译器编译，最终它会成为一个可执行程序，当这个可执行程序运行起来后，
 *     它就成为了一个进程。程序是存放在存储介质上的一个可执行文件，而进程是程序执行的过程。进程的状态
 *     是变化的，其包括进程的创建、调度和消亡。程序是静态的，进程是动态的。
 *（2）程序是一段静态的代码，是保存在非易失性存储器上的指令和数据的有序集合，没有任何执行的概念。
 *     进程是一个动态的概念，它是程序的一次执行过程，进程具有生命周期，包括了动态创建、调度、执行
 *     和消亡的整个过程，它是程序执行和资源管理的最小单位。
 *（3）从操作系统的角度来看，进程是程序执行时相关资源的总称。当进程结束时所有资源被操作系统自动回收。
 *（4）通过多次执行，一个程序可对应多个进程；通过调用关系，一个进程可包括多个程序。
 */

/*5.Linux系统中进程的主要类型：
 *（1）交互式进程：这类进程经常与用户进行交互，需要等待用户的输入（键盘和鼠标操作等）。当接收到用户
 *     的输入之后，这类进程能够立刻响应。交互式进程可以在前台运行也可以在后台运行。典型的交互式进程
 *     有shell命令进程、vim文本编辑器、图形应用程序运行等。
 *（2）批处理进程：这类进程不必与用户进行交互，它不属于某个终端，它被提交到一个队列中以便顺序执行。
 *     因此通常在后台运行。因为这类进程不必很快的响应，因此往往不会优先调度。典型的批处理器是编译器
 *     的编译操作、数据库搜索引擎等。
 *（3）守护进程（精灵进程、后退进程、Daemon进程）：这类进程一直在后台运行，和任何终端都无关联。
 *     一般在系统启动时开始执行，系统关闭时结束。很多系统进程（各种服务）都是以守护进程的形式存在。
 *     在Linux中init是0号进程，它是所有进程的父进程。
 */

/*3.进程状态：（进程都有着[运行-暂停-运行]的活动规律）
 *（1）一个进程并不是自始至终连续不停地运行的，它与并发执行中的其他进程的执行是相互制约的。它有时处于运行状态，
 *     有时又由于某种原因而暂停运行处于等待状态，当使它暂停的原因消失后，它又进入准备运行状态。所以在一个进程的
 *     活动期间至少具备三种基本状态，即运行状态、就绪状态、阻塞状态。
 *（2）创建状态New：进程正在被创建时的状态。
 *（3）就绪状态Ready：可运行，但因为其他进程正在运行而暂停停止。
 *（4）运行状态Runing：该时刻进程占用 CPU。
 *（5）阻塞状态Blocked：该进程正在等待某一事件发生而暂时停止运行，这时即使给它CPU控制权，它也无法运行。
 *（6）挂起状态Hang：它表示进程没有占有物理内存空间。这跟阻塞状态是不一样，阻塞状态是等待某个事件的返回。
 *     挂起状态又可以分为两种：阻塞挂起状态和就绪挂起状态。
 *  ① 阻塞挂起状态：进程在外存（硬盘），并等待某个事件的出现。
 *  ② 就绪挂起状态：进程在外存（硬盘），但只要进入内存，即刻立刻运行。
 *（7）结束状态Exit：进程正在从系统中消失时的状态。
 */
 
/*4.进程状态迁移：
 *（1）NULL -> 创建状态：一个新进程被创建时的第一个状态。
 *（2）创建状态 -> 就绪状态：当进程被创建完成并初始化后，一切就绪准备运行时，变为就绪状态，这个过程是很快的。
 *（3）就绪状态 -> 运行状态：处于就绪状态的进程被操作系统的进程调度器选中后，就分配给CPU正式运行该进程。
 *（4）运行状态 -> 结束状态：当进程已经运行完成或出错时，会被操作系统作结束状态处理。
 *（5）运行状态 -> 就绪状态：处于运行状态的进程在运行过程中，由于分配给它的运行时间片用完，操作系统会把该进程
 *     变为就绪态，接着从就绪态选中另外一个进程运行。
 *（6）运行状态 -> 阻塞状态：当进程请求某个事件且必须等待时，例如请求I/O事件。
 *（7）阻塞状态 -> 就绪状态：当进程要等待的事件完成时，它从阻塞状态变到就绪状态。
 *（8）就绪态/阻塞态 -> 挂起状态：由于虚拟内存管理原因，进程的所使用的空间可能并没有映射到物理内存，而是在硬盘上，
 *     这时进程就会出现挂起状态，另外调用sleep()也会被挂起。
 */

#include <fcntl.h>       //creat(),open()
#include <unistd.h>      //read(),write(),sleep(),frok(),_exit()
#include <sys/types.h>   //pid_t,ssize_t
#include <sys/wait.h>    //wait(),waitpid()
#include <stdio.h>       //perror()
#include <stdlib.h>      //exit();
#include <string.h>      //strerror()
#include <errno.h>       //errno全局变量

typedef void (*pFun)();

typedef struct Message_t
{
	char signal[16];
	pFun handle;
}Message;

static void writeFile(int fb);
static void readFile(int fb);

static void status_test();
static void zombie_test();
static void orphan_test();

//status_test()必须在使用前声明，所以static void status_test()必须放置在Message message_map定义前
static const Message message_map[] = {
	{"status",status_test},
	{"zombie",zombie_test},
	{"orphan",orphan_test}
};


/*终端执行./status.out时主进程被创建。此时刚被创建的主进程处于创建状态。
 *进程的创建状态维持时间很短，随即马上进入就绪状态，等待被CPU调度。
 */
int main(int argc,char* argv[])  //主进程进入main函数时，就说明主进程由就绪态切换到了运行态。
{
	if(argc != 2)
	{
		puts("usage: ./status.out status/zombie/orphan");
		exit(-1);
	}
	
	for(int i=0;i<sizeof(message_map)/sizeof(Message);++i)
	{
		if(strcmp(argv[1],message_map[i].signal) == 0)
		{
			message_map[i].handle();
			break;
		}
	}
	
	return 0;    //调用return语句退出主进程后，主进程将由运行态转换到退出态。
}

void writeFile(int fb)
{
	write(fb,"hello world\n",strlen("hello world\n"));    //调用read/write系统调用，进程将由用户态进入到内核态
	write(fb,"time is 2021.05.31\n",strlen("time is 2021.05.31\n"));
	
	const char* str = "test process status\n";
	write(fb,str,strlen(str));
}

void readFile(int fb)
{
	lseek(fb,0,SEEK_SET);   //调用lseek系统调用，进程将由用户态进入到内核态
	
	int size = 0;
	char buf[128] = {0};
	while((size = read(fb,buf,sizeof(buf))) > 0)
	{
		write(STDOUT_FILENO,buf,size);
		memset(buf,0,sizeof(buf));
	}
}

/*子进程可以继承父进程中创建的文件描述符。即子进程中拷贝出来的文件描述符
 *与父进程中的文件描述符都会指向同一个文件。
 */
void status_test()
{
	int fb = open("file/status_test.txt",O_RDWR | O_CREAT | O_TRUNC,S_IRWXU | S_IRWXG | S_IROTH | S_IWOTH);
	if(fb == -1)
	{
		perror("status_test error: ");
		exit(-1);
	}
	
	pid_t pid = fork();  //子进程在调用fork时被创建，刚创建的子进程处于创建态，随即马上进入就绪态，等待被CPU执行。
	if(pid == -1)        //子进程执行这一条if语句时，就说明了子进程已经由就绪态转换到了运行态。
	{
		printf("status_test error: %s\n",strerror(errno));   //printf加了'\n'换行符，所以会刷新行缓冲
		_exit(-1);     //_exit()退出进程时不会自动刷新缓冲区
	}
	else if(pid == 0)  //父子进程在执行每一条语句的过程中，都有可能因为CPU被抢占或时间片运行完，而从运行态切换到就绪态。
	{
		//子进程可能在执行fprintf或fputs语句过程中，由执行态切换为就绪态或者由就绪态切换为运行态。
		fprintf(stdout,"status_test: child process ,pid =%d,ppid =%d\n",getpid(),getppid());
		fputs("status_test: child process ,write text to status_test.txt\n",stdout);
		
		writeFile(fb);
		fputs("status_test: child process, run finished and exit\n",stdout);
		exit(5);   //调用exit()退出后，子进程就进入退出态
	}
	else if(pid > 0)  //对于单CPU，父进程处于运行态，那么它的子进程就一定不是运行态。子进程可能处于就绪态、阻塞态、退出态或挂起态。
	{
		//父进程可能在执行printf或puts语句过程中，由执行态切换为就绪态或者由就绪态切换为运行态。
		printf("status_test: parent process ,pid =%d ,spid =%d ,ppid =%d\n",getpid(),pid,getppid());
		puts("status_test: parent process ,read content from status_test.txt");
		
		//调用sleep()休眠以后，父进程进入阻塞状态。当休眠结束后，父进程再由阻塞状态变为就绪态。
		sleep(2);   //延时2s读取，以便子进程先将数据写入文件中。
		readFile(fb);   //处于就绪态的进程获取到CPU时间片，就会马上切换为运行态。
		int status;
		
		//当使用阻塞方式调用waitpid()时，父进程将变为阻塞态，直到子进程发出退出信号将其唤醒，才由阻塞态变为就绪态。
		int retpid = waitpid(-1,&status,0);
		if(retpid == -1)
		{
			puts("status_test error: parent process ,recycle child process failed\n");
		}
		
		//WIFEXITED()宏用来指出子进程是否为正常退出的，如果是它会返回一个非零值。
		if(WIFEXITED(status))
		{
			/*当WIFEXITED()返回非零值时，我们可以用WEXITSTATUS()宏来提取子进程的返回值。
			 *如果进程不是正常退出的，也就是说WIFEXITED返回0，WEXITSTATUS()的值就毫无意义。
			 */
			printf("status_test: parent process ,child process exits normally - %d\n",WEXITSTATUS(status));
		}
		else
		{
			puts("status_test: parent process ,child process exits unexpectedly");
		}
		
		//进程中的所有语句都是在运行状态下被执行的。且进程在执行每一条语句的过程中都有可能发生状态切换。
		close(fb);
		puts("status_test: parent process ,run finished and exit");
	}
}

//父进程中没有调用wait()/waitpid()或处理子进程退出SIGCHLD信号，那么子进程结束后就将变为僵尸进程。
void zombie_test()
{
	pid_t pid = fork();
	if(pid == -1)
	{
		perror("zombie_test error: ");
		exit(-1);
	}
	else if(pid == 0)
	{
		fprintf(stdout,"zombie_test: child process ,pid =%d ,ppid =%d\n",getpid(),getppid());
		fputs("zombie_test: child process exit and will be zombie process\n",stdout);
		_exit(0);   //子进程只要执行完毕，就会变为僵尸态。与调不调用exit()/_exit()函数退出无关。
	}
	else if(pid > 0)
	{
		printf("zombie_test: parent process ,pid =%d,spid =%d,ppid =%d\n",getpid(),pid,getppid());
		puts("zombie_test: parent process is always running");
		while(1);   //使父进程一直运行，不退出。从而使子进程退出后遗留下的资源得不到回收，子进程变为僵尸进程。
	}
}

//如果使用./status.out &命令将程序运行在后台。由于子进程是一个死循环，所以需要使用kill -9 （进程号）的方式来结束子进程
void orphan_test()
{
	pid_t pid = fork();
	if(pid == -1)
	{
		printf("orphan_test error: %s\n",strerror(errno));
		_exit(-1);
	}
	else if(pid == 0)
	{
		fprintf(stdout,"orphan_test: child process ,pid =%d ,ppid =%d\n",getpid(),getppid());
		fputs("orphan_test: child process is always running",stdout);
		while(1);   //使子进程一直运行，不退出。由于父进程执行完毕先退出，而子进程一直运行，那么子进程就将变为孤儿进程。
	}
	else if(pid > 0)
	{
		printf("orphan_test: parent process ,pid =%d,spid =%d,ppid =%d\n",getpid(),pid,getppid());
	}
	
	if(pid == 0)
	{
		fputs("orphan_test: child process exit\n",stdout);
	}
	else
	{
		puts("orphan_test: parent process exit and will be zombie process");
	}
}