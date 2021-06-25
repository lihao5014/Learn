/*进程是一个程序的一次执行，是系统资源分配的最小单元。由于处于用户态的不同进程间是彼此隔离的，
 *但是它们很可能需要相互发送一些信息，好让对方知道自己的进度情况。进程间传递信息就叫进程间通信。
 */

/*1.为什么会有进程间通信：
 *（1）数据传输：一个进程需要将它的数据发送给另一个进程。
 *（2）共享数据：多个进程想要操作共享数据，一个进程对共享数据的修改，别的进程应该立刻看到。
 *（3）通知事件：一个进程需要向另一个或一组进程发送消息，通知它发生了某种事件。
 *（4）进程控制：一个进程希望控制另一个进程的运行。
 *（5）进程的数据空间是独立的、私有的、不能相互访问，但在某些情况下进程之间需要通信来实现某功能或交换数据。
 */

/*2.Linux进程间通信的6种方式：
 *（1）管道(Pipe)及有名管道(Named Pipe): 管道可用于具有"血缘"关系进程间的通信，即父子进程或兄弟进程间的通信。
 *     有名管道除具有管道所具有的功能外，还允许无"血缘"关系进程间的通信。
 *（2）信号(Signal): 信号是在软件层次上对中断机制的一种模拟，它是比较复杂的通信方式，用于通知进程有某事件发生。
 *     其实一个进程收到一个信号与处理器收到一个中断请求效果上可以说是一样的。
 *（3）信号量(Semaphore): 主要作为进程之间及同一进程的不同线程之间的同步和互斥手段。
 *（4）共享内存(Shared Memory): 可以说这是最有效的进程间通信方式。它使得多个进程可以访问同一块内存空间，
 *     不同进程可以及时看到对方进程中对共享内存中数据的更新。这种通信方式需要依靠某种同步机制，如互此锁和信号量等。
 *（5）消息队列(Messge Queue): 消息队列是消息的链表，包括Posix消息队列和System V消息队列。它克服了管道和信号通信方式
 *     中信息量有限的缺点。具有写权限的进程可以按照一定的规则向消息队列中添加消息；对消息队列具有读权限的进程则可以从
 *     消息队列中读取消息。
 *（6）套接字(Socket): 是一种更为一般的进程间通信机制，它可用于网络中不同机器之间的进程间通信，其应用相当广泛。
 */

/*3.管道通信：（管道是UNIX系统进程间通信IPC的最古老形式，所有的UNIX系统都支持这种通信机制）
 *（1）管道是Linux中进程间通信的一种方式，它把一个程序的输出直接连接到另一个程序的输入。Linux的管道主要包括两种：
 *     无名管道和有名管道。无名管道只能由父子进程使用，但是通过命名管道，不相关的进程也能交换数据。
 *（2）管道是单向的、先进先出的，它把一个进程的输出和另一个进程的输入连接在一起。一个进程在管道的尾部写入数据，
 *     另一个进程从管道的头部读出数据。当数据被一个进程读出后，将从管道中删除，其它读进程将不能再读到这些数据。
 *     管道提供了简单的流控制机制，进程试图读空管道时，进程将阻塞。同样管道已经满时，进程再试图向管道写入数据，
 *     进程也将阻塞。
 *（3）管道包括无名管道和有名管道两种。无名管道主要用于父进程和子进程间的通信，有名管道可用于运行于同一系统中的
 *     任意两个进程间的通信。
 */

/*4.匿名管道pipe的特点：（无名管道是Linux中管道通信的一种原始方法）
 *（1）它只能用于具有亲缘关系的进程之间的通信，也就是父子进程或者兄弟进程之间通信。
 *（2）它是一个半双工的通信模式，具有固定的读端和写端。
 *（3）管道也可以看成是一种特殊的文件，对于它的读写也可以使用普通的read()、write()等函数。但它不是普通的文件，
 *     并不属于其他任何文件系统并且只存在于内存中。
 */

/*5.pipe()函数的用法：
 *（1）函数原型：int pipe(int pipefd[2])。
 *（2）功能：创建一个匿名的管道, 得到两个可用的文件描述符。
 *（3）参数：传出参数，需要传递一个整形数组的地址，数组大小为2，也就是说最终会传出两个元素。
 *  ①pipefd[0]: 对应管道读端的文件描述符，通过它可以将数据从管道中读出。
 *  ②pipefd[1]: 对应管道写端的文件描述符，通过它可以将数据写入到管道中。
 *（4）返回值：成功返回0，失败返回-1。
 */

/*6.无名管道的使用：
 *（1）匿名管道是管道的一种，既然是匿名也就是说这个管道没有名字，但其本质是不变的，就是位于内核中的一块内存，
 *     匿名管道拥有管道的所有特性。匿名管道只能实现有血缘关系的进程间通信（父子进程、兄弟进程、爷孙进程或叔侄进程）。
 *（2）管道是基于文件描述符的通信方式。当一个无名管道建立时，它会创建两个文件描述符fd[0]和fd[1]，其中fd[0]固定
 *     用于读管道，而fd[1]固定用于写管道。
 *（3）匿名管道关闭时只需要将这两个文件描述符关闭即可，可使用普通的close()函数逐个关闭各个文件描述符。
 *（4）用pipe()创建的管道两端处于同一个进程中，由于管道主要是用于在不同的进程间通信的，因此在实际应用中没有太大意义。
 *     实际上通常先是创建一个管道，再调用fork()创建一个子进程，该子进程会继承父进程所创建的管道。此时父子进程分别拥有
 *     自己的读写通道，为了实现父子进程之间的读写，只需把无关的读端或写端的文件描述符关闭即可。将父进程的写端fd[1]和
 *     子进程的读端fd[0]关闭，则父子进程之间就建立起一条“子进程写入父进程读取”的通道。同样也可以将父进程的读端fd[0]和
 *     子进程的写端fd[1]关闭，则父子进程之间就建立起一条“父进程写入子进程读取”的通道。另外父进程还可以创建多个子进程，
 *     各个子进程都继承了相应的fd[0]和fd[1]，此时只需要关闭相应的端口就可以建立各子进程之间的的通道。
 */

/*7.匿名管道读写注意事项：
 *（1）使用匿名管道只能够实现有血缘关系的进程间通信，且必须要保证数据在管道中的单向流动。
 *（2）只有在管道的读端存在时，向管道写入数据才有意义。否则向管道写入数据的进程将收到内核传来的SIGPIPE信号
 *     （通常为Broken pipe错误）。
 *（3）向管道写入数据时，Linux将不保证写入的原子性，管道缓冲区一有空闲区域，写进程就会试图向管道写入数据。
 *     如果读进程不读取管道缓冲区中的数据，那么写进程将会一直阻塞。
 *（4）父子进程在运行时，它们的先后次序并不能确定。因此为了保证父子进程已经关闭了相应的文件描述符，可在两个进程中
 *     调用sleep()函数。当然使用进程休眠不是很好的解决方法，最好使用同步与互斥机制来保证父子进程间的运行顺序。
 */

/*8.匿名管道的使用步骤：
 *（1）在父进程中创建了匿名管道，得到了两个分配的文件描述符，fd3操作管道的读端，fd4操作管道的写端。
 *（2）父进程创建子进程，父进程的文件描述符被拷贝，在子进程的文件描述符表中也得到两个被分配的可以使用的文件描述符，
 *     通过fd3读管道、fd4写管道。此时匿名管道中数据的流动还不是单向的，存在4种流动情况。由于管道行为默认是阻塞的，
 *     假设子进程通过写端将数据写入管道，父进程的读端将数据读出，这种情况下子进程的读端就读不到数据，导致子进程阻塞
 *     在读管道的操作上，这样就会给程序的执行造成一些不必要的影响。如果没有打算让进程读或者写管道，那么就可以将进程
 *     操作的读端或者写端关闭。
 *（3）为了避免两个进程都读管道，但是可能其中某个进程由于读不到数据而阻塞的情况。我们可以关闭进程中用不到的那一端
 *     的文件描述符，这样数据就只能单向的从一端流向另外一端了。
 */

/*9.标准流管道：
 *（1）与Linux的文件操作中有基于文件流的标准I/O操作一样，管道的操作也支持基于文件流的的模式。这种基于文件流的
 *     管道主要是用来创建一个连接到另一个进程（一个可以进行一定操作的可执行文件）的管道。由于这类操作很常用，
 *     因此标准流管道就将一系列的创建过程合并到一个函数popen()中完成。
 *（2）popen()函数的使用可以大大减少代码的编写量，但同时也有一些不利之处。它不如管道创建的函数那样灵活多变，
 *    并且用popen()创建的管道必须使用标准I/O函数进行操作，而不能使用read()、write()一类不带缓冲的I/O函数。
 *    关闭用popen()创建的流管道必须使用函数pclose()，该函数关闭标准I/O流，并等待命令执行结束。
 */

/*10.popen()函数的工作过程：
 *（1）创建一个管道。
 *（2）fork()创建一个子进程。
 *（3）在父子进程中关闭不需要的文件描述符。
 *（4）执行exec函数族调用。
 *（5）执行函数中所指定的命令。
 *（6）将命令执行结果写入管道中。
 */

#include <unistd.h>       //fork(),dup(),dup2(),execlp()
#include <fcntl.h>        //fcntl()
#include <sys/types.h>    //pid_t,ssize_t
#include <sys/wait.h>     //wait(),waitpid(),WIFEXITED(),WEXITSTATUS()
#include <stdio.h>        //popen(),pclose()
#include <stdlib.h>       //exit(),malloc(),free(),system()
#include <string.h>       //strerror(),bzero()
#include <assert.h>
#include <errno.h>        //errno全局变量

#define _CHANGE_WAY_
#undef _CHANGE_WAY_

#define BUFF_SIZE 256

static void pipe_test();
static void pipe_count();
static void pipe_message();   //struct

static void pipe_communicate();
static void pipe_transmit();
static void popen_test();

static void mysystem(const char* cmd);
static void fcntl_pipe();

int main(void)
{
    // pipe_test();
    // pipe_count();
    
    // pipe_communicate();
    // pipe_transmit();
    // popen_test();
	// mysystem("ls -al");
	fcntl_pipe();
	
	return 0;
}

/*匿名管道主要用于具有血缘关系的进程间通信，同一个进程中使用匿名管道传输数据是没有意义的。
 *这里在同一个进程中使用匿名管道，只是为了学习匿名管道读写相关的API或系统调用。
 */
void pipe_test()
{
	int fb[2];
	if(pipe(fb) == -1)
	{
		printf("pipe_test error: %s\n",strerror(errno));
		_exit(-1);
	}
	
	//对无名管道写一次，读两次操作
	char buf[BUFF_SIZE] = {0};
	write(fb[1],"hello world\n",strlen("hello world\n"));    //fb[1]为匿名管道的写入端
	read(fb[0],buf,sizeof(buf));       //fb[0]为匿名管道的读取端。读取完成以后，管道中的数据就会被删除。
	write(STDOUT_FILENO,buf,strlen(buf));
	
	memset(buf,0,BUFF_SIZE);
	write(fb[1],"data is 2021.05.10\n",strlen("data is 2021.05.10\n"));

	ssize_t size = 0;
#ifndef _CHANGE_WAY_   //对管道写一次，读两次操作测试
	read(fb[0],buf,sizeof(buf));       //如果管道中的内容为空，那么读操作会阻塞
	write(STDOUT_FILENO,buf,strlen(buf));
	
	/*因为第一次读取时，就已经将pipe管道中的数据读取光了。所以第二次读取时，其实读的已经是空管道，
	 *对空管道的读取操作会造成进程阻塞。
	 */
	memset(buf,0,sizeof(buf));
	if((size = read(fb[0],buf,BUFF_SIZE)) > 0)   //管道连续读取两次，第二次读取时会阻塞，不会读取成功。
	{
		fwrite(buf,size,1,stdout);
	}
	else
	{
		puts("pipe_test: can't read anything from pipe");
	}
#else                  //对管道写两次，读一次操作测试
	/*因为第一次向无名管道中写入数据时，并没有将管道写满。所以第二次写入数据时，可以写入成功。
	 *只有管道已满时，再往里面写入数据，才会造成写操作阻塞。
	 */
	size = write(fb[1],"welcome linux\n",strlen("welcome linux\n"));     //管道中连续写两次，第二次写入时不会阻塞，会写入成功。
	if(size > 0)
	{
		read(fb[0],buf,BUFF_SIZE);     //读取完成以后，管道中的数据就会被删除。
		fwrite(buf,strlen(buf),1,stdout);
	}
	else
	{
		fputs("pipe_test: can't write anything to pipe\n",stdout);
	}
#endif
	
	close(fb[0]);
	close(fb[1]);
}

void pipe_count()
{
	int pipe_fb[2] = {-1,-1};
	if(pipe(pipe_fb) == -1)
	{
		fprintf(stdout,"pipe_count error: %s\n",strerror(errno));
		abort();
	}
	
	int sum = 0;
	pid_t pid = fork();
	if(pid == -1)
	{
		perror("pipe_count error: ");
		_exit(-1);
	}
	
	/*父进程刚fork()成功创建子进程时，管道中数据的流动还不是单向的，有4种流动方向：
     *（1）父进程通过fd4将数据写入管道，然后父进程再通过fd3将数据从管道中读出。
     *（2）父进程通过fd4将数据写入管道，然后子进程再通过fd3将数据从管道中读出。
     *（3）子进程通过fd4将数据写入管道，然后子进程再通过fd3将数据从管道中读出。
     *（4）子进程通过fd4将数据写入管道，然后父进程再通过fd3将数据从管道中读出。
     */
	if(pid == 0)
	{
		close(pipe_fb[0]);    //关闭子进程中多余的读端口，以使数据单向的从一端流向另外一端。
		fprintf(stdout,"pipe_count: child process ,pid =%d ,ppid =%d\n",getpid(),getppid());
		
		for(int i=0;i<50;++i)
		{
			sum += i;
		}
		
		printf("pipe_count: child process write data to pipe ,sum =%d\n",sum);
		write(pipe_fb[1],&sum,sizeof(int));
		
		puts("pipe_count: child process exit");
		close(pipe_fb[1]);
		exit(5);
	}
	else if(pid > 0)
	{
		close(pipe_fb[1]);   //关闭父进程中多余的写端口，以使数据单向的子进程的写端流向父进程的读端。
		fprintf(stdout,"pipe_count: parent process ,pid =%d ,cpid =%d ,ppid =%d\n",getpid(),pid,getppid());
		
		pid_t retpid = -1;
		int status,result = 0,i = 50;
		do{
			retpid = waitpid(pid,&status,WNOHANG);
			if(retpid == pid)
			{
				if(WIFEXITED(status))
				{
					printf("pipe_count: waitpid() ,child process exit code %d\n",WEXITSTATUS(status));
					
					read(pipe_fb[0],&result,sizeof(result));
					fprintf(stdout,"pipe_count: parent process read data from pipe ,result =%d\n",result);
				}
				else
				{
					const char* error = "pipe_count: child process exit unexpectedly\n";
					fwrite(error,strlen(error),1,stderr);
					exit(-2);
				}
			}
			
			sum += i;
		}while(i++ < 100);
		
		if(retpid != pid)
		{
			wait(&status);
			if(WIFEXITED(status))
			{
				printf("pipe_count: wait() ,child process exit code %d\n",WEXITSTATUS(status));
				
				read(pipe_fb[0],&result,sizeof(int));
				fprintf(stdout,"pipe_count: parent process read data from pipe ,result =%d\n",result);
			}
			else
			{
				const char info[] = "pipe_count: child process exit abnormally\n";
				write(STDERR_FILENO,info,strlen(info));
				_exit(-3);
			}
		}
		
		sum += result;
		printf("pipe_count: 0~100 sum is %d\n",sum);
		
		fputs("pipe_count: parent process finish\n",stdout);
		close(pipe_fb[0]);
	}
}

void pipe_communicate()
{
	int pipe_fb[2] = {-1,-1};
	if(pipe(pipe_fb) == -1)
	{
		perror("pipe_communicate error: ");
		return ;
	}
	
	pid_t pid = fork();
	if(-1 == pid)
	{
		puts("pipe_communicate error: fork() failed");
		_exit(-1);
	}
	else if(pid == 0)
	{
		close(pipe_fb[1]);
		printf("pipe_communicate: child process ,pid =%d ,ppid =%d\n",getpid(),getppid());
		
		sleep(1);   //子进程sleep()休眠1s，等待父进程将数据写入
		fputs("pipe_communicate: child process read data from pipe\n",stdout);
		
		ssize_t size = 0;
		char buf[BUFF_SIZE] = {0};
		if((size = read(pipe_fb[0],buf,BUFF_SIZE)) > 0)
		{
			puts(buf);
		}
		else
		{
			const char* error = "pipe_communicate: child process read() failed\n";
			fwrite(error,strlen(error),1,stderr);   //标准输入输出流（stdin/stdout）是行缓存的，stderr是无缓存的
		}
		
		puts("pipe_communicate: child process finish");
		close(pipe_fb[0]);
		exit(1);
	}
	else if(pid > 0)
	{
		close(pipe_fb[0]);
		fprintf(stdout,"pipe_communicate: parent process ,pid =%d ,spid =%d ,ppid =%d\n",getpid(),pid,getppid());
		
		const char* str = "Pipe test program\n";
		write(pipe_fb[1],str,strlen(str));
		
		char buf[BUFF_SIZE] = {0};
		sprintf(buf,"parent process: pid =%d ,spid =%d ,ppid =%d",getpid(),pid,getppid());
		write(pipe_fb[1],buf,strlen(buf));
		
		int status;
		int retpid = wait(&status);
		if(retpid == pid)
		{
			if(WIFEXITED(status))
			{
				printf("parent process recycle child process ,retpid =%d ,status =%d\n",retpid,WEXITSTATUS(status));
			}
			else
			{
				const char msg[] = "parent process: child process exit unexpectedly\n";
				write(STDERR_FILENO,msg,strlen(msg));
			}
		}
		else
		{
			fprintf(stdout,"parent process recycle other process ,retpid =%d\n",retpid);
		}
		
		fputs("pipe_communicate: parent process exit\n",stdout);
		close(pipe_fb[1]);
	}
}

/*管道的数据是单向流动的。如果操作管道的是两个进程，那么读管道进程需要关闭管道的写端，写管道进程需要关闭管道的读端。
 *如果不做该操作，会对程序的结果造成一些影响，对管道的操作无法结束。
 */
void pipe_transmit()
{
	int fb[2] = {-1,-1};
	if(pipe(fb) == -1)    //创建匿名管道, 得到两个文件描述符
	{
		printf("pipe_transmit error: %s\n",strerror(errno));
		abort();
	}
	
	//必须在系统调用fork()前调用pipe()，否则子进程将不会继承父进程中的文件描述符
	pid_t pid = fork();  //创建子进程。能够操作管道的文件描述符被复制到子进程中
	if(-1 == pid)
	{
		perror("pipe_transmit error: ");
		exit(-1);
	}
	else if(pid == 0)
	{
		close(fb[0]);   //关闭读端
		printf("pipe_transmit: child process ,pid =%d ,ppid =%d\n",getpid(),getppid());
		
		/*在子进程中完成输出的重定向，原来输出到终端现在要写管道。
		 *进程打印数据默认输出到终端，终端对应的文件描述符STDOUT_FILENO。
		 */
		if(dup2(fb[1],STDOUT_FILENO) != STDOUT_FILENO)   //将标准输出流重定向到管道的写入端
		{
			close(fb[1]);
			puts("pipe_transmit: dup2() failed");
			exit(-1);
		}
		
		close(fb[1]);  //子进程进程空间被替换前，关闭管道的读端
		if(execlp("ps","ps","-ef",NULL) == -1)
		{
			fputs("pipe_transmit: execlp() failed\n",stdout);
		}
		
		fputs("pipe_transmit: child process finish\n",stdout);  //如果进程替换函数execlp()执行成功，那么这条打印不会执行
		exit(-2);
	}
	else if(pid > 0)
	{
		close(fb[1]);  //关闭管道的写端
		fprintf(stdout,"pipe_transmit: parent process ,pid =%d ,cpid =%d ,ppid =%d\n",getpid(),pid,getppid());
		
		/*读管道时如果管道中没有数据，read()会阻塞。有数据之后read()解除阻塞，直接读数据。
         *需要循环读数据，因为管道是有容量的，写满之后就不写了。数据被读走之后，继续写管道，
		 *那么就需要再继续读数据。
		 */
		
		/*管道的写端关闭了，如果管道中没有数据，管道读端不会阻塞。
         *没数据直接返回0。如果有数据，将数据读出，数据读完之后返回0。
		 */
		int length = 0;
		char buf[16] = {0};
		while((length = read(fb[0],buf,sizeof(buf))) > 0)   //第一次读取管道中没有数据，也会阻塞
		{
			write(STDOUT_FILENO,buf,length);   //不能使用printf("%s",buf)替换，因为buf读取的字符串中可能不包含'\0'
			memset(buf,0,sizeof(buf));
		}
		
		close(fb[0]);   //父进程退出时，关闭管道的写端
		wait(NULL);     //回收子进程资源
		puts("pipe_transmit: parent process quit");
	}
}

//使用popen()函数来执行“ls -l”命令。使用popen()函数能让程序变得短小精悍。
void popen_test()
{
	FILE *fp = popen("ls -al","r");
	if(NULL == fp)
	{
		printf("popen_test error: popen() failed\n");
		return ;
	}
	
	char buf[128] = {0};
	while(fgets(buf,sizeof(buf),fp) != NULL)
	{
		fputs(buf,stdout);
		bzero(buf,sizeof(buf));
	}
	
	pclose(fp);
}

void mysystem(const char* cmd)
{
	assert(cmd != NULL);
	
	FILE *fp = popen(cmd,"r");
	if(fp == NULL)
	{
		perror("mysystem error: ");
		_exit(-1);
	}
	
	int size = 0;
	char buf[BUFF_SIZE] = {0};
	while((size = fread(buf,1,sizeof(buf),fp)) > 0)   //fread()一次读取一个字节才能读取文件的长度
	{
		fwrite(buf,size,1,stdout);
		memset(buf,0,BUFF_SIZE);
	}
}

/*通过fcntl()函数设置文件的阻塞特性：
 *（1）设置为阻塞：fcntl(fd,F_SETFL,0)。
 *（2）设置为非阻塞：fcntl(fd,F_SETFL,O_NONBLOCK)。
 */
void fcntl_pipe()
{
	int fb[2] = {-1,-1};
	if(pipe(fb) == -1)
	{
		puts("fcntl_pipe error: create pipe failed");
		abort();
	}
	
	pid_t pid = fork();
	if(pid == -1)
	{
		perror("fcntl_pipe error: ");
		return ;
	}
	else if(pid == 0)
	{
		close(fb[0]);
		sleep(2);
		
		const char info[] = "fcntl() modify pipe";
		write(fb[1],info,strlen(info));
		
		close(fb[1]);
		exit(1);
	}
	else if(pid > 0)
	{
		close(fb[1]);
#ifndef _CHANGE_WAY_
		puts("fcntl_pipe: non-blocking pipe");
		fcntl(fb[0],F_SETFL,O_NONBLOCK);   //设置管道的读端文件描述符为非阻塞
#else
		fputs("fcntl_pipe: blocking pipe\n",stdout);
		fcntl(fb[0],F_SETFL,0);            //设置管道的读端文件描述符为阻塞
#endif

		char buf[BUFF_SIZE] = {0};
		for(int i=0;i<5;++i)
		{
			read(fb[0],buf,BUFF_SIZE);
			printf("receive [%s] from pipe ,i =%d\n",buf,i);
			
			sleep(1);
			bzero(buf,sizeof(buf));
		}
		
		close(fb[0]);
		waitpid(pid,NULL,0);   //阻塞等待回收子进程资源
	}
}