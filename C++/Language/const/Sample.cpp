#include <iostream>

using namespace std;

class Sample
{
public:
	Sample(int n,int m=0):m(m){this->n = n;}
	void setValue(/*const */int n);            //对于函数中传入的是普通变量参数，不用使用const关键字修饰，
	int getValue()const;                       //因为普通变量传参是一种拷贝赋值的过程,在函数中修改形参不会修改实参值
	void display();
	void display() const;
private:
	int n;
	const int m;      //const成语只能通过初始化列表初始化
};

void Sample::setValue(/*const */int n)
{
	this->n = n;
}

int Sample::getValue()const
{
	return n;
}

void Sample::display()
{
	cout<<"display: n="<<n<<" m="<<m<<endl;
}

void Sample::display() const
{
	cout<<"const display: n="<<n<<" m="<<m<<endl;
}

int main()
{
	const Sample s(10,12);        //const成员只能调用const方法
	
//	s.setValue(11);
	cout<<"n="<<s.getValue()<<endl;
	s.display();
	
	Sample s1(s);
	cout<<"n="<<s1.getValue()<<endl;
	s1.display();
	s1.setValue(120);
	s1.display();
	
	return 0;
}