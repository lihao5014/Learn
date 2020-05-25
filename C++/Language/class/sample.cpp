#include <iostream>

using namespace std;

class Sample
{
public:
	Sample(){n = 0;}
	Sample(int n){this->n = n;}
	Sample(/*const*/ Sample &s);
	~Sample();
	void setN(int n);
	int getN()/*const*/;
	void setM(int m);
	int getM()const;
	
	static void display(const Sample &s);
	static int m;
private:
	int n;
};

int Sample::m = 0;		 //static成员是类公有的，可以通过类名和对象名调用。

Sample::Sample(/*const*/ Sample &s)        //const对象只能调用const修饰的函数
{
#if 0
	n = s.getN();
#else
    n = s.n;
#endif
}

Sample::~Sample()
{
	cout << "Sample destroy"<<endl;
}

void Sample::setN(int n)
{
	this->n = n;
}

int Sample::getN()/*const*/
{
	return n;
}

void Sample::setM(int m)
{
	Sample::m = m;
}

int Sample::getM()const
{
	return m;
}


void Sample::display(const Sample &s)
{
	cout << "n ="<<s.n<<" ,m="<<m<<endl;     //static成员函数只能直接访问static成员
}

int main(int argc,char** argv)
{
	
	Sample s(5);	
	s.display(s);
	
	Sample *p = &s;
	p->setN(6);
	(*p).setM(7);
	cout << "n ="<<(*p).getN()<<" ,m="<<Sample::m/*p->m*/<<endl;
	
	Sample t(s);
	t.display(t);	
	
	return 0;
}