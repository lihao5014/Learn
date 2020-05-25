/*C++类之间的实现关系与泛化关系类似，都是通过继承实现的。
 *继承自抽象类为实现关系，继承自普通类为泛化关系。
 */

#include <iostream>

using namespace std;

class Base
{
public:
	virtual ~Base(){};
	virtual void show() = 0;
};

class SubClass:public Base
{
public:
	void show()override
	{
		cout<<"SubClass show()"<<endl;
	}
};

class Interface
{
public:
	virtual ~Interface() = default;
	virtual void doWork() = 0;
};

class Implement:public Interface
{
public:
	void doWork()
	{
		cout<<"Implement doWork"<<endl;
	}
};

int main()
{
	Base *p = new SubClass;
	p->show();
	if(p != nullptr)
	{
		delete p;
		p = nullptr;
	}
	
	Interface* q = new Implement();
	q->doWork();
	if(q != nullptr)
	{
		delete q;
		q = nullptr;
	}
	
	return 0;
}