#include <iostream>
#include <string>
#include <functional>

using namespace std;

template <typename T>
using UnaryFuncType = void (*)(T);

//C++中闭包将函数和参数封装到类中，在一定的场景下进行使用。可以将闭包看成是对回调函数的封装。
struct Closure
{
	virtual ~Closure(){}
	virtual void run() = 0;
};

template <typename T>
class UnaryClosure:public Closure
{
public:
	UnaryClosure(UnaryFuncType<T> pfun,T arg):m_pfun(pfun),m_arg(arg){}
	
	virtual void run()
	{
		m_pfun(m_arg);
	}
private:
	UnaryFuncType<T> m_pfun;
	T m_arg;
};

/*createClosure()是一个辅助函数，用来生成子闭包类，它需要传入函数指针和参数。
 *类似于C++11中的std::bind()函数
 */
template <typename T>
Closure* createClosure(UnaryFuncType<T> unaryFuncPtr,T arg)
{
	return new UnaryClosure<T>(unaryFuncPtr,arg);
}

void print(string str)
{
	cout<<"print(): "<<str<<endl;
}

void display(double num)
{
	cout<<"display(): "<<num<<endl;
}

int main(void)
{
	string title("hello world");
	Closure* closure1 = createClosure(print,title);
	closure1->run();
	
	double num = 3.14;
	Closure* closure2 = createClosure(display,num);
	closure2->run();
	
	delete closure1;
	delete closure2;
	
	//callableObj只是普通的可调用对象，不属于闭包。因为闭包包含状态，而callableObj没有。
	function<void(string)> callableObj = print;
	callableObj(title);
	
	num = 2.718;
	auto closure3 = [=]{display(num);};
	closure3();
	
	title = "hello C++";
	function<void(void)> closure4 = std::bind(print,title);
	closure4();
	
	return 0;
}