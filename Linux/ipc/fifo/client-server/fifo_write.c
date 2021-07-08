/*1.命名管道概述：
 *（1）无名管道由于没有名字，只能用于亲缘关系的进程间通信。为了克服无名管道的缺点，提出了命名管道FIFO，
 *     也叫有名管道、FIFO文件。
 *（2）命名管道FIFO不同于无名管道之处在于它提供了一个路径名与之关联，以FIFO的文件形式存在于文件系统中，
 *     这样即使与FIFO的创建进程不存在亲缘关系的进程，只要可以访问该路径，就能够彼此通过FIFO相互通信，
 *     因此通过FIFO不相关的进程也能交换数据。
 *（3）有名管道拥有管道的所有特性，之所以称之为有名是因为管道在磁盘上有实体文件，文件类型为p。有名管道文件大小永远为0，
 *     因为有名管道也是将数据存储到内存的缓冲区中。打开磁盘上的管道文件，就可以得到操作有名管道的文件描述符，通过文件
 *     描述符读写管道存储在内核中的数据。有名管道也可以称为fifo(first in first out)，使用有名管道既可以进行有血缘关系
 *     的进程间通信，也可以进行没有血缘关系的进程间通信。创建有名管道的方式有两种，一种是通过命令，一种是通过函数。
 */

/*2.命名管道FIFO和无名管道pipe的区别:
 *（1）FIFO在文件系统中作为一个特殊的文件而存在，但FIFO中的内容却存放在内存中。
 *（2）当使用FIFO的进程退出后，FIFO文件将继续保存在文件系统中以便以后使用。
 *（3）FIFO有名字，不相关的进程可以通过打开命名管道进行通信。
 */
 
/*3.有名管道通信：
 *（1）不管是有血缘关系还是没有血缘关系，使用有名管道实现进程间通信的方式是相同的，就是在两个进程中分别以读写的方式
 *     打开磁盘上的管道文件，得到用于读管道或写管道的文件描述符，就可以调用对应的read()或write()函数进行读写操作了。
 *（2）有名管道操作需要通过调用open()得到读写管道的文件描述符。如果只是读端打开了或者只是写端打开了，进程会阻塞在这里
 *     不会向下执行，直到在另一个进程中将管道的对端打开，当前进程的阻塞才解除。所以当发现进程阻塞在了open()函数上不要
 *     感到惊讶。
 *（3）如果不想在open()打开命名管道的时候阻塞，可以使用可读可写方式打开FIFO文件，这样open()函数就不会阻塞。
 *（4）命名管道创建成功以后，就可以把命名管道当做普通文件一样进行open()、write()、read()、close()等操作。
 *     和无名管道一样，操作命名管道肯定要考虑默认情况下其阻塞特性。
 */

/*4.有名管道操作命令：
 *（1）创建有名管道：“mkfifo -m 666 有名管道名” 或 “mknod -m 666 命名管道名 p”。
 *（2）删除有名管道：“rm -rf 有名管道名” 或 “unlink 命名管道名”。
 */

/*5.管道的读写行为：（关于管道无论是有名的还是匿名的，在进行读写的时候，它们表现出的行为是一致的）
 *（1）读管道，需要根据写端的状态进行分析：
 *  ①写端没有关闭（操作管道写端的文件描述符没有被关闭）：
 *    如果管道中没有数据则读阻塞。如果管道中被写入了数据阻塞解除。
 *    如果管道中有数据不阻塞，管道中的数据被读完了，再继续读管道还会阻塞。
 *  ②写端已经关闭了（没有可用的文件描述符可以写管道了）：
 *    管道中没有数据 读端解除阻塞，read()函数返回0。
 *    管道中有数据read()先将数据读出，数据读完之后返回0，不会阻塞了。
 *（2）写管道，需要根据读端的状态进行分析：
 *  ①读端没有关闭：
 *    如果管道有存储的空间，一直写数据。
 *    如果管道写满了，写操作就阻塞，当读端将管道数据读走了，解除阻塞继续写。
 *  ②读端关闭了，管道破裂，进程直接退出。
 */

/*6.mkfifo()函数的用法：
 *（1）函数原型：int mkfifo( const char *pathname, mode_t mode)。
 *（2）功能：创建命名管道。
 *（3）pathname参数：普通的路径名，也就是创建后FIFO的名字。
 *（4）mode参数: 文件的权限，与打开普通文件的open()函数中的mode参数相同。
 *（5）返回值：成功返回0。如果文件已经存在，则会出错且返回-1。
 */

/*7.unlink()函数的用法：
 *（1）函数原型：int unlink(const char *pathname)。
 *（2）功能：从文件系统中删除一个名称。如果名称是文件的最后一个连接，并且没有其它进程将文件打开，
 *           名称对应的文件会实际被删除。
 *（3）pathname参数：指向需解除连接的文件名。
 *（4）返回值：成功执行返回0。失败返回-1，并设置errno全局变量的值。
 */
 
 #include <unistd.h>           //read(),write(),fork(),sleep()
#include <fcntl.h>            //creat(),open()
#include <sys/types.h>        //pid_t,ssize_t
#include <sys/stat.h>         //mkfifo(),mkdir()
#include <sys/wait.h>         //wait(),waitpid()
#include <stdio.h>
#include <stdlib.h>           //exit(),abort(),system()
#include <string.h>           //strerror()
#include <errno.h>

#define BUFF_SIZE 64

static void write_fifo();
static void fifo_count();

int main(int argc,char** argv)
{
	// write_fifo();
	fifo_count();
	
	return 0;
}

void write_fifo()
{
	char buf[BUFF_SIZE] = {0};
	sprintf(buf,"write_fifo: begin ,pid =%d\n",getpid());
	puts(buf);
	
	if(access("testfifo",F_OK) == -1)
	{
		if(mkfifo("testfifo",0666) == -1)   //最终创建命名管道的权限为(0666 & ~0022)
		{
			puts("write_fifo error: can't create fifo file");
			exit(-1);
		}
	}
	
	int fb = open("./testfifo",O_WRONLY);
	if(-1 == fb)
	{
		perror("write_fifo error");
		abort();
	}
	
	write(fb,"hello world\n",strlen("hello world\n"));
	write(fb,"welcome linux\n",strlen("welcome linux\n"));
	
	puts("write_fifo: end");
	close(fb);
}

void fifo_count()
{
	fprintf(stdout,"fifo_count: write start ,pid =%d\n",getpid());
	
	if(access("./count_fifo.p",F_OK) == -1)
	{
		if(mkfifo("count_fifo.p",0777) == -1)
		{
			printf("fifo_count error: %s\n",strerror(errno));
			_exit(-1);
		}
	}
	
	int fb = open("count_fifo.p",O_WRONLY | O_TRUNC);
	if(-1 == fb)
	{
		puts("fifo_count error: open count_fifo.p failed");
		return ;
	}
	
	int sum = 0;
	for(int i=1;i<50;++i)
	{
		sum += i;
	}
	
	printf("fifo_count: write sum =%d\n",sum);
	write(fb,&sum,sizeof(int));   //写管道进程正在写入数据时，读管道进程将阻塞。所以管道读写没有进程同步问题
	
	fputs("fifo_count: write end\n",stdout);
	close(fb);
}