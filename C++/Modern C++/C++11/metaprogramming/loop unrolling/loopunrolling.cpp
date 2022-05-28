/*1.循环展开：
 *是一种牺牲程序的尺寸来加快程序的执行速度的优化方法。可以由程序员完成，也可由编译器自动优化完成。
 *循环展开最常用来降低循环开销，为具有多个功能单元的处理器提供指令级并行。也有利于指令流水线的调度。
 */

/*2.循环展开改进程序性能的2方面：
 *（1）减少了不直接有助于程序结果的操作的数量，例如循环索引计算和分支条件。
 *（2）提供了一些方法，可以进一步变化代码，减少整个计算中关键路径上的操作数量。
 */

/*3.循环展开的优缺点：
 *循环展开对程序性能有着很重要的影响，可以减少分支预测错误次数，增加取消数据相关进一步利用并行执行
 *提高速度的机会。但是并不建议大家进行手动的循环展开，在代码中进行循环展开会导致程序的可读性下降，
 *代码膨胀。为了直观感受循环展开对性能的影响，测试代码运行结果均是在不开编译器优化的情况下进行的测试，
 *其实在我们开启了编译器优化的时候，编译器会自动对我们的循环代码进行循环展开，让我们可以在保持了代码
 *可读性的同时，又能享受到循环展开对我们程序性能的提高。
 */

#include <iostream>
#include <chrono>

#define _CHANGE_WAY_ 1<<2   //1<<0 = 0b001, 1<<1 = 0b010, 1<<2 = 0b100

using namespace std;

typedef void (*pFun)(int);

class Timer
{
public:
	Timer():m_startTimePoint(chrono::steady_clock::now()){}
	
	~Timer()
	{
		auto endTimePoint = chrono::steady_clock::now();
		auto duration = chrono::duration<double,std::micro>(endTimePoint - m_startTimePoint);
		
		cout<<"spend time: "<<duration.count()<<"ms"<<endl;
	}
private:
	chrono::steady_clock::time_point m_startTimePoint;
};

#if (_CHANGE_WAY_ & 0b001)
//未经过循环展开优化的代码
int sum(int num)
{
	Timer timer;
	
	int ret = 0;
	for(int i=1;i<=num;++i)
	{
		ret += i;
	}
	
	return ret;
}
#elif (_CHANGE_WAY_ & 0b010)
/*（1）循环展开一次，即每次循环将i和i+1一起累加到ret变量上，这样可以把循环次数从num次降低
 *     到num/2次，由于CPU的高度流水线化，连续两个加法指令增加耗时很低，所以此版本代码可以
 *     一定程度上提高程序运行速度。
 *（2）当然我们可以继续增加循环展开次数以进一步提高程序运行速度，但是这个增加循环展开次数
 *     也是有限度的，当达到了CPU的最高吞吐量之后，继续增加循环展开次数是没有意义的。
 */
int sum(int num)
{
	Timer timer;
	
	int ret = 0;
	for(int i=1;i <= num;i += 2)    //循环展开
	{
		ret += i;
		ret += i + 1;
	}
	
	return ret;
}
#elif (_CHANGE_WAY_ & 0b100)
/*（1）上述循环展开一次后的代码依然有进一步优化的空间，那就是消除连续指令的相关性，以达到指令级并行，
 *     我们可以看到循环展开后的代码，循环体中有两条语句：ret += i和ret += i+1，第二条语句sum += i+1
 *     依赖于第一条命来ret += i的执行结果，所以这两条语句只能依次执行，限制了CPU进一步提高性能的可能。
 *（2）我们新建了两个变量ret1和ret2用于存储循环展开时，两个累加语句的累加结果，最后在循环体外将两部分
 *     结果相加得到最终结果。该代码中两个累加语句之间是互不相关的，所以CPU可以并行执行这两条指令，
 *     以达到性能的进一步提高。
 */
int sum(int num)
{
	Timer timer;
	
	int ret1 = 0;
	int ret2 = 0;
	for(int i=1;i <= num;i += 2)   //既循环展开又多路并行
	{
		ret1 += i;
		ret2 += i + 1;
	}
	
	return ret1 + ret2;
}
#endif

void print(int n)
{
	cout<<n<<" ";
}

void show(int n)
{
	cout<<n * n<<" ";
}

/*使用模板元编程进行循环展开，因为在编译后的代码中是没有递归和循环的。
 *有的只是很多特化类Loop<10>、Loop<9>...Loop<0>都执行了run()方法。
 */
template <int N>
struct Loop
{
	static int run(pFun pfun)
	{
		int num = Loop<N - 1>::run(pfun);
		
		pfun(num + 1);
		return num + 1;
	}
};

template <>
struct Loop<0>
{
	static int run(pFun pfun)
	{
		pfun(0);
		return 0;
	}
};

int main(void)
{
	int ret = sum(50000);
	cout<<"sum 1~50000 = "<<ret<<endl;
	
	Loop<10>::run(print);
	cout<<endl;
	
	Loop<6>::run(show);
	cout<<endl;
	
	return 0;
}