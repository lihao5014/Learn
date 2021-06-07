/*1.exec函数族说明：
 *（1）fork()函数用于创建一个新的子进程，但该子进程几乎复制了父进程的全部内容。如果想要父子进程中执行不同的代码段，
 *     就需要用到exec函数族。exec函数族提供了一个在进程中启动另一个程序执行的方法。它可以根据指定的文件名或目录名
 *     找到可执行文件，并用它来取代原调用进程的数据段、代码段和堆栈段，在执行完之后，原调用进程的内容除了进程号外，
 *     其他全部被新的进程替换了。另外这里的可执行文件既可以是二进制文件，也可以是Linux下任何可执行的脚本文件。
 *（2）在Windows平台下，我们可以通过双击运行可执行程序，让这个可执行程序成为一个进程。而在Linux平台可以通过./运行，
 *     让一个可执行程序成为一个进程。但是如果我们本来就运行着一个程序，我们又需要在这个进程内部启动一个外部程序，
 *     由内核将这个外部程序读入内存，使其执行起来成为一个进程，就需要通过exec函数族实现。
 *（3）exec函数族，顾名思义就是一簇函数，在Linux中并不存在exec()函数，exec指的是一组函数，一共有6个。
 *     其中只有execve()是真正意义上的系统调用，其它都是在此基础上经过包装的库函数。
 *（4）exec函数族提供了六种在进程中启动另一个程序的方法。exec函数族的作用是根据指定的文件名或目录名找到可执行文件，
 *     并用它来取代调用进程的内容，换句话说，就是在调用进程内部执行一个可执行文件。
 *（5）进程调用一种exec函数时，该进程完全由新程序替换，而新程序则从其main函数开始执行。因为调用exec并不创建新进程，
 *     所以前后的进程ID（当然还有父进程号、进程组号、当前工作目录等）并未改变。exec只是用另一个新程序替换了当前进程
 *     的正文、数据、堆和栈段。
 *（6）exec函数族的6个函数看起来似乎很复杂，但实际上无论是作用还是用法都非常相似，只有很微小的差别。
 */

/*2.在Linux中使用exec函数族主要有两种情况：
 *（1）当进程认为自己不能再为系统和用户做出任何贡献时，就可以调用exec函数族中的任意一个函数让自己重生。
 *（2）如果一个进程想执行另一个程序，那么它就可以调用fork()函数新建一个进程，然后调用exec函数族中的任意一个函数，
 *     这样看起来就像通过执行应用程序而产生了一个新进程。
 */

/*3.exec函数族使用方法：
 *（1）实际上Linux中并没有exec()函数，而是由6个以exec开头的函数，它们在可执行文件查找方式、参数传递方式
 *     和环境变量使用，这三个方面上有细微差别。
 *（2）查找方式：execl(),execv(),execle()和execve()的查找方式都是完整的文件目录路径，而execlp()和execvp()
 *     也就是以p结尾的两个函数，可以只给出文件名，系统就会自动按照环境变量“$PATH” 所指定的路径进行查找。
 *（3）参数传递方式：exec函数族的参数传递有两种，一种是逐个列举的方式，而另一种则是将所有参数整体构造指针数组传递。
 *     在这里是以函数名的第5位字母来区分的，字母为"l"(list)的表示逐个列举参数的方式，其语法为const char *arg。
 *     字母为“v”(vector)的表示将所有参数整体构造指针数组传递，其语法为char *const argv[]。这里的参数实际上就是
 *     用户在使用这个可执行文件时所需的全部命令选项字符串（包括该可执行程序命令本身）。要注意的是，这些参数必须
 *     以NULL结束。
 *（4）环境变量：exec函数族可以默认系统的环境变量，也可以传入指定的环境变量。这里以“e”(environment)结尾的两个函数
 *     execle()和 execve()就可以在envp[]中指定当前进程所使用的环境变量。
 *（5）exec函数族中真正的系统调用只有execve()，其他5个都是库函数，它们最终都会调用execve()这个系统调用。
 *     在使用exec函数族时，一定要加上错误判断语句。因为exec很容易执行失败。
 */

/*4.exec函数运行失败常见的原因：
 *（1）找不到文件或路径，此时errno被设置为ENOENT。
 *（2）数组argv和envp忘记用NULL结束，此时errno被设置为EFAUL。
 *（3）没有对应可执行文件的运行权限，此时errno被设置为EACCES。
 */

/*5.exec函数族语法：（6个exec函数头文件unistd.h）
 *（1）int execl(const char *path, const char *arg, ...);
 *（2）int execlp(const char *file, const char *arg, ...);
 *（3）int execle(const char *path, const char *arg, ..., char * const envp[]);
 *（4）int execv(const char *path, char *const argv[]);
 *（5）int execvp(const char *file, char *const argv[]);
 *（6）int execve(const char *path, char *const argv[], char *const envp[]);
 */

/*6.exec函数名尾部字母的含义：
 *（1）l(list)：参数地址列表，以空指针结尾。
 *（2）v(vector)：存有各参数地址的指针数组的地址。
 *（3）p(path)：按 PATH 环境变量指定的目录搜索可执行文件。
 *（4）e(environment)：存有环境变量字符串地址的指针数组的地址。
 */

/*exec函数族与一般的函数不同，exec函数族中的函数执行成功后不会返回，而且exec数族下面的代码执行不到。
 *只有调用失败了，它们才会返回-1，失败后从原程序的调用点接着往下执行。
 */
 
/*7.exec函数族中各函数之间的区别：
 *（1）execlp()和execl()的区别在于，execlp()指定的可执行程序可以不带路径名，如果不带路径名的话，
 *     会在环境变量PATH指定的目录里寻找这个可执行程序，而execl()指定的可执行程序，必须带上路径名。
 *（2）execle()和execve()改变的是exec启动的程序的环境变量（只会改变进程的环境变量，不会影响系统的环境变量），
 *     其他四个函数启动的程序则使用默认系统环境变量。
 */

/*8.exec函数族使用注意事项：
 *（1）exec族函数一般不会在进程中直接调用，如果直接调用这个进程的代码区会被替换，也就不能按照原来的流程工作了。
 *    我们一般在调用这些函数的时候都会先创建一个子进程，在子进程中调用exec族函数，子进程的用户区数据被替换掉，
 *    开始执行新的程序中的代码逻辑，但是父进程不受任何影响仍然可以继续正常工作。
 *（2）exec函数族执行成功后不会返回，因为调用进程的实体，包括代码段、数据段和堆栈等都已经被新的内容取代
 *    （即用户区数据基本全部被替换掉了），只留下进程ID等一些表面上的信息仍保持原样。只有调用失败了，
 *     它们才会返回一个-1，从原程序的调用点接着往下执行。
 *（3）exec族函数并没有创建新进程的能力，只是有大无畏的牺牲精神，让起启动的新进程寄生到自己虚拟地址空间之内，
 *     并挖空了自己的地址空间用户区，把新启动的进程数据填充进去。
 *（4）exec族函数中最常用的有两个execl()和execlp()，这两个函数是对其他4个函数做了进一步的封装。
 */

/*9.execl()函数使用方法：
 *（1）int execl(const char *path, const char *arg, ...);
 *（2）功能：可用于执行任意一个可执行程序，函数需要通过指定的文件路径才能找到这个可执行程序。
 *（3）参数：
 *  ①path: 要启动的可执行程序的路径，推荐使用绝对路径。
 *  ②arg: 启动的进程的名字，可以随意指定，一般和要启动的可执行程序名相同。
 *  ③...: 要执行的命令需要的参数，可以写多个，最后以NULL结尾，表示参数指定完了。
 *（4）返回值：如果这个函数执行成功，没有返回值，如果执行失败，返回-1。
 */

/*10.execlp()函数使用方法：
 *（1）int execlp(const char *file, const char *arg, ...);
 *（2）常用于执行已经设置了环境变量的可执行程序，函数名中的p就是path，也是说这个函数会自动搜索系统的环境变量PATH，
 *     因此使用这个函数执行可执行程序不需要指定路径，只需要指定出名字即可。
 *（3）参数：
 *  ①file: 可执行程序的名字。在环境变量PATH中，可执行程序可以不加路径。没有在环境变量PATH中，
 *          可执行程序需要指定绝对路径。
 *  ②arg: 启动的进程的名字，可以随意指定，一般和要启动的可执行程序名相同。
 *  ③...: 要执行的命令需要的参数，可以写多个，最后以NULL结尾，表示参数指定完了。
 *（4）返回值：如果这个函数执行成功，没有返回值，如果执行失败，返回-1。
 */

#include <unistd.h>      //fork(),execl()
#include <sys/types.h>   //pid_t
#include <sys/wait.h>    //wait()，waitpid()
#include <stdio.h>
#include <stdlib.h>      //exit(),getenv()
#include <string.h>      //strcmp(),strerror()
#include <errno.h>       //error全局变量

typedef void (*pFun)();

typedef struct Message_t
{
	char signal[16];
	pFun handle;
}Message_t;

static void execl_test();
static void execle_test();
static void execlp_test();
static void execv_test();

static const Message_t message_map[] = {
	{"execl",execl_test},
	{"execle",execle_test},
	{"execlp",execlp_test},
	{"execv",execv_test}
};

/*在项目开发过程中，有时候有这种需求，需要通过现在运行的进程启动磁盘上的另一个可执行程序，
 *也就是通过一个进程启动另一个进程，这种情况下我们可以使用exec族函数。
 */
int main(int argc,char* argv[])
{
	puts("useage: ./exec.out execl/execlp");
	if(argc != 2)
	{
		// execl_test();
		execle_test();
		// execlp_test();
		// execv_test();
		
		return -1;
	}
	
	for(int i=0;i<sizeof(message_map)/sizeof(Message_t);++i)
	{
		if(strcmp(argv[i],message_map[i].signal) == 0)
		{
			message_map[i].handle();
			break;
		}
	}
	
	return 0;
}

//exec函数族装入并运行可执行程序path/file，并将参数arg0(arg1,arg2,argv[],envp[])传递给此程序。
void execl_test()
{
	/*"/bin/ls"：是/bin目录的ls可执行程序，必须带上路径（相对或绝对）。
	 *"ls"：没有意义，如果需要给这个外部程序传参，这里必须要写上字符串，至于字符串内容任意。
	 *"-a，-l，-h"：给外部程序ls传的参数。
	 *NULL：必须写上，代表给外部程序ls传参结束。
	 */
	printf("execl_test: call execl before\n");
	if(execl("/bin/ls","ls","-a","-l","-h",NULL) == -1)  //execl()使用完整的文件目录来查找对应的可执行文件。注意目录必须以“/”开头，否则将其视为文件名。
	{
		perror("execl_test error: ");
		exit(-1);
	}
	
	//如果execl()执行成功，下面fprintf语句执行不到，因为当前进程空间已经被执行的ls替换了
	fprintf(stdout,"execl_test: call execl after\n");
}

void execle_test()
{
	//getenv()获取指定环境变量的值
	printf("execle_test：call execle before ,USER =%s, HOME =%s\n", getenv("USER"), getenv("HOME"));
	
	//改变helloworld.exe程序的环境变量，让helloworld.exe只保留env环境变量。而不会影响系统的环境变量。
	char *env[] = {"USER=lihao","HOME=/home/linux/Share/Learn",NULL};
	if(execle("helloworld/helloworld.exe","helloworld.exe",NULL,env))   //execle()可以将环境变量添加到新建的子进程中。
	{
		fprintf(stdout,"execle_test error：%s\n",strerror(errno));
		_exit(-1);
	}
	
	fputs("execle_test：call execle after\n",stdout);
}

/*execlp()的参数列表列出了在shell中使用的命令名和选项，并且当使用文件名进行查找时，
 *系统会在默认的环境变量PATH中寻找该可执行文件。
 */
void execlp_test()
{
	pid_t pid = fork();
	if(pid == -1)
	{
		printf("execlp_test error: %s\n",strerror(errno));
		_exit(-1);
	}
	else if(pid == 0)
	{
		fprintf(stdout,"execlp_test: child process ,pid =%d ,ppid =%d\n",getpid(),getppid());
		sleep(4);
		
		//execlp()使用文件名来查找可执行文件，同时使用参数列表的方式传递参数。
		if(execlp("ps","ps","-aux",NULL) == -1)  //第一个参数"ps"，没有带路径名，说明在环境变量PATH里寻找这个可执行程序。
		{
			perror("execlp_test: child process ,");
			exit(-1);
		}
	}
	else if(pid > 0)
	{
		printf("execlp_test: parent process ,pid =%d ,spid =%d ,ppid =%d\n",getpid(),pid,getppid());
		
		int retpid = -1;
		int count = 10;
		do{
			retpid = waitpid(pid,NULL,WNOHANG);   //使用非阻塞的方式，轮询回收子进程资源
			if(retpid == -1)
			{
				puts("execlp_test: parent process ,don't have child process need to recycle\n"); 
				
				const char* str = "execlp_test: parent process is runing\n";
				fwrite(str,strlen(str),1,stdout);
				fflush(stdout);
				sleep(1);
			}
			else if(retpid == 0)
			{
				fputs("execlp_test: parent process ,child process is runing\n",stdout);
				
				const char msg[] = "execlp_test: parent process do some work\n";
				write(STDOUT_FILENO,msg,strlen(msg));
				sleep(1);
			}
			else if(retpid == pid)
			{
				const char msg[] = " capture child process exit\n";
				printf("execlp_test: parent process ,child %d terminated\n",retpid);
				sleep(1);
			}
		}while(count--);
		
		puts("execlp_test: parent process run finished and exit");
	}
}

//execv()和execl()的用法基本是一样的，无非将列表传参，改为用指针数组。
void execv_test()
{
	/*vfork()可以保证子进程先运行，在它调用exec进程替换或exit退出进程之后父进程才可能被调度运行。
	 *且子进程在调用exec进程替换或exit退出进程之前与父进程数据是共享的。
	 */
	pid_t pid = vfork();
	if(pid == -1)
	{
		const char* str = "execv_test error: vfork failed\n";
		write(STDERR_FILENO,str,strlen(str));
		exit(-1);
	}
	else if(pid == 0)
	{
		printf("execv_test: child process ,pid =%d ,ppid =%d\n",getpid(),getppid());
		puts("execv_test: child process ,call execv before");
	
		char *arg[] = {"welcome.out","test execv",NULL};  //命令参数列表必须以NULL作为结尾标识符。
		if(execv("./welcome.out",arg) == -1)    //execv()函数使用构造指针数组的方式来传递参数。
		{
			printf("execv_test error: child process ,%s\n",strerror(errno));
		}
		
		fputs("execv_test: child process ,call execv after\n",stdout);
		_exit(-1);
	}
	else if(pid > 0)
	{
		fprintf(stdout,"execv_test: parent process ,pid =%d ,spid =%d ,ppid =%d\n",getpid(),pid,getppid());
		
		/*vfork()以后子进程中调用exec函数替换了进程空间。父进程中也需要使用wait()/waitpid()回收子进程资源，
		 *以防止子进程变为僵尸进程。
		 */
		wait(NULL);
		
		for(int i=0;i<5;++i)
		{
			sleep(1);
			puts("execv_test: parent process running");
		}
		
		fputs("execv_test: parent process run finished and exit\n",stdout);
	}
}