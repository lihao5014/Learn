#include <iostream>

#define _CHANGE_WAY_
// #undef _CHANGE_WAY_

using namespace std;

class Empty{};      //����Ĵ�С��1���ֽ�

/*����ֻҪ���麯������ô32λϵͳ�оͻ�����4���ֽڴ�С�����ָ�룬64λϵͳ�л�����8���ֽڵ����ָ�롣
 *32λϵͳ��ָ���Сλ4���ֽڣ�64λϵͳ��ָ���Сλ8���ֽڡ�
 */
class Base
{
public:
#ifndef _CHANGE_WAY_
	~Base()
	{
		cout<<"Base destructor"<<endl;
	}
#else
	virtual ~Base()
	{
		cout<<"virtual Base destructor"<<endl;
	}
#endif
	
	virtual void fun(int a)
	{
		cout<<"class Base: fun "<<a<<endl;
	}
	
	virtual void foo(int x)
	{
		cout<<"class Base: foo "<<x<<endl;
	}
};

class SubClass:public Base
{
public:
	~SubClass()
	{
		cout<<"SubClass destructor"<<endl;
	}
	
	
	void fun(int a)
	{
		cout<<"class SubClass: fun "<<a<<endl;
	}
	
	void foo(double x)
	{
		cout<<"class SubClass: foo "<<x<<endl;
	}
	
	void bar()
	{
		foo(2.71828);      //�������า�ǵ�foo()�麯��������������ȵ����Լ�ʵ�ֵĺ���
		Base::foo(5);      //�������ͨ��::����������ʵ������б������˵�foo()�麯��
		cout<<"class SubClass: bar"<<endl;
	}
};

int main()
{
	cout<<"sizeof(Empty) ="<<sizeof(Empty)<<endl;
	cout<<"sizeof(Base) ="<<sizeof(Base)<<endl;
	
	{
		//Base����ָ��q��ָ������SubClass
		Base *q = new SubClass;    //���Base������û����������������ôdelete����ָ��ʱ��ֻ���ø��������������
		delete q;                  //���Base����������������������ôdelete����ָ��ʱ���ͻᶯ̬���õ�����͸��������������
	}
	
	Base a,*p = &a;
	SubClass b;
	
	(*p).fun(1);
	p->foo(1);
	
	p = &b;
	(*p).fun(2);
	p->foo(2);
	p->foo(3.1415);
	
	b.Base::foo(1.414);   //����������ͨ��::����������ʸ���������public�����������������˵��麯��
	b.foo(3.1415);
	b.bar();
}