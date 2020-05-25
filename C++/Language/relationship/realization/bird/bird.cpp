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
		delete p;
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
		free(ptr);
		ptr = nullptr;
	}	
}	
#endif