/*1.程序和进程的区别：
 *（1）程序和进程是两个不同的概念，他们的状态，占用的系统资源都是不同的。
 *（2）程序：就是磁盘上的可执行文件文件，并且只占用磁盘上的空间，是一个静态的概念。
 *（3）进程：被执行之后的程序叫做进程，不占用磁盘空间，需要消耗系统的内存，CPU资源，
 *     每个运行的进程的都对应一个属于自己的虚拟地址空间，这是一个动态的概念。
 */

/*fork是根据一个现有的进程复制出一个新进程，原来的进程称为父进程(Parent Process)，新进程称为子进程(Child Process)。
 *系统中同时运行着很多进程，这些进程都是从最初只有一个进程开始一个一个复制出来的。在Shell下输入命令可以运行一个程序，
 *是因为Shell进程在读取用户输入的命令之后，会调用fork复制出一个新的Shell进程，然后新的Shell进程调用exec执行新的程序。
 */

/*2.fork系统调用使用注意事项：（在Linux中创建一个新进程的唯一方法是使用fork()/vfork()函数）
 *（1）fork系统调用之后，父子进程将交替执行。
 *（2）如果父进程先退出，子进程还没退出那么子进程的父进程将变为init进程，任何一个进程都必须有父进程。
 *（3）如果子进程先退出，父进程还没退出，那么子进程必须等到父进程捕获到了子进程的退出状态才真正结束，
 *     否则这个时候子进程就成为僵进程。子进程退出会发送SIGCHLD信号给父进程，可以选择忽略或使用信号处
 *     理函数接收处理就可以避免僵尸进程。
 */

/*fork就是基于写时复制，只读代码段是可以共享的。若使用vfork则子进程和父进程占用同一个内存映像，
 *在子进程修改会影响父进程。同时只有在子进程执行exec/exit之后才会运行父进程。实际上子进程占用的
 *栈空间就是父进程的栈空间，所以需要非常小心。如果vfork的子进程并没有exec或者是exit的话，那么子
 *进程就会执行直到程序退出之后，父进程才开始执行。而这个时候父进程的内存已经完全被写坏。
 */

/*fork()函数用于从已存在的一个进程中创建一个新的进程，新进程称为子进程，而原进程称为父进程。使用fork()函数
 *得到的子进程是父进程的一个复制品，它从父进程处继承了整个进程的地址空间，包括进程上下文、代码段、进程堆栈、
 *内存信息、打开的文件描述符、信号控制设定、进程优先级、进程组号、当前工作目录、根目录、资源限制和控制终端等，
 *而子进程所独有的只有它的进程号、资源使用和计时器等。可以看出使用fork()函数的代价是很大的，它复制了父进程的
 *代码段、数据段和堆栈段里的大部分内容，使得fork()函数的系统开销比较大，而且执行速度页不是很快。
 */

/*父子进程的代码从fork()函数的返回开始，分别在两个地址空间中同时运行，从而使两个进程分别获得其所属fork()函数的返回值，
 *其中在父进程中的返回值是子进程的进程号，而在子进程中返回0。因此可以通过返回值来判定该进程是父进程还是子进程。
 */

/*由于子进程拷贝了父进程的堆栈段和数据段，也就是说在父进程中定义的变量，在子进程中会复制一个副本，
 *fork之后子进程对变量的操作不会影响交父进程，父进程对变量的操作也不会影响子进程。
 */

/*在父进程中成功创建了子进程，子进程就拥有父进程代码区的所有代码。父进程是从main()函数开始运行的，
 *子进程是在父进程中调用fork()函数之后被创建，子进程就从fork ()之后开始向下执行代码。
 */

/*3.进程ID使用注意事项：
 *（1）Linux中进程ID为pid_t类型，其本质是一个正整数。PID为1的进程是Linux系统中创建的第一个进程。
 *（2）进程ID是系统动态分配的，相同的程序在不同的时间执行，进程的编号是不同的。
 *（3）进程ID会循环使用，但是在同一时间，进程的编号是唯一的，不管任何时间，系统不可能存在两个编号相同的进程。
 */

/*fork()与vfock()函数的区别：
 *（1）fork()：父子进程的执行次序不确定。
?*?    vfork()：保证子进程先运行,在它调用exec进程替换或exit退出进程之后父进程才可能被调度运行。
 *（2）fork()： 子进程拷贝父进程的地址空间，子进程是父进程的一个复制品。
 *  ? ?vfork()：子进程共享父进程的地址空间。准确来说在调用exec进程替换或exit退出进程之前与父进程数据是共享的。
 */

#include <unistd.h>      //getpid(),getppid(),getpgid(),fork(),vfork(),sleep()
#include <sys/types.h>   //pit_t
#include <stdio.h>
#include <stdlib.h>      //exit(),abort()
#include <string.h>

#define _CHANGE_WAY_
#undef _CHANGE_WAY_

#define BUFF_SIZE 512

#define PRINT_INFO(str)  \
	write(STDOUT_FILENO,str,strlen(str))

#define ERROR_INFO(str)  \
	write(STDERR_FILENO,str,strlen(str))

static int g_number = 0;   //父子进程之间不可以通过全局变量互动，实现交替数数的功能

static void processInfo();
static void countNumber();
static void vfork_test();

int main(void)
{
	processInfo();

#ifndef _CHANGE_WAY_   //单独测试fork和vfork的作用，以免它们两个创建的进程相互影响
	countNumber();
#else
	vfork_test();
#endif
	
	return 0;
}

void processInfo()
{
	pid_t pid = getpid();   //获取本进程号（PID）
	printf("processInfo: pid =%d\n",pid);
	
	pid_t ppid = getppid();   //获取父进程号（PPID）
	fprintf(stdout,"processInfo: ppid =%d\n",ppid);
	
	char buf[BUFF_SIZE] = {0};
	pid_t pgid = getpgid(pid);   //获取进程组号（PGID）
	sprintf(buf,"processInfo: pgid =%d",pgid);
	puts(buf);
	
	sleep(5);
	fputs("---processInfo end---\n\n",stdout);
}

/*两个进程中是不能通过全局变量实现数据交互的，因为每个进程都有自己的地址空间，两个同名全局变量存储在
 *不同的虚拟地址空间中，二者没有任何关联性。如果要进行进程间通信需要使用：管道，共享内存，本地套接字，
 *内存映射区，消息队列等方式。
 */
void countNumber()
{
	printf("---countNumber start: g_number =%d\n",g_number);

	pid_t pid = fork();
	if(pid == -1)
	{
		perror("countNumber fork error: ");
		exit(-1);
	}
	else if(pid == 0)
	{
		g_number++;
		printf("countNumber: child process, pid =%d ,ppid =%d ,g_number =%d\n",getpid(),getppid(),g_number);   //g_number =1
	}
	else if(pid > 0)
	{
		sleep(1);    //延时1s，使子进程开始优先执行数数功能
		g_number += 10;     //父进程没有接着子进程结束时的g_number等于1开始计数,而是父子进程各玩各的
		fprintf(stdout,"countNumber: parent process, pid =%d ,ppid =%d ,g_number =%d\n",getpid(),getppid(),g_number);  ////g_number =10
	}
	
	fprintf(stdout,"---countNumber end: pid =%d, g_number =%d\n\n",getpid(),g_number);
}

/*vfork()保证子进程先运行，在它调用exec进程替换或 exit退出进程之后父进程才可能被调度运行。
 *如果子进程没有调用exec/exit, 程序则会导致死锁，程序是有问题的程序，没有意义。
 */
void vfork_test()
{
	int var = 0;
	
	pid_t pid = vfork();
	if(pid == -1)
	{
		perror("vfork_test vfork error: ");
		exit(-1);
	}
	else if(pid == 0)
	{
		var++;
		printf("vfork_test: child process, pid =%d ,ppid =%d ,var =%d\n",getpid(),getppid(),var);   //var =1
		
		/*必须调用exit/_exit退出子进程，将共享内存空间还给父进程使用。否则子进程进入僵尸态后，会一直跟父
		 *进程争夺共享的地址空间，从而造成父进程运行时，内存空间中的数据紊乱，导致段错误或程序运行异常。
		 */
		_exit(0);
	}
	else if(pid > 0)  //通过vfork()创建的子进程会执行完后，才到父进程执行。
	{
		var += 10;  //由于使用vfork创建的子进程与父进程共享内存空间，所以子进程中对var变量的修改，在父进程中也会生效
		fprintf(stdout,"vfork_test: parent process, pid =%d ,ppid =%d ,var =%d\n",getpid(),getppid(),var);  //var =11
	}
}