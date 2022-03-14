#include <iostream>
#include <functional>   //binary_function与unary_function

#define _CHANGE_WAY_
#undef _CHANGE_WAY_

using namespace std;

template <class Operation1,class Operation2>
class unary_compose:public unary_function<typename Operation2::argument_type,typename Operation1::result_type>
{
public:
	unary_compose(const Operation1& op1,const Operation2& op2)
		:m_op1(op1),m_op2(op2)
	{
		
	}
	
	typename Operation1::result_type operator ()(const typename Operation2::argument_type& x)const
	{
		return m_op1(m_op2(x));
	}

protected:
	Operation1 m_op1;
	Operation2 m_op2;
};

template <class Operation1,class Operation2>
inline unary_compose<Operation1,Operation2> compose1(const Operation1& op1,const Operation2& op2)
{
	return unary_compose<Operation1,Operation2>(op1,op2);
}

class Foo:public unary_function<double,double>
{
public:
	result_type operator ()(const argument_type& x)const  //必须带const，原因是unary_compose的operator()带const
	{
		return x * 2 + 1;
	}
};

struct Bar:public unary_function<double,double>
{
	result_type operator ()(const argument_type& x)const  //必须带const，原因是unary_compose的operator()带const
	{
		return x * x;
	}
};

int main(void)
{
	Foo f;
	Bar g;
	
	int ret = compose1(f,g)(5);
	cout<<"Foo(Bar(x)) = (x * x)*2 + 1 : (5 * 5) * 2 + 1 ="<<ret<<endl;

#ifndef _CHANGE_WAY_
	std::function<int(int)> h = compose1(g,f);
#else
	auto h = compose1(Foo(),Bar());
#endif
	cout<<"Bar(Foo(x)) = (x*2 + 1)^2 : (5 * 2 + 1)^2 ="<<h(5)<<endl;
	
	return 0;
}
