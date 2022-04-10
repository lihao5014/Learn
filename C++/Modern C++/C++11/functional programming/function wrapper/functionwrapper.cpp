#include <iostream>
#include <string>
#include <functional>

using namespace std;

template <typename T>
using UnaryFuncType = void (*)(T);

//C++�бհ��������Ͳ�����װ�����У���һ���ĳ����½���ʹ�á����Խ��հ������ǶԻص������ķ�װ��
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

/*createClosure()��һ���������������������ӱհ��࣬����Ҫ���뺯��ָ��Ͳ�����
 *������C++11�е�std::bind()����
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
	
	//callableObjֻ����ͨ�Ŀɵ��ö��󣬲����ڱհ�����Ϊ�հ�����״̬����callableObjû�С�
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