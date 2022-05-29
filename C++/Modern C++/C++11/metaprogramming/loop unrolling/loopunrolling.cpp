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

#include <limits.h>
#include <iostream>
#include <chrono>

#define _CHANGE_WAY_ 1<<2   //1<<0 = 0b001, 1<<1 = 0b010, 1<<2 = 0b100

#define INFINITY INT_MIN

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

/*定义一个模板函数sumArray()来做循环展开。然后比较传统循环累加和循环展开后累加的时间。
 *不展开循环用时比循环展开用时更少。可见做这个展开意义不是特别大。而且当长度变大之后，
 *编译器处理不了，展开会直接报编译错误。
 */
int totalArray(int* parr,int size)
{
	if(parr == nullptr || size < 0)
	{
		cout<<"totalArray() error: parr is null or size<0"<<endl;
		return INFINITY;
	}
	
	int ret = 0;
	while(size-->0)
	{
		ret += parr[size];
	}
	
	return ret;
}

template <int N>
int sumArray(int arr[])
{
	if(arr == nullptr)
	{
		cout<<"sumArray() error: arr is null"<<endl;
		return INFINITY;
	}
	
	return arr[0] + sumArray<N - 1>(arr + 1);
}

template <>
int sumArray<1>(int arr[])
{
	return arr[0];
}

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

/*对于性能要求极高并大量使用点乘的应用程序，也许想再节省一点开销。如果能减少循环的计数，对性能也有
 *比较可观的提升。这样代码应该展开以直接计算：result=a[0]*b[0]+a[1]*b[1]+a[2]*b[2]+a[3]*b[3]表达式。
 *但是我们希望泛化这个表达式，以便应用于不同维数的向量计算，这里模板元编程正好可以发挥出它编译时计算
 *和生成代码的能力。
 */
int dotProduct(int dim,int vec1[],int vec2[])
{
	if(dim < 0)
	{
		cout<<"dotProduct() warn: dimension is less than zero"<<endl;
		return INFINITY;
	}
	
	int result = 0;
	for(int i=0;i<dim;++i)     //如果直接将循环展开为a[0]*b[0]+a[1]*b[1]+a[2]*b[2]表达式进行计算性能更好。
	{
		result += vec1[i] * vec2[i];
	}
	
	return result;
}

/*使用模板元编程进行向量点乘的方法是定义一个类模板DotProduct作为元函数，通过递归调用
 *不断展开表达式。还定义了一个局部特化的版本，使它在维数递减到1时能够终结递归。
 */
template <int DIM>
struct DotProduct
{
	static int result(int* pvec1,int* pvec2)
	{
		return pvec1[0] * pvec2[0] + DotProduct<DIM - 1>::result(pvec1 + 1,pvec2 + 1);
	}
};

template <>
struct DotProduct<1>    //作为递归结束条件的局部特化
{
	static int result(int* pvec1,int* pvec2)
	{
		return pvec1[0] * pvec2[0];
	}
};

/*dot_product()包装函数的接口相较于dotProduct()已经改变，这是原因模板参数必须在编译时确定，
 *所以DIM必须是一个常量，而可以是一个变量。这是模板元编程技术在数值计算方面的一个重大限制。
 *当然对于点乘计算而言，向量的维数一般都能在编译时确定。
 */
template <int DIM>
int dot_product(int* pvec1,int* pvec2)
{
	if(pvec1 == nullptr || pvec2 == nullptr)
	{
		cout<<"dot_product() warn: pvec1 or pvec2 is null"<<endl;
		return INFINITY;
	}
	
	return DotProduct<DIM>::result(pvec1,pvec2);
}

int main(void)
{
	int ret = sum(50000);
	cout<<"sum 1~50000 = "<<ret<<endl;
	
	Loop<10>::run(print);
	cout<<endl;
	
	Loop<6>::run(show);
	cout<<endl;
	
	int seq[] = {8,5,0,9,3,1,2,6,4,7};
	{
		Timer timer;
		ret = totalArray(seq,sizeof(seq)/sizeof(int));
	}
	cout<<"totalArray(): "<<ret<<endl;
	
	{
		Timer timer;
		ret = sumArray<sizeof(seq)/sizeof(seq[0])>(seq);
	}
	cout<<"sumArray(): "<<ret<<endl;
	
	int arr[] = {1,2,3};
	int vec[] = {3,4,5};
	{
		Timer timer;
		ret = dotProduct(sizeof(arr)/sizeof(int),arr,vec);
	}
	cout<<"dotProduct(): "<<ret<<endl;
	
	{
		Timer timer;
		ret = dot_product<sizeof(arr)/sizeof(arr[0])>(arr,vec);
	}
	cout<<"dot_Product(): "<<ret<<endl;
	
	return 0;
}