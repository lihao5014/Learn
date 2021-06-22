/*1.信号概述：
 *（1）Linux中的信号是一种消息处理机制，它本质上是一个整数，不同的信号对应不同的值。由于信号的结构简单
 *     所以天生不能携带很大的信息量，但是信号在系统中的优先级是非常高的。
 *（2）信号可以实现进程间通信，但是信号能传递的数据量很少，不能满足大部分需求，另外信号的优先级很高，
 *     并且它对应的处理动作是回调完成的，它会打乱程序原有的处理流程，影响到最终的处理结果。因此非常
 *     不建议使用信号进行进程间通信。
 *（3）信号是Linux进程间通信的最古老的方式。信号是软件中断，它是在软件层次上对中断机制的一种模拟，
 *     是一种异步通信的方式。信号可以导致一个正在运行的进程被另一个正在运行的异步进程中断，转而处理
 *     某一个突发事件。在终端上敲“Ctrl+c”组合键，就产生一个“中断”，相当于产生一个信号，接着就会处理
 *     这么一个“中断任务”，默认的处理方式为中断当前进程。
 *（4）信号可以直接进行用户空间进程和内核空间进程的交互，内核进程可以利用它来通知用户空间进程发生了哪些系统事件。
 *     一个完整的信号周期包括三个部分：信号的产生、信号在进程中的注册、信号在进程中的注销、执行信号处理函数。
 *     注意这里信号的产生、注册、注销是信号的内部机制，而不是信号的函数实现。
 *（5）Linux中的每个信号产生之后都会有对应的默认处理行为，如果想要忽略或修改某个信号的默认行为就需要在程序中
 *     捕捉该信号。程序中进行信号捕捉可以看做是一个注册的动作，提前告诉应用程序信号产生之后做什么样的处理，
 *     当进程中对应的信号产生了，这个处理动作也就被调用了。
 *（6）如果linux执行一个信号处理函数的时候如果又收到一个不同种信号，会去执行新的信号处理函数，执行完之后再回来执行。
 */
 
/*2.信号的产生方式：
 *（1）当用户按某些终端键时，将产生信号：终端上按“Ctrl + c”组合键通常产生中断信号SIGINT，终端上按“Ctrl + \”键
 *     通常产生中断信号SIGQUIT，终端上按“Ctrl + z”键通常产生中断信号SIGSTOP等。
 *（2）硬件异常将产生信号：除数为0、无效的内存访问等。这些情况通常由硬件检测到，并通知内核，然后内核产生适当的
 *     信号发送给相应的进程。
 *（3）软件异常将产生信号：当检测到某种软件条件已发生，并将其通知有关进程时，产生信号。
 *（4）调用kill()函数将发送信号：注意接收信号进程和发送信号进程的所有者必须相同，或发送信号进程的所有者必须是超级用户。
 *（5）运行kill命令将发送信号：kill命令实际上是使用kill函数来发送信号。常用此命令终止一个失控的后台进程。
 */

/*3.Linux中查看信号的相关命令：
 *（1）通过“kill -l”命令可以查看系统定义的信号编号。
 *（2）通过“man 7 signal”命令可以查询所有信号的详细信息。
 *（3）编号为1 ~ 31的信号为传统UNIX支持的信号，是不可靠信号（非实时的），编号为32 ~ 63的信号是后来扩充的，
 *     称做可靠信号（实时信号）。不可靠信号和可靠信号的区别在于前者不支持排队，可能会造成信号丢失，而后者不会。
 *     非可靠信号一般都有确定的用途及含义, 可靠信号则可以让用户自定义使用。
 */
 
/*4.信号的5种默认处理动作:（有些信号在不同的平台对应的值是不一样的，对应使用PC机来说，需要看中间一列的值）
 *（1）Term：信号将进程终止。
 *（2）Ign：信号产生之后默认被忽略了。
 *（3）Core：信号将进程终止，并且生成一个core文件（一般用于gdb调试）。
 *（4）Stop：信号会暂停进程的运行。
 *（5）Cont：信号会让暂停的进程继续运行。
 *（6）9号信号SIGKILL和19号信号SIGSTOP不能被捕捉、阻塞和忽略。9号信号SIGKILL - 无条件杀死进程。
 *     19号信号SIGSTOP - 无条件暂停进程。
 *（7）当系统捕捉到某个信号时，可以忽略该信号或使用指定的处理函数来处理该信号，或者使用系统默认的方式。
 */

/*5.信号的3种状态：
 *（1）产生：键盘输入、函数调用、执行shell命令、对硬件进行非法访问都会产生信号。
 *（2）未决：信号产生了，但是这个信号还没有被处理掉，这个期间信号的状态称之为未决状态。
 *（3）递达：信号被某个进程处理了。
 */

/*6.进程处理信号的3中方式：（SIGKILL和SIGSTOP不能更改信号的处理方式，因为它们向用户提供了一种使进程终止的可靠方法）
 *（1）执行系统默认动作：对大多数信号来说，系统默认动作是用来终止该进程。
 *（2）忽略此信号：接收到此信号后没有任何动作。
 *（3）执行自定义信号处理函数：用用户定义的信号处理函数处理该信号。
 */

/*7.信号的常用操作：
 *（1）发送信号kill()：
 *  ①函数原型：int kill(pid_t pid, int signum)。
 *  ②功能：给指定进程发送信号。kill()既可以向自身发送信号，也可以向其他进程发送信号，而raise()是向进程自身发送信号。
 *          注意使用kill()发送信号，接收信号进程和发送信号进程的所有者必须相同，或者发送信号进程的所有者是超级用户。
 *  ③pid参数：（pid取值有4种情况）
 *             pid > 0：将信号传送给进程ID为pid的进程。
 *             pid = 0：将信号传送给当前进程所在进程组中的所有进程。常用于父进程给子进程发送信号，
 *                      注意发送信号者进程也会收到自己发出的信号。
 *             pid = -1：将信号传送给系统内所有的进程。
 *             pid < -1：将信号传给指定进程组的所有进程，这个进程组号等于pid的绝对值。
 *  ④signum参数: 发送信号的编号，可以填数字编号，也可以填信号的宏定义，可以通过命令“kill -l”进行相应查看。如果signum = 0
 *                则没有任何信号送出，但是系统会执行错误检查。通常会利用signum值为0来检验某个进程是否仍在运行。
 *  ⑤返回值：成功返回0，失败返回-1。
 *（2）等待信号pause()：
 *  ①函数原型：int pause()。
 *  ②功能：阻塞进程等待信号的到来。将调用进程挂起直至捕捉到信号为止，此函数通常用于判断信号是否已到。
 *  ③返回值：直到捕获到信号才返回-1，且errno被设置成EINTR。
 *（3）处理信号signal()：
 *  ①函数原型：
 *    typedef void (*sighandler_t)(int)。
 *    sighandler_t signal(int signum,sighandler_t handler)。
 *  ②功能：注册信号处理函数，即确定收到信号后处理函数的入口地址。此函数不会阻塞。
 *          signal()函数不可用于SIGKILL和SIGSTOP信号。
 *  ③handler参数：（handler取值有3种情况）
 *                 SIG_IGN：忽略该信号。
 *                 SIG_DFL：执行系统默认动作。
 *                 信号处理函数名：自定义信号处理函数，信号的编号为这个自定义函数的参数。信号处理函数应该为可重入函数。
 *  ④返回值：成功第一次返回NULL，下一次返回此信号上一次注册的信号处理函数的地址。如果需要使用此返回值，
 *            必须在前面先声明此函数指针的类型。失败返回SIG_ERR。
 */

/*8.void (*signal(int sig, void (*func)(int)))(int)信号处理函数原型的理解：
 *（1）signal( int sig, void (*func)(int))：
 *     signal是一个函数，有2个参数，第一个是int类型，第二个参数是一个函数指针。
 *（2）void (*signal(int sig, void (*func) (int)))(int)：
 *     signal仍然是一个函数，他返回一个函数指针，这个指针指向的函数没有返回值，只有一个int类型的参数。
 *（3）简化：typedef void (*sighandler_t)(int); sighandler_t signal(int signum,sighandler_t handler)。
 */

/*9.定时器setitimer():
 *（1）函数原型：int setitimer(int which, const struct itimerval *new_value, struct itimerval *old_value)。
 *（2）功能：setitimer()函数可以进行周期性定时，每触发一次定时器就会发射出一个信号。
 *（3）which参数: 定时器使用什么样的计时法则，不同的计时法则发出的信号不同。
 *  ①ITIMER_REAL: 自然计时法，发出的信号为SIGALRM, 一般使用这个宏值。自然计时法时间 = 用户区 + 内核 + 消耗的时间。
 *                 其中消耗的时间等于从进程的用户区到内核区切换使用的总时间。
 *  ②ITIMER_VIRTUAL: 只计算程序在用户区运行使用的时间，发射的信号为SIGVTALRM。
 *  ③ITIMER_PROF: 只计算内核运行使用的时间，发出的信号为SIGPROF。
 *（4）new_value参数: 给定时器设置的定时信息，传入参数。
 *（5）old_value参数: 上一次给定时器设置的定时信息，传出参数，如果不需要这个信息，指定为NULL。
 *（6）返回值：成功返回0，失败返回-1，并把错误号写到errno变量中。
 *
 *（7）itimerval结构体的定义：
 *  struct itimerval {
 *      struct timeval it_interval;   //时间间隔
 *      struct timeval it_value;      //第一次触发定时器的时长
 *  };
 *
 *（8）timeval结构体的定义：（timeval结构体表示的是一个时间段: tv_sec + tv_usec）
 * struct timeval {
 *     time_t      tv_sec;         //秒
 *     suseconds_t tv_usec;        //微妙
 * };
 */

/*10. 阻塞信号集和未决信号集:
 *（1）在PCB中有两个非常重要的信号集。一个称之为 “阻塞信号集”，另一个称之为 “未决信号集”。这两个信号集体现
 *     在内核中就是两张表。但是操作系统不允许我们直接对这两个信号集进行任何操作，而是需要自定义另外一个集合，
 *     借助信号集操作函数来对PCB中的这两个信号集进行修改。
 *（2）信号的“未决”是一种状态，指的是从信号的产生到信号被处理前的这一段时间。
 *（3）信号的“阻塞”是一个开关动作，指的是阻止信号被处理，但不是阻止信号产生。信号的阻塞就是让系统暂时保留信号，
 *     留待以后发送。由于另外有办法让系统忽略信号，所以一般情况下信号的阻塞只是暂时的，只是为了防止信号打断某
 *     些敏感的操作。
 *（4）阻塞信号集和未决信号集在内核中的结构是相同的，它们都是一个整形数组（被封装过的），一共128字节，1024个标志位，
 *     其中前31个标志位，每一个都对应一个Linux中的标准信号。通过标志位的值来标记当前信号在信号集中的状态。
 *（5）在阻塞信号集中，描述这个信号有没有被阻塞。默认情况下没有信号是被阻塞的，因此信号对应的标志位的值为0。
 *     如果某个信号被设置为了阻塞状态，这个信号对应的标志位 被设置为1。
 *（6）在未决信号集中，描述信号是否处于未决状态。如果这个信号被阻塞了，不能处理，这个信号对应的标志位被设置为1。
 *     如果这个信号的阻塞被解除了，未决信号集中的这个信号马上就被处理了，这个信号对应的标志位值变为0。如果这个
 *     信号没有阻塞，信号产生之后直接被处理，因此不会在未决信号集中做任何记录。
 */

/*11.信号集函数：
 *（1）因为用户是不能直接操作内核中的阻塞信号集和未决信号集的，必须要调用系统函数。关于阻塞信号集可以通过系统函数
 *     进行读写操作，未决信号集只能对其进行读操作。
 *（2）未决信号集不需要程序员修改，如果设置了某个信号阻塞，当这个信号产生之后，内核会将这个信号的未决状态记录到
 *     未决信号集中。当阻塞的信号被解除阻塞，未决信号集中的信号随之被处理，内核再次修改未决信号集将该信号的状态
 *     修改为递达状态（标志位置0）。因此写未决信号集的动作都是内核做的，但可使用sigpending()读取未决信号集。
 *（3）sigprocmask()函数的用法：
 *  ①函数原型：int sigprocmask(int how, const sigset_t *set, sigset_t *oldset)。
 *  ②功能：读写阻塞信号集，即使用sigprocmask()函数可以修改内核中的阻塞信号集。
 *  ③how参数：（how取值有3种情况）
 *             SIG_BLOCK: 将参数set集合中的数据追加到阻塞信号集中。
 *             SIG_UNBLOCK: 将参数set集合中的信号在阻塞信号集中解除阻塞。
 *             SIG_SETMASK: 使用参set结合中的数据覆盖内核的阻塞信号集数据。
 *  ④set参数：指定信号集。在sigprocmask()中，若set是一个非空指针，则参数how表示函数的操作方式。
 *             若set为空，则表示忽略此操作，不改变信号阻塞集合。
 *  ⑤oldset参数: 通过这个参数将设置之前的阻塞信号集数据传出，如果不需要可以指定为NULL。
 *  ⑥返回值：函数调用成功返回0，调用失败返回-1。
 *（4）sigpending()函数的用法：
 *  ①函数原型：int sigpending(sigset_t *set)。
 *  ②功能：读取未决信号集。
 *  ③set参数：是一个传出参数，传出的内核未决信号集的拷贝。读一下这个集合就知道哪个信号是未决状态。
 */

/*12.信号集相关操作函数：（sigprocmask()有一个sigset_t类型的参数set，对set进行初始化就需要调用创建信号集函数）
 *（1）int sigemptyset(sigset_t *set)。                    //将set集合中所有的标志位设置为0
 *（2）int sigfillset(sigset_t *set)。                     //将set集合中所有的标志位设置为1
 *（3）int sigaddset(sigset_t *set, int signum)。          //将set集合中某一个信号(signum)对应的标志位设置为1
 *（4）int sigdelset(sigset_t *set, int signum)。          //将set集合中某一个信号(signum)对应的标志位设置为0
 *（5）int sigismember(const sigset_t *set, int signum)。  //判断某个信号在集合中对应的标志位到底是0还是1，如果是0返回0，如果是1返回1
 *（6）如果在程序中读写sigset_t类型的变量。阻塞信号集和未决信号集都存储在sigset_t类型的变量中，这个变量对应一块内存。
 *     阻塞信号集和未决信号集, 对应的内存中有1024bit = 128字节。
 */

/*13.可靠信号的操作：
 *（1）从UNIX系统继承过来的信号（SIGHUP~SIGSYS，前32个）都是不可靠信号，不支持排队，多次发送相同的信号，
 *     进程可能只能收到一次，可能会丢失。SIGRTMIN至SIGRTMAX的信号支持排队，发多少次，就可以收到多少次，
 *     不会丢失，故称为可靠信号。可靠信号就是实时信号，非可靠信号就是非实时信号。
 *（2）signal()函数只能提供简单的信号安装操作，使用signal()处理信号比较简单，只要把要处理的信号和处理函数列出即可。
 *     signal()函数主要用于前面32种不可靠，非实时信号的处理，并且不支持信号传递信息。
 *（3）Linux提供了功能更强大的sigaction()函数，可以用来检查和更改信号处理操作，可以支持可靠、实时信号的处理，
 *     并且支持信号传递信息。
 */

/*14.sigaction()函数的用法：
 *（1）函数原型：int sigaction(int signum,const struct sigaction *act, struct sigaction *oldact )。
 *（2）功能：检查或修改指定信号的设置（或同时执行这两种操作）。
 *（3）signum参数：要操作的信号
 *（4）act参数：要设置的对信号的新处理方式。
 *（5）oldact参数：原来对信号的处理方式。如果act指针非空，则要改变指定信号的处理方式。
 *                 如果oldact指针非空，则系统将此前指定信号的处理方式存入oldact。
 *（6）返回值：成功返回0，失败返回-1。
 *
 *（7）sigaction结构体的定义：
 *  struct sigaction {
 *      void (*sa_handler)(int signum);                                    //旧的信号处理函数指针
 *      void (*sa_sigaction)(int signum, siginfo_t *info, void *context);  //新的信号处理函数指针
 *      sigset_t sa_mask;                                                  //信号阻塞集
 *      int sa_flags;                                                      //信号处理的方式
 *  };
 *  ①sa_handler/sa_sigaction：信号处理函数指针和signal()里的函数指针用法一样，应根据情况给它们两者之一赋值。
 *                             SIG_IGN：忽略该信号。
 *                             SIG_DFL：执行系统默认动作。
 *                             处理函数名：自定义信号处理函数。
 *  ②sa_mask：信号阻塞集。
 *  ③sa_flags：用于指定信号处理的行为，它可以是一下值的“按位或”组合。
 *              SA_RESTART：使被信号打断的系统调用自动重新发起（已经废弃）。
 *              SA_NOCLDSTOP：使父进程在它的子进程暂停或继续运行时不会收到SIGCHLD信号。
 *              SA_NOCLDWAIT：使父进程在它的子进程退出时不会收到SIGCHLD信号，这时子进程如果退出也不会成为僵尸进程。
 *              SA_NODEFER：使对信号的屏蔽无效，即在信号处理函数执行期间仍能发出这个信号。
 *              SA_RESETHAND：信号处理之后重新设置为默认的处理方式。
 *              SA_SIGINFO：使用sa_sigaction成员而不是sa_handler作为信号处理函数。
 *
 *（8）信号处理函数：void (*sa_sigaction)(int signum,siginfo_t *info,void *context)
 *  ①signum：信号的编号。
 *  ②info：记录信号发送进程信息的结构体。
 *  ③context：可以赋给指向ucontext_t类型的一个对象的指针，以引用在传递信号时被中断的接收进程或线程的上下文。
 *
 *（9）siginfo_t结构体的定义：
 *  typedef struct {
 *      int si_signo;           //信号编号。
 *      int si_code;            //说明进程如何接收信号以及从何处收到。
 *      union sigval si_value;  //用于传输数据。等于sigqueue()函数中传入的第三个参数sigval。
 *      int si_errno;           //如果为非零值则错误代码与之关联，即errno。
 *      pid_t si_pid;           // 发送信号的进程号pid
 *      uid_t si_uid;           //发送信号的用户号uid
 *      void *si_addr;          //错误发生的地址。
 *      int si_status;          //适用于SIGCHLD，代表被终止进程的状态。
 *      int si_int;             //从sigqueue()函数中传入的第三个参数sigval.sival_int中获得。
 *      void *si_ptr;           //从sigqueue()函数中传入的第三个参数sigval.sival_ptr中获得。
 *  }siginfo_t;
 *
 *（10）sa_sigaction和sa_handler的区别：
 *  ①由于sa_handler指定的处理函数只有一个参数，即信号值，所以信号不能传递除信号值之外的任何信息。
 *    由于sa_sigaction指定的信号处理函数带有三个参数，是为实时信号而设的，但是同样支持非实时信号。
 *    它的第一个参数为信号值。第二个参数是指向siginfo_t结构的指针，该结构体中包含信号携带的数据值。
 *    第三个参数没有使用，posix没有规范使用该参数的标准。
 *  ②sa_handler主要用于不可靠信号，实时信号当然也可以，只是不能带信息。sa_sigaction用于实时信号
 *    可以带siginfo_t信息。但它们两者不能同时出现。
 */

/*15.sigqueue()函数的用法：（sigqueue()比kill()传递了更多的附加信息，但sigqueue()只能向一个进程发送信号，而不能发送信号给一个进程组）
 *（1）函数原型：int sigqueue(pid_t pid, int sig, const union sigval value)。
 *（2）功能：新的发送信号系统调用，主要是针对实时信号提出的支持信号带有参数，与函数sigaction()配合使用。
 *（3）pid参数: 进程号。
 *（4）sig参数: 信号的编号，这里可以填数字编号，也可以填信号的宏定义，可以通过命令“kill -l”进行相应查看。
 *（5）value参数: 通过信号传递的参数，即通常所说的4字节值。
 *（6）返回值：成功返回0，失败返回-1。
 *
 *（7）sigval共用体的定义：（sigval共用体中要么持有一个4字节的整数值，要么持有一个指针）
 *  union sigval
 *  {
 *  	int   sival_int;      //用于传递简单整形数据。
 *  	void  *sival_ptr;     //用于传递任意类型的大规模数据。
 *  };
 */

/*16.SIGCHLD信号：（子进程改变状态时，父进程就会收到SIGCHLD信号）
 *当子进程退出、暂停、从暂停恢复运行的时候，在子进程中会产生一个SIGCHLD信号，并将其发送给父进程。
 *但是父进程收到这个信号之后默认就忽略了。可以在父进程中对该信号加以利用，以实现回收子进程的资源，
 *因此需要在父进程中捕捉子进程发送过来的SIGCHLD信号。
 */
 
#include <unistd.h>       //fork(),_exit(),read(),write(),alarm()
#include <signal.h>       //kill(),raise(),signal(),sigaction(),sigqueue()
#include <sys/types.h>    //pid_t,ssize_t
#include <sys/wait.h>     //wait(),waitpid()
#include <sys/time.h>     //setitimer()
#include <stdio.h>
#include <stdlib.h>       //exit(),abort()
#include <string.h>       //strerror()
#include <errno.h>

#define _CHANGE_WAY_
// #undef _CHANGE_WAY_

typedef enum Color_t
{
	RED,
	YELLOW,
	BLUE
}Color_t;

static void handle(int signo);
static void timeout(int signo);
static void deal_with(int signo);
static void dispose(int signum,siginfo_t *info,void *context);
static void recycle(int signo);

#ifndef _CHANGE_WAY_
static void (*mysignal(int signo,void (*pfun)(int)))(int);
#else
typedef void (*pFun)(int signo);

pFun mysignal(int signo,pFun pfun);
#endif

static void mysignal_test();
static void setitimer_test();
static void sigaction_test();
static void sigprocmask_test();
static void sigqueue_test();
static void resource_collect();

int main(int argc,char* argv[])
{
	// mysignal_test();
	// setitimer_test();
	// sigaction_test();
	// sigprocmask_test();
	// sigqueue_test();
	resource_collect();
	
	return 0;
}

static void handle(int signo)
{
	printf("handler: the signal number is %d\n",signo);
	
	switch(signo){
	case RED:
		puts("red");
		break;
	case YELLOW:
		fputs("yellow\n",stdout);
		break;
	case BLUE:
		fwrite("blue\n",strlen("blue\n"),1,stdout);
		break;
	default:
		write(STDOUT_FILENO,"parse failed\n",strlen("parse failed\n"));
	}
}

void timeout(int signo)
{
	printf("timeout: signal arrive ,signo = %d\n",signo);
}

static void deal_with(int signo)
{
	fprintf(stdout,"deal_with: signo =%d\n",signo);
	
	switch(signo){
	case SIGINT:
		puts("SIGINT: ctrl + c");
		break;
	case SIGQUIT:
		fputs("SIGQUIT: ctrl + \\ \n",stdout);
		break;
	case SIGTERM:
		printf("SIGTERM: kill + pid\n");
		break;
	default:
		fprintf(stdout,"don't know signal\n");
	}
}

//新的信号处理函数多了两个参数，其中signfo_t里面携带了我们想要的数据
void dispose(int signum,siginfo_t *info,void *context)
{
	printf("dispose: signum =%d ,",signum);                 //打印信号编号。
	fprintf(stdout,"info->si_pid =%d ,",info->si_pid);      //打印发送信号的进程号。
#ifndef _CHANGE_WAY_
	// printf("info->si_int =%d\n", info->si_int);            //打印通过信号传递过来的简单整形数据。
    printf("info->si_value.sival_int =%d\n", info->si_value.sival_int);
#else
	// printf("info->si_ptr =%s\n", (char*)info->si_ptr);              //打印通过信号传递过来的指针数据。
    printf("info->si_value.sival_ptr =%s\n", (char*)info->si_value.sival_ptr);
#endif
}

/*使用非阻塞方式回收子进程的资源。因为SIGCHLD为17号信号，1-31号信号都不支持排队。如果这些信号同时产生多个，
 *最终处理的时候只处理一次。假设多个子进程同时退出，父进程同时收到了多个SIGCHLD信号，父进程只会处理一次该信号，
 *recycle()函数只被调用一次。waitpid被调用一次相当于只回收了一个子进程，但同时死了多个子进程，就出现了僵尸进程。
 */
void recycle(int signo)
{
	printf("recycle: pid =%d ,signo =%d\n",getpid(),signo);
	
	for(;;)
	{
		pid_t retpid = waitpid(-1,NULL,WNOHANG);  //使用waitpid()非阻塞轮询的方式，回收子进程的退出资源
		if(retpid > 0)
		{
			printf("recycle: child process died ,retpid =%d\n",retpid);
		}
		else if(retpid == 0)  //没有死亡的子进程, 直接退出当前循环
		{
			puts("recycle: child process running");
			break;
		}
		else if(retpid == -1)
		{
			fputs("recycle: don't have child process to collecte\n",stdout);
			break;
		}
	}
}

#ifndef _CHANGE_WAY_
void (*mysignal(int signo,void (*pfun)(int)))(int)
{
	if(pfun == NULL)
	{
		puts("mysignal error: pfun is null");
		return NULL;
	}
	
	printf("mysignal: start ,pid =%d\n",getpid());
	pfun(signo);
	
	fprintf(stdout,"mysignal: end ,pid =%d\n",getpid());
	return pfun;
}
#else
pFun mysignal(int signo,pFun pfun)
{
	if(pfun == NULL)
	{
		puts("mysignal error: pfun is illegal");
		return NULL;
	}
	
	printf("mysignal: begin ,pid =%d\n",getpid());
	pfun(signo);
	
	fprintf(stdout,"mysignal: finish ,pid =%d\n",getpid());
	return pfun;
}
#endif

void mysignal_test()
{
	(*mysignal(RED,handle))(BLUE);
	
#ifndef _CHANGE_WAY_
	void (*pfun)(int) = mysignal(YELLOW,handle);
	pfun(RED);
#else
	pFun pfun = mysignal(BLUE,handle);
	pfun(YELLOW);
#endif
}

void setitimer_test()
{
	fprintf(stdout,"setitimer_test: enter ,pid =%d\n",getpid());
	signal(SIGALRM,timeout);
	
	/*itimerval结构体中，it_value表示设置定时器后间隔多久开始执行定时任务，
	 *而it_interval表示两次定时任务之间的时间间隔。
	 */
	struct itimerval itv = {0,0};
	itv.it_interval.tv_sec = 1;
	itv.it_interval.tv_usec = 500;
	itv.it_value.tv_sec = 3;
	itv.it_value.tv_usec = 0;
	
	printf("setitimer_test: delay %lds start timer\n",itv.it_value.tv_sec);
	printf("setitimer_test: timer interval %fs\n",itv.it_interval.tv_sec + (double)itv.it_interval.tv_usec/1000);
	
	//setitimer()函数可以实现周期性定时, 每个一段固定的时间, 发出一个特定的定时器信号
	if(setitimer(ITIMER_REAL,&itv,NULL) == -1)
	{
		perror("setitimer_test error: ");
		_exit(-1);
	}
	
	for(int i=0;i<10;++i)
	{
		puts("setitimer_test: do something");
		sleep(1);
	}
	
	printf("setitimer_test: leave ,pid =%d\n",getpid());
}

void sigaction_test()
{
	char buf[64] = {0};
	sprintf(buf,"sigaction_test: entry ,pid =%d",getpid());
	puts(buf);
	
	struct sigaction action;   //定义sigaction结构体
	puts("sigaction_test: waiting for signal SIGINT or SIGQUIT...");
	
	//初始化sigaction结构体
	action.sa_handler = deal_with;   //指定信号处理函数
	action.sa_flags = SA_NOMASK;      //指定使用sa_handler函数指针处理信号
	sigemptyset(&action.sa_mask);    //信号阻塞集sa_mask清空
	
	//注册信号处理函数，即指定发出哪些信号会跳转到信号处理函数
	sigaction(SIGINT,&action,0);
	sigaction(SIGQUIT,&action,0);
	sigaction(SIGTERM,&action,0);
	
	pause();
	puts("the frist pause");
	
	pause();
	fputs("the second pause\n",stdout);
	
	fprintf(stdout,"sigaction_test: exit ,pid =%d\n",getpid());
}

void sigprocmask_test()
{
	printf("sigprocmask_test: begin ,pid =%d\n",getpid());
	
	sigset_t blockset;        //创建信号集
	sigemptyset(&blockset);   //清空信号集
	
	sigaddset(&blockset,SIGINT);   //将SIGINT信号加入blockset信号集中
	sigaddset(&blockset,SIGQUIT);
	sigaddset(&blockset,SIGALRM);
	
	if(sigismember(&blockset,SIGINT) == 1)
	{
		puts("SIGINT in blockset");
	}
	else
	{
		fputs("SIGINT out of blockset\n",stdout);
	}
	
	struct sigaction action;       //新建信号安装结构体
	sigemptyset(&action.sa_mask);
	action.sa_handler = deal_with;
	action.sa_flags = SA_NOMASK;
	
	sigaction(SIGINT,&action,NULL);    //注册SIGINT信号的处理动作
	sigaction(SIGQUIT,&action,NULL);   //将信号和安装信号结构体关联
	sigaction(SIGALRM,&action,NULL);
	
	sigprocmask(SIG_BLOCK,&blockset,NULL);  //blockset信号集加入阻塞集，在没有移除前，SIGINT、SIGQUIT和会SIGALRM被阻塞
	
	/*向自身进程发送SIGINT信号。由于SIGINT信号被设置在进程的阻塞信号集中，所以即使发出了SIGINT信号，
	 *也得不到立即处理。它会被添加到未决信号集中，等待取消阻塞状态时再被执行。
	 */
	raise(SIGINT);
	kill(getpid(),SIGQUIT);  //由于SIGQUIT信号被在阻塞信号集中，所以kill()发送了SIGQUIT以后，它将被添加到未决信号集中。
	alarm(2);
	fputs("sigprocmask_test: emit SIGINT ,SIGQUIT and SIGALRM\n",stdout);
	
	int count = 0;
	do{
		puts("sigprocmask_test: running");
		sleep(1);   //为了降低CPU使用率
	}while(count++ < 5);
	
	sigset_t pendset;
	sigpending(&pendset);   //获取未决信号集
	
	//循环遍历前32个信号，以判断哪些信号在未决信号集中，正等待被处理
	for(int i=1;i<=32;++i)
	{
		if(sigismember(&pendset,i) == 1)
		{
			printf("pending signal: %d\n",i);
		}
	}
	
	if(sigismember(&blockset,SIGINT) == 1)
	{
		printf("SIGINT in pendset ,signo =%d\n",SIGINT);
	}
	else
	{
		puts("SIGINT out of pendset");
	}
	
	//blockset信号集从阻塞集中移除。SIGINT信号在被阻塞时发生了，此刻SIGINT信号将立马生效，执行信号处理函数
	sigprocmask(SIG_UNBLOCK,&blockset,NULL);
	
	sleep(2);   //睡眠2s等待所有的信号都指向处理函数完。
	printf("sigprocmask_test: end ,pid =%d\n",getpid());
}

/*可以通过sigqueue()中传入sigval值来实现信号带值，然后在信号处理函数void (*sa_sigaction)(int signum,siginfo_t *info,void *context)中，
 *读取第二个参数info中对应变量的值来获取信号所带参数，通过这种方法实现进程间通讯。
 */
void sigqueue_test()
{
	pid_t pid = fork();
	if(pid == -1)
	{
		printf("sigqueue_test error: %s\n",strerror(errno));
		return ;
	}
	else if(pid == 0)
	{
		printf("sigqueue_test: child process ,pid =%d ,ppid =%d\n",getpid(),getppid());

		sigval_t value;
#ifndef _CHANGE_WAY_
		value.sival_int = 50;      //通过信号传递整形数据
		fprintf(stdout,"sigqueue_test: send signal to parent process ,value.sival_int =%d\n",value.sival_int);
#else
	    value.sival_ptr = "hello world";   //通过信号传递字符串
		fprintf(stdout,"sigqueue_test: send signal to parent process ,value.sival_ptr =%s\n",(char*)value.sival_ptr);
#endif
		sigqueue(getppid(),SIGINT,value);    //给父进程发送SIGINT信号，并把value值传递过去
		
		puts("sigqueue_test: child process exit");
		exit(2);
	}
	else if(pid > 0)
	{
		printf("sigqueue_test: parent process ,pid =%d ,spid =%d ,ppid =%d\n",getpid(),pid,getppid());
		
		struct sigaction action;
		sigemptyset(&action.sa_mask);   //清空信号阻塞集
		
		action.sa_sigaction = dispose;   //指定信号处理回调函数
		action.sa_flags = SA_SIGINFO;    //指定使用sa_sigaction函数指针作为信号处理函数。
		sigaction(SIGINT,&action,NULL);  //注册信号SIGINT的处理函数
		
		fputs("sigqueue_test: parent process pause to wait SIGINT\n",stdout);
		pause();   //阻塞父进程，等待子进程中发送的信号到来
		
		int status;
		wait(&status);    //等待回收子进程退出资源，以防止子进程退出后变为僵尸进程
		
		if(WIFEXITED(status))   //判断进程是正常退出
		{
			printf("sigqueue_test: child process exit code %d\n",WEXITSTATUS(status));   //WEXITSTATUS()得到进程退出时候的状态码。
		}
		
		if(WIFSIGNALED(status))  //判断进程是否被信号杀死
		{
			printf("sigqueue_test: child process terminate signal %d\n",WTERMSIG(status));  //WTERMSIG()获得进程是被哪个信号杀死的，会得到信号的编号。
		}
		
		const char info[] = "sigqueue_test: parent process exit\n";
		write(STDOUT_FILENO,info,strlen(info));
	}
}

void resource_collect()
{
	sigset_t blockset;
	sigemptyset(&blockset);
	sigaddset(&blockset,SIGCHLD);    //设置SIGCHLD信号阻塞
	sigprocmask(SIG_BLOCK,&blockset,NULL);
	
	pid_t pid = -1;
	for(int i=0;i<10;++i)   //循环创建5个子进程
	{
		pid = fork();
		if(pid == 0)  //只让父进程创建子进程，如果是子进程不让其继续创建子进程。
		{
			break;
		}
	}
	
	if(pid == 0)
	{
		printf("resource_collect: child process ,pid =%d ,ppid =%d\n",getpid(),getppid());
		_exit(-1);
	}
	else if(pid > 0)
	{
		fprintf(stdout,"resource_collect: parent process ,pid =%d ,cpid =%d ,ppid =%d\n",getpid(),pid,getppid());
		
		struct sigaction action;
		sigemptyset(&action.sa_mask);
		action.sa_handler = recycle;
		action.sa_flags = SA_NODEFER;    //使用旧式的函数指针sa_handler来作为信号处理函数

		/*注册信号捕捉，委托内核处理将来产生的信号当信号产生之后。当前进程优先处理信号，之前的处理动作会暂停，
         *信号处理完毕之后, 回到原来的暂停的位置继续运行。
		 */
		sigaction(SIGCHLD,&action,NULL);
		sleep(1);   //等待子进程都运行完退出，以查看未接信号集中的数据
		
		sigset_t pendset;
		sigpending(&pendset);     //获取未决信号集
		if(sigismember(&pendset,SIGCHLD))   //判断SIGCHLD信号是否在未决信号集中
		{
			printf("resource_collect: %d SIGCHLD in pendset\n",SIGCHLD);
		}
		else
		{
			fprintf(stdout,"resource_collect: %d SIGCHLD out of pendset\n",SIGCHLD);
		}
		
		//解除SIGCHLD信号的阻塞。信号被阻塞之后，就捕捉不到了，解除阻塞之后才能捕捉到这个信号。
		sigprocmask(SIG_UNBLOCK,&blockset,NULL);
		
		//默认父进程执行for循环中的语句。但是信号产生了，默认执行逻辑就会被强迫暂停，转而让父进程去运行信号的处理函数
		for(int i=0;i<5;++i)
		{
			puts("resource_collect: parent process is running");
			sleep(1);    //休眠1s，减小CPU使用率
		}
		
		const char* info = "resource_collect: parent process run finished\n";
		fwrite(info,strlen(info),1,stdout);
	}
}