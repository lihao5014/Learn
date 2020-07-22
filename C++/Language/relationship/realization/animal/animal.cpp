#include <iostream>
#include <stdlib.h>

using namespace std;

#define FREE(ptr)                   \
	do{                             \
		if((ptr) != nullptr)        \
		{                           \
			delete ptr;             \
			ptr = nullptr;          \
		}                           \
	}while(0)

class Move
{
public:
	virtual ~Move(){};
	virtual void fly() = 0;
	virtual void run() = 0;
};

class Bird:public Move
{
public:
	void fly()
	{
		cout<<"bird can fly"<<endl;
	}
private:
	virtual void run()
	{
		cout<<"bird can't run"<<endl;
	}
};

class Animal:public Move
{
public:
	void run()final
	{
		cout<<"animal can run"<<endl;
	}
private:
	void fly()override
	{
		cout<<"animal can't fly"<<endl;
	}
};

template <typename T>
static void myFree(T** pp);

static void Free(void* ptr);            // C/C++中只有void*指针，没有void**指针。且void*指针不能使用delete

int main()
{
	Move* p = new Bird;
	p->fly();
	p->run();                           //基类调用派生类中的虚函数时，其访问权限为基类中虚函数的访问权限
	if(p != nullptr)
	{
		delete p;
		p = nullptr;
	}
	
	Bird* pbrid = new Bird();
	pbrid->fly();
	// pbrid->run();          //私有成员不可以调用
	myFree(&pbrid);
	
	Move* q = new Animal();
	q->fly();                          //尽管Animal类中的fly()函数是private，但是通过Move类指针访问时，其权限为基类中的public
	q->run();
	FREE(p);
	
	Animal* panimal = new Animal;
	// panimal->fly();        //私有成员不可以调用
	panimal->run();
	Free(panimal);
	
	return 0;
}

template <typename T>
void myFree(T** pp)
{
	if(*pp != nullptr)
	{
		delete *pp;
		*pp = nullptr;
	}
}

void Free(void* ptr)
{
	if(ptr != nullptr)
	{
		free(ptr);
		// ptr = nullptr;            //因为传递的为void*指针，所以为ptr赋nullptr没有意义
	}
}