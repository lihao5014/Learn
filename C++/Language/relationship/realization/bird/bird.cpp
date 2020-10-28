#include <iostream>
#include <stdlib.h>

#define _ERROR_
#undef _ERROR_

using namespace std;

class Fly
{
public:
	virtual ~Fly(){};
	virtual void fly() = 0;
};

class Move
{
public:
	virtual ~Move(){};
	virtual void move() = 0;
};

class Bird:public Fly
{
public:
	virtual void fly()
	{
		cout<<"bird can fly"<<endl;
	}
};

class Animal:public Move
{
public:
	void move()final
	{
		cout<<"animal can move"<<endl;
	}
};

#ifdef _ERROR_
static void myFree(void** pp);
#else
static void myFree(void* ptr);	
#endif

int main()
{
	Fly *p = new Bird;
	p->fly();
	if(p != nullptr)
	{
		delete p;                          //new和delete不仅可以开辟或释放内存，还会自动调用构造和析构函数
		p = nullptr;
	}
	
	Move* q = new Animal();
	q->move();
	
#ifdef _ERROR_
	myFree(&q);
#else
	myFree(q);
#endif
	
	return 0;
}

#ifdef _ERROR_
void myFree(void** pp)
{
	if(*pp != nullptr)
	{
		free(*pp);
		*pp = nullptr;
	}
}
#else 
void myFree(void* ptr)
{
	if(ptr != nullptr)
	{
		free(ptr);                   //malloc和free函数，只会开辟或释放内存，不会调用构造函数或析构函数
		ptr = nullptr;               //因为函数传参是指针类型，所以并不能将传入的实参设置为nullptr。
	}	
}	
#endif