/*1.并发和并行的区别：
 *（1）并发的同时运行是一个假象。CPU在某一个时间点只能为某一个个体来服务，因此不可能同时处理多任务，
 *     并发看上去就像多个进程同时运行，其实是通过计算机的CPU快速的时间片切换实现的。
 *（2）并发是针对某一个硬件资源而言的，在某个时间段之内处理的任务的总量，量越大效率越高。
 *（3）并行的多进程同时运行是真实存在的，可以在同一时刻同时运行多个进程
 *（4）并行需要依赖多个CPU硬件资源，单个CPU是无法实现的。
 */

/*2.单个CPU并行处理多任务的实现原理：（通过时间片轮询调度策略实现多任务）
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
 *     子进程还在运行，这时候这个子进程就可以被称之为孤儿进程。
 *（4）僵尸进程：在一个启动的进程中创建子进程，这时候就有了父子两个进程。如果父进程正常运行，子进程先于父进程结束，
 *     子进程无法释放自己的PCB资源，需要父进程来做这个件事儿，但是如果父进程也不管，这时候子进程就变成了僵尸进程。
 */

/*6.进程的三种基本状态：
 *（1）进程是有状态的，同时状态是可以相互进行转换的，从执行的状态转换为不执行的状态。我们可以把进程运行的整个
 *     生命周期简单划分为三种状态（实际上不指这三种状态）：就绪态、执行态、等待态。
 *（2）就绪态：进程已经具备执行的一切条件，正在等待分配 CPU 的处理时间。
 *（3）执行态：该进程正在占用CPU运行。
 *（4）等待态：进程因不具备某些执行条件而暂时无法继续执行的状态。虽然就绪态和等待态都是不执行，但它们是有区别的，
 *     就绪态是指满足条件，时间没到，等待态是不满足条件。
 */
 
/*7.进程号：
 *（1）进程号PID：每个进程都由一个进程号来标识，其类型为无符号整型pid_t，进程号的范围0～32767。
 *     进程号总是唯一的，但进程号可以重用。当一个进程终止后，其进程号就可以再次使用。
 *（2）父进程号PPID：任何进程都是由另一个进程创建，该进程称为被创建进程的父进程，对应的进程号称为父进程号。
 *（3）进程组号PGID：进程组是一个或多个进程的集合。他们之间相互关联，进程组可以接收同一终端的各种信号，
 *     关联的进程有一个进程组号。默认的情况下，当前的进程号会当做当前的进程组号。
 *（4）Linux操作系统提供了三个获得进程号的函数：getpid()、getppid()、getpgid()。
 */

/*8.Linux进程树结构模型：
 * 系统允许一个进程创建新进程，新进程即为子进程，子进程还可以创建新的子进程，形成进程树结构模型。
 * 整个Linux系统的所有进程也是一个树形结构。树根是系统自动构造的，即在内核态下执行的0号进程，
 * 它是所有进程的祖先。进程号为0的进程通常是调度进程，常被称为swapper交换进程。由0号进程创建1号进程，
 * 1号进程负责执行内核的部分初始化工作及进行系统配置，并创建若干个用于高速缓存和虚拟主存管理的内核线程。
 * 随后1号进程调用execve()运行可执行程序init，并演变成用户态1号进程，即init进程。所以在Linux下面所有的
 * 进程都由init进程直接或者间接创建。
 */

/*9.进程互斥：
 * 是指当有若干进程都要使用某一共享资源时，任何时刻最多允许一个进程使用，其他要使用该资源的进程必须等待，
 * 直到占用该资源者释放了该资源为止。操作系统中将一次只允许一个进程访问的资源称为临界资源。多个进程因竞争资源
 * 而形成一种僵局，若无外力作用，这些进程都将永远不能再向前推进。进程中访问临界资源的那段程序代码称为临界区，
 * 为实现对临界资源的互斥访问，应保证诸进程互斥地进入各自的临界区。
 */

/*10.同步进程：
 * 一组并发进程按一定的顺序执行的过程称为进程间的同步。具有同步关系一组并发进程称为合作进程，
 * 合作进程间互相发送的信号称为消息或事件。
 */

/*11.进程调度：（进程调度方式主要分为抢占式和非抢占式两种）
 * 按一定算法，从一组待运行的进程中选出一个来占有CPU运行。
 *（1）抢占式：高优先级优先调度算法和时间片轮转法结合。
 *（2）非抢占式：指定进程执行时间，时间结束才能进行下一个。
 */

/*12.标准IO缓冲区的优缺点：
 * 在Linux的标准函数库中，有一种被称作缓冲I/O（buffered I/O）的操作，其特征就是对应每一个打开的文件，在内存
 * 中都有一片缓冲区。每次读文件时，会连续读出若干条记录，这样在下次读文件时就可以直接从内存的缓冲区中读取。
 * 同样每次写文件时，也仅仅是写入内存中的缓冲区，等满足了一定的条件，再将缓冲区中的内容一次性写入文件。
 * 这种技术大大增加了文件读写的速度，但也给咱们的编程带来了一些麻烦。比如有些数据你认为已经被写入到文件中，
 * 实际上因为没有满足特定的条件，它们还只是被保存在缓冲区内，这时用_exit()函数直接将进程关闭掉，缓冲区中的
 * 数据就会丢失。因此若想保证数据的完整性，最好使用exit()函数。
 */

/*13.exit()和_exit()函数:（为安全起见，一般用exit()函数）
 *（1）创建进程使用fork()函数，执行进程使用exec函数族，终止进程则使用exit()和_exit()函数。
 *     当进程执行到exit()或_exit()函数时，进程会无条件的停止剩下的所有操作，清除各种数据结构，
 *     并终止本进程的运行。
 *（2）_exit()函数的作用是直接使进程停止运行，清除其使用的内存空间，并清除其在内核中的各种数据结构；
 *     而exit()函数则在这些基础上做了一些包装，在执行退出之前加了若干道工序。exit()函数和_exit()函数的
 *     最大区别就在于exit()函数在终止当前进程之前要检查该进程打开过哪些文件，把文件缓冲区中的内容写回文件。
 *（3）exit()用来正常终结目前进程的执行，并把参数status返回给父进程，而进程所有的缓冲区数据会自动写回并关闭
 *     未关闭的文件。
 *（4）_exit()用来立刻结束目前进程的执行，并把参数status返回给父进程，并关闭未关闭的文件。此函数调用后不会返回，
 *     并且会传递SIGCHLD信号给父进程，父进程可以由wait函数取得子进程结束状态。
 *（5）exit()和_exit()函数的作用是使进程退出，但也仅仅限于将一个正常的进程变成一个僵尸进程，并不能将其完全销毁。
 */

/*14.wait()和waitpid()函数：
 *（1）wait()函数用于使父进程阻塞，直到一个子进程结束或者该进程接收到了一个指定的信号为止。如果该父进程没有
 *     子进程或者它的子进程已经结束，则wait()函数就会立即返回。
 *（2）waitpid()的作用和wait()一样，但它并不一定要等待第一个终止的子进程，它可以指定需要等待终止的子进程pid。
 *     waitpid()有若干选项，如可提供一个非阻塞版本的wait()功能。实际上wait()函数只是waitpid()函数的一个特例，
 *     在Linux内部实现wait()函数时直接调用的就是waitpid()函数。
 *（3）一个进程结束之后，就会变成僵尸进程，需要父进程替它收尸。如果其父进程在其死掉之前就已经死掉，则该进程就
 *     变为了孤儿进程，由init进程接管，死后也由init进程为其收尸。如果父进程没有调用wait函数对子进程进行收尸，
 *     子进程死后也是变成了僵尸进程，最终在父进程死了之后由init进程为其收尸。
 */

/*15.wait()函数的用法：
 *（1）wait()功能：等待任意一个子进程结束，并回收该子进程的资源。在每个进程退出的时候，内核释放该进程所有的资源
 *     （包括打开的文件、占用的内存等）。但是仍然为其保留一定的信息，这些信息主要指进程控制块的信息（包括进程号、
 *     退出状态、运行时间等）。调用wait()函数的进程会挂起，直到它的一个子进程退出或收到一个不能被忽视的信号时才被唤醒。
 *     若调用进程没有子进程，该函数立即返回。若它的子进程已经结束，该函数同样会立即返回，并会回收那个已结束进程的资源。
 *     所以wait()函数的主要功能为回收已经结束子进程的资源。
 *（2）status参数：返回进程退出时的状态信息。如果参数status的值不是NULL，wait()就会把子进程退出时的状态取出并存入其中，
 *     它是一个整数值，指出子进程是正常退出还是被非正常结束的。这个退出信息在一个int中包含了多个字段，直接使用这个值是
 *     没有意义的，我们需要用宏定义取出其中的每个字段。
 *（3）WIFEXITED(status)：如果子进程是正常终止的，取出的字段值非零。
 *（4）WEXITSTATUS(status)：返回子进程的退出状态，退出状态保存在status变量的8~16位。在用此宏前应先用宏WIFEXITED
 *     判断子进程是否正常退出，正常退出才可以使用此宏。
 *（5）返回值：成功返回已经结束子进程的进程号，失败返回-1。
 */

/*16.waitpid()函数的用法：
 *（1）waitpid()功能：等待子进程终止，如果子进程终止了，此函数会回收子进程的资源。
 *（2）pid参数：指定等待回收子进程pid。
 *  ①pid > 0：等待进程ID等于pid 的子进程。
 *  ②pid = 0：等待同一个进程组中的任何子进程，如果子进程已经加入了别的进程组，waitpid()不会等待它。
 *  ③pid = -1：等待任一子进程，此时waitpid()和wait()作用一样。
 *  ④pid < -1：等待指定进程组中的任何子进程，这个进程组的ID等于pid的绝对值。
 *（3）status参数: 进程退出时的状态信息，和wait()用法一样。
 *（4）options参数: options提供了一些额外的选项来控制waitpid()。
 *  ①0：同wait()，阻塞父进程，等待子进程退出。
 *  ②WNOHANG；没有任何已经结束的子进程，则立即返回。
 *  ③WUNTRACED：如果子进程暂停了则此函数马上返回，并且不予以理会子进程的结束状态。
 *（5）返回值：waitpid()的返回值比wait()稍微复杂一些，一共有3种情况。
 *  ①当正常返回的时候，waitpid()返回收集到的已经子进程的进程号。
 *  ②如果设置了选项WNOHANG，而调用中waitpid()发现没有已退出的子进程可等待，则返回-1。
 *  ③如果调用中出错，则返回-1，这时errno会被设置成相应的值以指示错误所在。当pid所对应的子进程不存在，
 *    或此进程存在，但不是调用进程的子进程，waitpid()就会出错返回，这时errno被设置为ECHILD。
 */

/*17.僵尸进程产生的原因：
 * 任何一个子进程(init除外)在exit()之后，并非马上就消失掉，而是留下一个称为僵尸进程(Zombie)的数据结构，
 * 等待父进程处理。这是每个子进程在结束时都要经过的阶段。如果子进程在exit()之后，父进程没有来得及处理，
 * 这时用ps命令就能看到子进程的状态是“defunct”。如果父进程能及时处理，可能用ps命令就来不及看到子进程的僵尸状态，
 * 但这并不等于子进程不经过僵尸状态。如果父进程在子进程结束之前退出，则子进程将由init接管。init进程将会以父进程的
 * 身份对僵尸状态的子进程进行处理。所以孤儿进程不会占资源，僵尸进程会占用资源危害系统。我们应当避免僵尸进程的出现。
 */

/*18.解决僵尸进程两种方法：
 *（1）子进程退出之前，会向父进程发送一个信号，父进程调用waid函数等待这个信号，只要等到了，就不会产生僵尸进程。
 *     但在并发的服务程序中这是不可能的，因为父进程要做其它的事，不能被阻塞。
 *（2）在父进程使用signal(SIGCHLD,SIG_IGN)语句，直接忽略子进程的退出信号，避免产生僵尸进程。
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
static void wait_test();      //使用wait()和waitpid()回收子进程退出资源，可以避免僵尸进程的产生。
static void waitpid_test();
static void zombie_test();    //父进程后于子进程退出，此时优先退出的子进程就变为了僵尸进程。
static void orphan_test();    //父进程先于子进程退出，此时正在运行的子进程就变为了孤儿进程。

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

//printf()函数使用的是缓冲I/O方式，该函数在遇到“\n”换行符时自动从缓冲区中将记录读出
void exit_test()
{
#ifndef _CHANGE_WAY_
	printf("using exit()...\n");
	printf("this content will be output on exit");
	exit(0);    //exit()函数属于C库函数，在退出进程前，会自动刷新缓冲区
#else
	printf("using _exit()...\n");
	printf("this content can't be print on _exit");
	_exit(0);   //_exit()函数属于系统调用，在退出进程前，不会自动刷新缓冲区
#endif
}

/*当一个进程正常或异常终止时，内核就向其父进程发送SIGCHLD 信号，相当于告诉父亲他哪个儿子挂了，
 *而父进程可以通过wait()或waitpid()函数等待子进程结束，获取子进程结束时的状态，同时回收他们的资源。
 */
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
		
		/*wait()回收子进程资源成功，返回被回收的子进程的进程ID，失败返回-1。当没有子进程资源可以回收了，
		 *函数的阻塞会自动解除，返回-1。当回收子进程资源的时候出现了异常，也会返回-1。
		 */
		int status;
#ifndef _CHANGE_WAY_
		pid_t retpid = wait(&status);  //wait()阻塞等待子进程结束，回收子进程资源。wait(&status)底层实现就是waitpid(-1,&status,0)
#else
		pid_t retpid = waitpid(-1,&status,0);   //waitpid()可以实现为阻塞或非阻塞版本等待子进程退出，回收子进程结束后留下的进程控制块资源。
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

/*wait()和waitpid()函数的功能一样，区别在于wait()函数会阻塞，waitpid()可以设置不阻塞，
 *waitpid()还可以指定等待哪个子进程结束。
 */
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
			//waitpid()函数可以设置阻塞, 也可以设置为非阻塞，并且可以指定回收哪些子进程的资源。
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