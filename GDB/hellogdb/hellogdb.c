/*1.程序调试：（程序的调试过程主要有单步执行、跳入函数、跳出函数、设置断点、设置观察点和查看变量）
 *调试Debug就是让代码一步一步慢慢执行，跟踪程序的运行过程。可以让程序停在某个地方，查看当前所有变量的值，
 *或者内存中的数据。也可以让程序一次只执行一条或者几条语句，查看程序到底执行了哪些代码。在调试的过程中，
 *可以监控程序的每一个细节，包括变量的值、函数的调用过程、内存中数据、寄存器、线程的调度等，从而发现隐藏
 *的错误或者低效的代码。
 */

/*2.gdb调试器的主要功能：
 *（1）能够运行程序，设置所有能影响程序运行的参数。
 *（2）能够让程序在指定的条件下停止运行。
 *（3）能够在程序停止时检查所有参数的情况。
 *（4）能够根据指定条件改变程序的运行。
 */

/*3.gdb基本使用流程:
 *（1）编译debug版本应用程序：
 *  ①因为gdb调试的是可执行文件，而不是".c"源文件。所以C语言源文件需要通过gcc编译生成可执行文件后才能进行gdb调试。
 *  ②gcc编译应用程序时一定要加"-g"选项，这样编译出的可执行文件中才包含调试信息，否则gdb将看不见程序的函数名/变量名，
 *    代替它们的全是运行时的内存地址，从而无法载入该执行文件。
 *  ③gcc -g hellodbg.c -o hellodbg.out      //编译带调试信息的hellodbg.out可执行文件，以供gdb调试使用
 *
 *（2）启动gdb调试：
 *  ①进入gdb只需要gdb和要调试的可执行文件即可。
 *  ②gdb ./hellodbg.out            //启动gdb调试hellodbg.out应用程序。
 *  ③gdb -q ./hellodbg.out         //选项"-q"表示不打印gdb版本信息，界面较为干净。
 *  ④gdb -silent ./hellodbg.out    //选项"-silent"用于屏蔽GDB的前导信息，否则它会在屏幕上打印一堆免责条款。
 *
 *（3）查看源码：
 *  ①list（l）：查看源程序代码，默认显示10行，按回车键继续看余下的。
 *  ②gdb列出的源代码中明确给出了对应的行号，这样可以大大地方便代码的定位。一般情况下，源代码中的行号与用户
 *    书写程序中的行号是一致的，但有时用户的某些编译选项会导致行号不一致的情况，因此一定要查看gdb中的行号。
 *  ③list 25                //查看当前文件中第25行周围的代码。
 *  ④list hellodbg.c:25     //查看hellodbg.c源文件中的第25行周围的代码。
 *  ⑤list sum               //查看sum()函数定义附近的代码。
 *  ⑥list hellodbg.c:sum    //查看hellodbg.c源文件中sum()函数定义附近的代码。
 *  ⑦set listsize 20        //设置list命令打印源代码时的行数
 *  ⑧show listsize          //查看list命令显示源代码时的行数
 *
 *（4）设置断点：
 *  ①break（b）：可以根据行号、函数名、地址来设置断点位置。
 *  ②设置断点可以使程序执行到某个位置时停止，以便于查看该位置处变量的值、堆栈情况和函数的调用过程等。
 *    从而找出问题的症结所在。在gdb中利用行号设置断点是指代码运行到对于行之前暂停。
 *  ③break 25                //代码运行到第25行之前停止，但还没运行第25行
 *  ④break hellodbg.c:25     //在源文件hellodbg.c的第25行处停住
 *  ⑤break +5 或 break -5    //在当前行号的前面或后面的5行处停住，offset为自然数。
 *  ⑥break sum               //在进入sum()函数时停住。C++中可以使用class::function或function(type,type)格式来指定函数名。
 *  ⑦break hellodbg.c:sum    //在源文件hellodbg.c的sum()函数入口处停住。
 *  ⑧break                   //break命令没有参数时，表示在下一条命令处停住。
 *  ⑨break 25 if i == 6       //在循环体中，可以设置"break if i == 6"表示当i为6时停住程序。
 *
 *（5）查看断点：
 *  ①info：设置完断点以后，用户可以键入"info b"来查看断点设置情况。
 *  ②info break           //列出所有断点
 *  ③info breakpoints     //列出所有断点
 *  ④info break 3         //查看断点号为3的断点信息
 *
 *（6）运行程序：
 *  ①run（r）：运行程序直到程序结束或遇到断点等待下一个命令。
 *  ②finish：运行程序直到当前函数完成返回，并打印函数返回时的堆栈地址、返回值、参数值等信息。
 *  ③run            //gdb默认从首行开始运行代码。
 *  ④run 25         //程序从第25行开始运行。
 *  ⑤run welcome    //调试启动带参程序。
 *  ⑥finish         //继续执行到函数结束，即一直运行到函数返回。
 *
 *（7）查看变量值：
 *  ①print（p）：在程序停止运行之后，就可以查看断点处的相关变量值，在gdb中只需要输入"p 变量名"即可。
 *  ②gdb在显示变量值时都会在对应值之前加上"$N"标记，它是当前变量值的引用标记，以后若想再次引用此变量
 *    就可以直接写作"$N"，而无需写冗长的变量名。
 *  ③print i               //打印变量i的值。
 *  ④print &i              //查看变量i的地址。
 *  ⑤print hellodbg.c:i    //打印源文件hellodbg.c中的变量i值。
 *  ⑥print/t i             //把变量i作为二进制数打印。
 *  ⑦print/o i             //把变量i作为八进制数打印。
 *  ⑧print/x i             //把变量i作为十六进制数打印。
 *  ⑨print/f i             //以浮点数格式打印变量i
 *  ⑩print *arr@5          //打印数组中的前5项
 *
 *（8）单步执行：
 *  ①step（s）：单步跟踪，如果有函数调用，它会进入该函数。进入函数的前提是此函数被编译有debug信息。
 *  ②next（n）：单步跟踪，但如果有函数调用，不会进入该函数。
 *  ③next与step的区别：step遇到用户自定义的函数，将步进到函数中去运行，而next则直接调用函数，不会进入到函数体内。
 *  ④step          //表示一条条地执行指令，类似于VS工具中的step in。
 *  ⑤step 3        //表示执行后面的3条指令，然后再停止。
 *  ⑥next          //表示一条条地执行指令，类似于VS工具中的step over。
 *  ⑦next 3        //表示执行后面的3条指令，然后再停止。
 *
 *（9）恢复程序运行：
 *  ①continue（c）: 当程序暂停时，可以使用continue命令使程序继续往下运行，直到再次遇到断点或程序结束。 
 *  ②continue      //继续执行直到下一个断点或观察点
 *  ③continue 3    //继续执行，但会忽略当前的断点3次。当断点在循环中时非常有用。
 *
 *（10）删除断点：
 *  ①clear：用于清除指定行号或函数名处的断点。
 *  ②delete（d）：根据断点编号删除断点。
 *  ③clear与delete的区别：clear清除断点时需要给出断点的行号或函数名，而delete删除断点时需要给出断点编号。
 *    用clear命令清除断点时gdb会给出提示，但使用delete删除断点时gdb不会给出任何提示。
 *  ④clear 25           //清除第25行处的断点
 *  ⑤clear sum          //清除sum()函数处的断点
 *  ⑥delete             //删除所有的断点或观察点
 *  ⑦delete 3           //删除断点编号为3的断点
 *  ⑧delete 1-5         //删除断点编号为1到5范围内的断点
 *
 *（11）禁用断点/启动断点：
 *  ①disable：不删除断点，仅仅把它设置为无效。如果要让多个断点编号处的断点失效可将编号之间用空格隔开。
 *  ②enable：将禁用的断点重新设置为有效。
 *  ③disable 3       //将断点编号为3的断点设置为无效。
 *  ④disable 1-5     //将编号为1到5的断点禁用。
 *  ⑤enable 3        //重新启用3号断点。
 *  ⑥enable 1-5      //将断点编号为1到5的断点设置为有效。
 *
 *（12）设置观察点：
 *  ①watch：为变量/表达式设置一个观察点，一旦表达式值有变化时，马上停住程序。
 *  ②rwatch：当变量/表达式被读取时，停住程序
 *  ③awatch：当变量/表达式的值被读写时，停住程序
 *  ④在循环中，如果希望能够观察某个变量的变化情况
 *  ⑤info watchpoints       //列出当前设置的所有观察点
 *  ⑥info watch             //查看观点信息
 *  ⑦info locals             //查看局部变量
 *  ⑧info variables          //查看全局变量和静态变量
 *  ⑨info args               //查看当前stack frame参数
 *
 *（12）停止程序运行：
 *  ①kill：终止当前正在运行的程序。
 *
 *（13）退出gdb调试：
 *  ①quit（q）：退出gdb调试器。
 *
 *（14）查看堆栈信息：
 *  ①backtrace（bt）：用来打印栈帧指针
 *  ②backtrace 5（bt 5）：表示只打印栈顶上的5层栈信息。
 *  ③backtrace -3（bt -3）：表示只打印栈底下的3层栈信息。
 *  ④frame（f）：用于切换当前栈，打印栈帧。一般来说，程序停止时，最顶层的栈就是当前栈，如果你要查看栈
				  下面层的详细信息，首先要做的就是切换当前栈。
 *  ⑤frame 2（f 2）：切换层编号为2的栈。frame 0表示栈顶；frame 1表示栈的第二层。
 *  ⑥up/down：向栈的上面/下面移动一层，即跳到上一层/下一层函数。
 *  ⑦up 3           //从当前栈向上移动3层
 *  ⑧down 2         //从当前栈向下移动2层
 *  ⑨info frame（info f）：打印更为详细的当前栈层的信息，只不过大多数都是运行时的内存地址。
 *  ⑩info stack    //查看当前堆栈情况
 *
 *（14）修改变量的值：
 *  ①set var i = 10      //修改程序中变量i的值为10
 */
#include <stdio.h>
#include <limits.h>

#define INFINITY INT_MAX

static int sum(int num)
{
	if(num <= 0)
	{
		puts("sum error: num is less than zero");
		return INFINITY;
	}
	
	int count = 0;
	for(int i=1;i<=num;++i)
	{
		count += i;
	}
	return count;
}

int main(int argc,char** argv)
{
	if(argc != 2)
	{
		fputs("main error: input argument is illegal\n",stdout);
		return -1;
	}
	printf("main: start ,argv[1] =%s\n",argv[1]);
	
	int arr[10] = {0};
	for(int i=1;i<sizeof(arr)/sizeof(int);++i)
	{
		arr[i] = i;
		printf("arr[%d] =%d\n",i,arr[i]);
	}
	
	int ret = sum(10);
	printf("1 ~ 10 sum is %d\n",ret);
	
	puts("main: end");
	return 0;
}