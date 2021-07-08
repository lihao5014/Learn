/*管道的是进程间通信的一种方式，管道的本质其实就是内核中的一块内存或称为内核缓冲区，这块缓冲区中的数据存储在
 *一个环形队列中。因为管道在内核里边，所以我们不能直接对其进行任何操作。
 */

/*1.管道中数据的特点：（因为管道数据是通过队列来维护的，所以管道必定会具有队列的所有特点）
 *（1）管道对应的内核缓冲区大小是固定的，默认为4k（也就是队列最大能存储4k数据）。
 *（2）管道分为两部分：读端和写端（队列的两端），数据从写端进入管道，从读端流出管道。
 *（3）管道中的数据只能读一次，做一次读操作之后数据也就没有了。读数据相当于出队列。
 *（4）管道是单工的：数据只能单向流动，数据从写端流向读端。
 *（5）对管道的操作读写默认是阻塞的。
 *  ①读管道：管道中没有数据，读操作被阻塞，当管道中有数据之后阻塞才能解除。
 *  ②写管道：管道被写满了，写数据的操作被阻塞，当管道变为不满的状态，写阻塞解除。
 */

/*2.管道的读写操作：（管道操作对应两个文件描述符, 分别是管道的读端和写端）
 *（1）管道在内核中，不能直接对其进行操作。其实管道操作就是文件IO操作，内核中管道的两端分别对应两个文件描述符，
 *     通过写端的文件描述符把数据写入到管道中，通过读端的文件描述符将数据从管道中读出来。读写管道函数就是Linux
 *     中的文件IO函数。
 *（2）父进程创建无名管道后可以通过文件描述符表中的文件描述符fd3写管道、fd4读管道，然后再通过fork()创建出子进程，
 *     那么在父进程中被分配的文件描述符fd3、fd4也就被拷贝到子进程中，子进程通过fd3可以将数据写入到内核的管道中，
 *     通过fd4将数据从管道中读出来。（文件描述符表中：fd1 - STDIN_FILENO,fb2 - STDOUT_FILENO,fb3 - STDERR_FILENO）
 *（3）管道是独立于任何进程的，并且充当了两个进程用于数据通信的载体，只要两个进程能够得到同一个管道的入口和出口
 *    （读端和写端的文件描述符），那么他们之间就可以通过管道进行数据的交互。
 */

/*3.无名管道pipe的特点：（无名管道是一种特殊类型的文件，在应用层体现为两个打开的文件描述符）
 *（1）半双工，数据在同一时刻只能在一个方向上流动。
 *（2）数据只能从管道的一端写入，从另一端读出。
 *（3）写入管道中的数据遵循先入先出的规则。
 *（4）管道所传送的数据是无格式的，这要求管道的读出方与写入方必须事先约定好数据的格式，如多少字节算一个消息等。
 *（5）管道不是普通的文件，不属于某个文件系统，其只存在于内存中。
 *（6）管道在内存中对应一个缓冲区。不同的系统其大小不一定相同。
 *（7）从管道读数据是一次性操作，数据一旦被读走，它就从管道中被抛弃，释放空间以便写更多的数据。
 *（8）管道没有名字，只能在具有公共祖先的进程之间使用。即具有亲缘关系的父子进程或兄弟进程之间使用。
 */

/*4.有名管道fifo的特点：（有名管道是对无名管道的一种改进）
 *（1）它可以使互不相关的两个进程间实现彼此通信。
 *（2）命名管道可以通过路径名来指出，并且在文件系统中是可见的。在建立了管道之后，两个进程就可以把它当做普通文件
 *     一样进行读写操作，使用非常方便。
 *（3）有名管道严格地遵循先进先出规则，对管道及FIFO的读总是从开始处返回数据，对它们的写则是把数据添加到末尾，
 *     它们不支持如lseek()等文件定位操作。
 */

/*5.pipe()函数的用法：
 *（1）函数原型：int pipe(int filedes[2])。
 *（2）功能：创建无名管道。
 *（3）参数：filedes为int型数组的首地址，其存放了管道的文件描述符filedes[0]和filedes[1]。当一个管道建立时，
 *           它会创建两个文件描述符fd[0]和fd[1]，其中fd[0]固定用于读管道，而fd[1]固定用于写管道。一般文件
 *           I/O的函数都可以用来操作管道，lseek()除外。
 *（4）返回值：成功返回0，失败返回-1。
 */

/*6.管道读写的特点：
 *（1）每个管道只有一个页面作为缓冲区，该页面是按照环形缓冲区的方式来使用的。这种访问方式是典型的“生产者—消费者”模型。
 *     生产者进程有数据需要写时，每当写满一个页面就需要进行睡眠等待，等待消费者从管道中读走一些数据，为其腾出一些空间。
 *     相应的如果管道中没有可读数据，消费者进程就要睡眠等待，
 *（2）默认的情况下，从管道中读写数据，最主要的特点就是阻塞。当管道里没有数据，另一个进程默认用read()函数从管道中
 *     读数据是阻塞的。当调用write()函数向管道里写数据，当缓冲区已满时write()也会阻塞。
 *（3）管道通信过程中别的进程先结束了，当前进程读端口关闭后再向管道内写数据时，write()进程会收到SIGPIPE信号退出。
 *     收到SIGPIPE默认动作为中断当前进程。
 */

/*7.命名管道的使用：
 *（1）有名管道的创建可以使用函数mkfifo()，该函数类似于文件中的open()操作，可以指定管道的路径和打开的模式。
 *     还可以在命令行使用“mknod 管道名 p”来创建有名管道。
 *（2）在管道创建成功后就可以使用open()、read()和write()等文件IO读写管道。与操作普通文件一样，对于为读而打开的管道
 *     可在open()中设置O_RDONLY，对于为写而打开的管道可在open()中设置O_WRONLY。管道和普通文件读写的区别是阻塞问题。
 *     普通文件在读写时不会出现阻塞问题，而管道的读写中却有可能阻塞。可以在open()函数中设定非阻塞标志O_NONBLOCK。
 *（3）由于Windows的文件系统不支持管道文件，所以在Linux和Windows的共享文件夹中，使用mkfifo/mknod命令创建管道会失败。
 *     应该只在linux的本地文件夹中创建管道文件。
 */

/*8.阻塞/非阻塞打开管道的读写特点：
 *（1）对于读进程：
 *  ①若管道是阻塞打开，且当前FIFO内没有数据，则对读进程而言将一直阻塞到有数据写入。
 *  ②若管道是非阻塞打开，则不论FIFO内是否有数据，读进程都会立即执行读操作。即如果FIFO内没有数据，则读函数将立刻返回0。
 *（2）对于写进程：
 *  ①若管道是阻塞打开，则写操作将一直阻塞到数据可以被写入。
 *  ②若管道是非阻塞打开，而不能写入全部数据，则读操作进行部分写入或者调用失败。
 */

/*9.mkfifo()函数的用法：
 *（1）函数原型：int mkfifo(const char *pathname, mode_t mode)。
 *（2）功能：创建有名管道。
 *（3）pathname参数：要创建的有名管道的名字。
 *（4）mode参数：文件的操作权限，和open()的第三个参数一个作用，最终权限为(mode & ~umask)。
 *（5）返回值：创建成功返回0，失败返回-1。
 */

/*10.access()函数的用法：
 *（1）函数原型：int access(const char * pathname, int mode)。
 *（2）功能：检查当前进程是否可以对指定文件进行某种操作。
 *（3）pathname：要检查的文件路径名。
 *（4）mode：需要检查的操作模式，mode的值一般为R_OK可读、W_OK可写、X_OK可执行、F_OK是否存在。
 *（5）返回值：成功返回0，失败返回-1.
 */

/*11.非阻塞打开的命名管道特点：（命名管道可以使用O_NONBLOCK非阻塞标志方式open()打开）
 *（1）先以只读方式打开，如果没有进程已经为写而打开一个FIFO, 只读open()成功，并且open()不阻塞。
 *（2）先以只写方式打开，如果没有进程已经为读而打开一个FIFO，只写open()将出错返回-1。
 *（3）read()、write()读写命名管道中读数据时不阻塞。
 */

#include <unistd.h>        //fork(),_exit()
#include <fcntl.h>         //creat(),open(),fcntl()
#include <signal.h>        //kill(),raise(),pause()
#include <sys/types.h>     //pid_t,ssize_t
#include <sys/stat.h>      //mkfifo(),mkdir(),stat(),fstat(),struct stat
#include <sys/wait.h>      //wait(),waitpid()
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define _ERROR_
#undef _ERROR_

#define _CHANGE_WAY_
#undef _CHANGE_WAY_

#define BUFF_SIZE 256

struct Message
{
	int pid;
	int textsize;
	char text[BUFF_SIZE];
};

static const int size = 256;

static void mkfifo_test();
static void fifo_operator();
static void fifo_message();
static void fcntl_fifo();

int main(int argc,char *agrv[])
{
	// mkfifo_test();
	// fifo_operator();
	// fifo_message();
	fcntl_fifo();
	
	return 0;
}

void mkfifo_test()
{
	int ret = mkfifo("testfifo",0666);    //创建命名管道
	if(ret == -1)
	{
		perror("mkfifo_test error");
		return ;
	}
	system("ls -l | grep testfifo");     //查看创建的命名管道信息
	
	/*open()以只读方式打开FIFO时，要阻塞到某个进程为写而打开此FIFO。
     *open()以只写方式打开FIFO时，要阻塞到某个进程为读而打开此FIFO。
     *即只读等着只写，只写等着只读，只有两个都执行到，才会往下执行。
	 */
#ifndef _CHANGE_WAY_
    //由于没有其他进程以写操作打开testfifo管道，所以mkfifo_test()测试函数会一直阻塞到open()函数这里。
	int fb = open("./testfifo",O_RDONLY);    //以只读方式打开命名管道。
	if(fb == -1)
	{
		puts("mkfifo_test error: open() failed");
		exit(-1);
	}
#else
	int fb = open("testfifo",O_RDONLY | O_NONBLOCK);   //非阻塞只读方式打开命名管道
	if(fb == -1)
	{
		printf("mkfifo_test error: %s",strerror(errno));
		_exit(-1);
	}
#endif
	fputs("mkfifo_test: open fifo successfully\n",stdout);
	
	close(fb);            //关闭打开的有名管道
	unlink("testfifo");   //删除命名管道
}

/*access()函数的功能是确定文件或文件夹的访问权限，即检查某个文件的存取方式，比如说是只读方式、只写方式等。
 *如果指定的存取方式有效，则函数返回0,否则函数返回-1。
 */
void fifo_operator()
{
	if(access("./fifotest.p",F_OK) == -1)
	{
		if(mkfifo("fifotest.p",0666) == -1)
		{
			perror("fifo_operator error");
			abort();
		}
	}
	
	//以O_RDWR可读可写方式打开有名管道文件，open()函数就不会阻塞。
	int fb = open("fifotest.p",O_RDWR);
	if(fb == -1)
	{
		printf("fifo_operator error: %s\n",strerror(errno));
		return ;
	}
	
	write(fb,"hello world\n",strlen("hello world\n"));
	write(fb,"fifo test program\n",strlen("fifo test program\n"));

	/*C语言中不能使用const常量来定义数组大小，只能使用宏。因为C语言中const常量又称为常变量，
	 *本质上只有一个大小不可再被修改的变量。而C++语言中可以使用const常变量来定义数组。
	 */
#ifndef _ERROR_
	char buf[BUFF_SIZE] = {0};
#else
	char buf[size] = {0};
#endif
	read(fb,buf,sizeof(buf));
	fputs(buf,stdout);
	
	close(fb);
	// unlink("fifotest.p);
}

/*（1）命名管道通信过程中，若写进程先退出了，就算命名管道里没有数据，调用read()函数从FIFO里读数据时不阻塞。
 *     若写进程又重新运行，则调用read()函数从FIFO里读数据时又恢复阻塞。
 *（2）有名管道通信过程中，若读进程退出后，写进程向命名管道内写数据时，写进程会因为收到SIGPIPE信号而退出。
 */
void fifo_message()
{
	if(access("fifotest.p",F_OK) == -1)
	{
		if(mkfifo("./fifotest.p",0666) == -1)
		{
			puts("fifo_message error: mkfifo() failed");
			exit(-1);
		}
	}
	
	pid_t pid = fork();
	if(pid == -1)
	{
		perror("fifo_message error");
		_exit(-1);
	}
	else if(pid == 0)
	{
		printf("fifo_message: child process ,pid =%d ,ppid =%d\n",getpid(),getppid());
		
		int writefb = open("fifotest.p",O_WRONLY);
		if(writefb == -1)
		{
			puts("fifo_message error: child process open fifo failed");
			exit(-1);
		}
		
		for(int i=0;i<5;++i)   //子进程睡眠5s后才往命名管道中写数据，在没写入数据前，命名管道会读端read()阻塞。
		{
			printf("fifo_message: child process sleep ,i =%d\n",i);
			sleep(1);
		}
		
		struct Message msg = {getpid(),0,0};
		do{
			bzero(&msg.text,BUFF_SIZE);
			fputs("Please input text: \n",stdout);
			scanf("%s",msg.text);
			getchar();
			
			msg.textsize = strlen(msg.text) + 1;
			write(writefb,&msg,sizeof(int)*2 + msg.textsize);   //调用write()函数向FIFO里写数据，当缓冲区已满时write()也会阻塞。
			printf("child process write message: pid =%d ,textsize =%d ,text =%s\n",msg.pid,msg.textsize,msg.text);
		}while(strcmp(msg.text,"quit") != 0);
		
		fputs("fifo_message: child process exit\n",stdout);
		close(writefb);
		_exit(1);
	}
	else if(pid > 0)
	{
		fprintf(stdout,"fifo_message: parent process ,pid =%d ,spid =%d ,ppid =%d\n",getpid(),pid,getppid());
		
		int readfb = open("./fifotest.p",O_RDONLY);
		if(readfb == -1)
		{
			fprintf(stdout,"fifo_message error: %s\n",strerror(errno));
			
			kill(pid,SIGTERM);
			waitpid(pid,NULL,0);
			exit(-1);
		}
		
		struct Message msg = {-1,0,0};
		while(1)
		{
			memset(&msg,0,sizeof(msg));
			read(readfb,&msg,sizeof(struct Message));  //假如FIFO里没有数据，调用read()函数从FIFO里读数据时read()也会阻塞。这个特点和无名管道是一样的。
			
			fprintf(stdout,"parent process read message: pid =%d ,textsize =%d ,text =%s\n",msg.pid,msg.textsize,msg.text);
			if(strncmp(msg.text,"quit",msg.textsize) == 0)
			{
				break;
			}
		}
		
		puts("fifo_message: parent process quit\n");
		close(readfb);
		wait(NULL);
	}
}

//管道的两端默认是阻塞的，可以通过fcntl()将管道设置为非阻塞。
void fcntl_fifo()
{
	if(mkfifo("./fifotest.p",O_CREAT | O_EXCL | 0666) == -1)
	{
		perror("fcntl_fifo warn");
	}
	
	pid_t pid = fork();
	if(pid == -1)
	{
		printf("fcntl_fifo error: %s\n",strerror(errno));
		_exit(-1);
	}
	else if(pid == 0)
	{
		int wfb = open("./fifotest.p",O_WRONLY | O_TRUNC);
		if(wfb == -1)
		{
			puts("fcntl_fifo error: write only open() fifotest.p failed");
			return ;
		}
		
		sleep(2);   //子线程延时2s后，再往有名管道中写入数据，以测试读管道文件描述的非阻塞特性
		const char* msg = "fcntl() change fifo";
		write(wfb,msg,strlen(msg));
		
		close(wfb);
		exit(1);
	}
	else if(pid > 0)
	{
		int rfb = open("./fifotest.p",O_RDONLY);
		if(-1 == rfb)
		{
			fputs("fcntl_fifo error: read only open() fifotest.p failed\n",stdout);
			kill(pid,SIGKILL);
			wait(NULL);
			exit(-2);
		}
		
#ifndef _CHANGE_WAY_
		puts("fcntl_fifo: non-blocking fifo");
		int flag = fcntl(rfb,F_GETFL);    //获取管道读端的文件描述符的flag属性
		flag |= O_NONBLOCK;               //添加非阻塞属性到flag中
		fcntl(rfb,F_SETFL,flag);          //将新的flag属性设置给读端的文件描述符
#else
		fputs("fcntl_pipe: blocking pipe\n",stdout);
		fcntl(rfb,F_SETFL,0);             //设置管道的读端文件描述符为阻塞
#endif

		char buf[BUFF_SIZE] = {0};
		for(int i=0;i<5;++i)
		{
			read(rfb,buf,BUFF_SIZE);
			printf("receive [%s] from fifo ,i =%d\n",buf,i);
			
			sleep(1);
			bzero(buf,sizeof(buf));
		}
		
		close(rfb);
		waitpid(pid,NULL,0);   //阻塞等待回收子进程资源
	}
}