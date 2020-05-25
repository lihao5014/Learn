#include <iostream>

using namespace std;

class Sample
{
public:
	Sample(int n){this->n;}
	void setN(const int n);
	int getN()const;
	
	static void setM(const int m);    //static函数只能访问static成员变量
	static int getM();
	
	void display();
	void display() const;
	
	static int m;
private:
	int n;
};

int Sample::m = 0;

void Sample::setN(const int n)
{
	this->n = n;
}

int Sample::getN()const
{
	return n;
}

void Sample::setM(const int m)
{
	Sample::m = m;
}

int Sample::getM()
{
	return Sample::m;
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
	const Sample s(10);        //const成员只能调用const方法
	
//	s.setN(11);
	cout<<"n="<<s.getN()<<endl;
	s.display();
	
	Sample s1(s);
	cout<<"n="<<s1.getN()<<endl;
	s1.display();
	s1.setN(20);
	s1.display();
	
	s1.setM(14);
	s1.display();
	
	return 0;
}