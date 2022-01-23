/*1.编译期常量:
 *编译期常量是C++中相当重要的一部分，整体而言他们有助提高程序的正确性，并提高程序的性能。
 *总有些东西是编译器要求编译期间就要确定的，除了变量的类型外，最频繁出现的地方就是数组、
 *switch的case标签、模板的值类型参数、enum枚举和static_assert静态断言。
 */

/*2.数组中的编译期常量：
 *如果我们想要创建一个不是动态分配内存的数组，那么我们就必须给他设定一个size大小，
 *这个size必须在编译期间就知道，因此静态数组的大小是编译期常量。因为只有这么做，
 *编译器才能准确地解算出到底要分配给这个数组多少内存。如果这个数组在函数中，
 *数组的内存就会被预留在该函数的栈帧中；如果这个数组是类的一个成员，那么编译器要确定
 *数组的大小以确定这个类成员的大小。无论哪种情况，编译器都要知道这个数组具体的size。
 */

/*3.模板中的编译期常量：
 *除了类型以外，数字也可以作为模板的参数。这些数值变量包括int、long、short、bool、char和弱枚举enum等。
 *既然编译器在初始化模板的时候必须知道模板的类型，那么这些模板的参数也必须是编译期常量。
 */

/*4.编译期常量用于编译优化：
 *（1）编译器能根据编译期常量来实现各种不同的优化。如果在一个if判断语句中，其中一个条件是编译期常量，
 *     编译器知道在这个判断句中一定会走某一条路，那么编译器就会把这个if语句优化掉，留下只会走的那一条路。
 *（2）另一个可以优化的地方在空间优化。编译期常数不需要占用运行时内存来存储数据。
 */

#include <iostream>
#include <array>

#define _ERROR_
#undef _ERROR_

#define _CHANGE_WAY_ 0

#define SIZE 10

using namespace std;

enum Color_t
{
	RED,
	GREEN,
	BLUE
};

void process(Color_t color)
{
	Color_t tag = BLUE;
	switch(color){
	case RED:        //switch语句的case labels必须是编译器常量
		cout<<"process: red"<<endl;
		break;
	case GREEN:
		cout<<"process: green"<<endl;
		break;
#ifdef _ERROR_
	case tag:        //tag是一个变量，不能用作switch语句的case分支判断。
		cout<<"process: blue"<<endl;
		break;
#endif
	default:
		cout<<"process: default"<<endl;
	}
}

constexpr int summation(int n)
{
	return n == 1 ? 1 : summation(n - 1);
}

//编译器在初始化模板的时候，必须知道模板的类型，所以值类型的模板参数也必须是常量。
template <int N>
int func()
{
	cout<<"func: "<<N<<endl;
	return N;
}

//模板输出要求编译期常量的元函数，用于测试一个表达式是否为常量表达式。
template <int N>
struct constN
{
	constN(){cout<<"constN: "<<N<<endl;}
};

struct Test
{
	enum{LEN = 5};   //枚举值必须是编译器常量
#ifdef _ERROR_
	static const int length;     //只是声明了一个静态只读的变量，其定义在类外面。
#else
	static const int length = 15;   //const只读变量在声明时初始化了，那么它就成为了一个常量。
#endif
	
	int arr[LEN];
	int seq[length];    //编译器常量在使用前，必须有对应的定义语句，不能只有变量声明。
};

#ifdef _ERROR_
const int Test::length = 10;
#endif

class Demo
{
public:
	constexpr Demo(int data):m_data(data){}
	
	void setData(int data){m_data = data;}
	constexpr int getData()const{return m_data;}
	
	void print()const{cout<<"m_data ="<<m_data<<endl;}
private:
	int m_data;
};

int main(void)
{
	//编译器会直接利用其中某一个cout语句来替换掉整个if代码块。因为运行代码的机器是32还是64位的又不会变。
	if(sizeof(void*) == 4){
		std::cout << "This is a 32-bit system!" << std::endl;
	} else {
		std::cout << "This is a 64-bit system!" << std::endl;
	}

#if _CHANGE_WAY_
	int arr[sizeof(void*)] = {0};    //sizeof运算符返回值是编译期常量。
	cout<<"sizeof[arr] ="<<sizeof(arr)<<endl;
#else
	array<int,sizeof(double)> arr;   //定义std::array数组时，必须使用编译期常量指定数组大小。
	cout<<"arr.size() ="<<arr.size()<<endl;
#endif
	
#if _CHANGE_WAY_
	int seq[SIZE] = {0};      //g++编译器中可以使用变量定义原始数组大小。
#else
	const int size = 10;
	constexpr int length = 20;
	int seq[length] = {0};
#endif
	cout<<"seq len ="<<sizeof(seq)/sizeof(seq[0])<<endl;

	process(GREEN);

#ifdef _ERROR_
	int num = 8;
	constexpr int ret = summation(num);
#else
	constexpr int ret = summation(8);
#endif
	cout<<"ret ="<<ret<<endl;
	
	func<5>();
	func<summation(5)>();
	
	constN<10> out1;
	constN<summation(10)> out2;
	
	Test test;
	cout<<"sizeof(test.arr) ="<<sizeof(test.arr)<<endl;
	cout<<"sizeof(test.seq) ="<<sizeof(test.seq)<<endl;

#ifdef _ERROR_
	int value = 25;
	constexpr Demo demo(value);    //定义constexpr常量时，调用constexpr构造函数时，传入的函数参数也必须为常量表达式。
#else
	constexpr Demo demo(25);
#endif

	enum{
		a = sizeof(int),
		b = summation(5),
		c = demo.getData()
	};

	Demo demo1(30);   //定义Demo类型变量时，constexpr构造函数失去常量表达式的语义，变为一个普通的构造函数。
	demo1.print();
	demo1.setData(35);
	demo1.print();

	return 0;
}