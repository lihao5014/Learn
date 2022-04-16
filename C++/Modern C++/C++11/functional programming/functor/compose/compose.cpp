/*�ں���ʽ�����к�����Ϊһ�ȹ��񣬿����ں����ڻ�������κεط����壬������Ϊ�����Ĳ����ͷ���ֵ��
 *���ԶԺ���������ϡ�����ʽ�������Ҳ����ͨ�����ƺ���ָ��ķ�ʽ��ʵ�ָ߽׺���������ʽ���ŵ���Ҫ
 *�ǲ��ɱ��Դ����ġ�û�пɱ��״̬��������������͸���ĺ�û�и����á�
 */

/*1.����ʽ��̵ĸ��
 *��1������ʽ��̣��Ѻ���������ͨ��ֵ����һ��ʹ�ã����������ú������и�ֵ�����Ρ��Ӻ����з��صȲ�����
 *��2����Ϊ����������һ��������Ϊ�����������ݸ���һ�������ķ�ʽ��
 *��3���߽׺��������һ��������������һ��������Ϊ�����򷵻صĽ����һ���������ú����Ϳ��Գ�Ϊ�߽׺�����
 *��4�����ﻯ�����߱���������ĺ���ת��Ϊʹ��һ�������ĺ�����������������ķ���ֵҲ��һ��������
 *     ������Ϊ�º�����һ�����������ߵķ���ֵ�ͳ�ʼ�����ķ���ֵ��ͬ��
 */

/*2.����ʽ�����һ�ֱ�̷�ʽ������������������
 *��1��������һ�ȹ��񣬿���������һ��������ȥ��
 *��2���߽׺�����
 *��3���ݹ顣
 *��4��pipeline��
 *��5��������ֵ��
 *��6�����ﻯ��
 *��7��ƫӦ�ú�����
 */

/*3.C++�к���ʽ��̵�ʵ�֣�
 *C++98/03�е�ģ��Ԫ��̺ͺ�������C++11�е�Lambda���ʽ��std::function��std::bind��C++�ĺ���ʽ���
 *������ס����ǿ�������C++11/14�����������ʵ�ָ߽׺�������ʽ���á�������ֵ�Ϳ����Ⱥ���ʽ������ԡ�
 */

/*4.�߽׺�����
 *��1���߽׺������ǲ���Ϊ�����򷵻�ֵΪ�����ĺ���������ĸ߽׺�������map��filter��fold��compose������
 *��2���еĸ߽׺����ǲ���Ϊ�������еĸ߽׺����ǲ����ͷ���ֵ���Ǻ������߽׺������������ϸ��ӳ��󷺻���
 *     ����ʵ�֡�������һ�ȹ��񡱣�������������һ��������ȥ����ϣ��ǳ�������compose������ʵ�ֶ�����ֵ��
 *     compose�ķ��ؽ����һ�����������ǿ��Ա����������ں�����Ҫ��ʱ����á�
 */

/*5.Scala�����г����ĸ߽׺�����
 *��1��mapӳ�䣺���б��е�ÿ��Ԫ��Ӧ��һ������������Ӧ�ú��Ԫ������ɵ��б�
 *     ���磺numbers.map((i: Int) => i * 2)�������������е�����Ԫ�ض���Ϊԭ����2����
 *��2��filter���ˣ��Ƴ��κζԴ��뺯��������Ϊfalse��Ԫ�ء�
 *     ���磺numbers.filter((i: Int) => i % 2 == 0)�����˵���������������ż��Ԫ�ء�
 *��3��fold�۵�����һ����ʼֵ��һ����Ԫ�����Ľ���ۼ�������
 *     ���磺numbers.fold(0){(z, i) => z + i}�������������е�����Ԫ����͡�
 *��4��compose��ϣ���f(x)��g(x)��������γ�һ���º���f(g(x))��
 */

/*6.compose1()��compose2():
 *��1��GCC��STL����һ��������C++��׼��compose1()���������Խ�������������()�������Ķ�����Ϊ����������
 *     ������һ���ܽ���f(g(x))����Ķ���
 *��2��compose1()��compose2()�������ڲ����ϳɡ����������������δ����STL��׼����SGI STL��˽�в�Ʒ��
 *��3��compose1()ʵ��ʵ���Ǻ�������unary_compose��compose1()��������������������������������
 *     ����op1�ķ���ֵ������Ϊ�ϲ����һԪ��������unary_compose�ķ���ֵ���ͣ�����op2�Ĳ�������
 *     ��Ϊ�ϲ����һԪ��������unary_compose�����غ���()�Ĳ������͡�
 *��4��compose2()ʵ��ʵ���Ǻ�������binary_compose��compose2()��������������������������������
 *    ����op1�ķ���ֵ������Ϊ�ϲ����һԪ��������binary_compose�ķ���ֵ���ͣ�����op2��
 *    ����������Ϊ�ϲ����һԪ��������binary_compose�����غ���()�Ĳ������͡�
 */

#include <iostream>
#include <list>
#include <iterator>     //distance()
#include <functional>   //binary_function��unary_function,bind1st(),bind2nd(),not1(),not2()
#include <algorithm>    //for_each(),transform()
#include <numeric>      //accumulate()

#define _CHANGE_WAY_
#undef _CHANGE_WAY_

using namespace std;

template <typename T>
void print(T x)
{
	cout<<x<<" ";
}

template <typename T>
class Show
{
public:
	void operator ()(T x)
	{
		cout<<x<<" ";
	}
};

class IsOdd:public unary_function<int,bool>
{
public:
	bool operator ()(int num)const    //һ��Ҫ��const��������ú���������not1(IsOdd())ʱ������ᱨ��
	{
		return num%2 == 0;
	}
};

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

template <class Operation1,class Operation2,class Operation3>
class binary_compose:public unary_function<typename Operation2::argument_type,typename Operation1::result_type>
{
public:
	binary_compose(const Operation1& op1,const Operation2& op2,const Operation3& op3)
		:m_op1(op1),m_op2(op2),m_op3(op3)
	{
		
	}
	
	typename Operation1::result_type operator ()(const typename Operation2::argument_type& x)const
	{
		return m_op1(m_op2(x),m_op3(x));
	}

protected:
	Operation1 m_op1;
	Operation2 m_op2;
	Operation3 m_op3;
};

template <class Operation1,class Operation2,class Operation3>
inline binary_compose<Operation1,Operation2,Operation3> compose2(const Operation1& op1,const Operation2& op2,const Operation3& op3)
{
	return binary_compose<Operation1,Operation2,Operation3>(op1,op2,op3);
}

class Foo:public unary_function<double,double>
{
public:
	result_type operator ()(const argument_type& x)const  //�����const��ԭ����unary_compose��operator()��const
	{
		return x * 2 + 1;
	}
};

struct Bar:public unary_function<double,double>
{
	result_type operator ()(const argument_type& x)const  //�����const��ԭ����unary_compose��operator()��const
	{
		return x * x;
	}
};

struct Qux:public binary_function<double,double,double>
{
	result_type operator ()(const first_argument_type& x,const second_argument_type& y)const
	{
		return x + y;
	}
};

int main(void)
{
	//Scala�����е�map()ӳ�亯������ӦC++�е�std::for_each()��std::transform()��
	list<int> numbers = {4,5,8,2,1,6,9,7,3,0};
	for_each(numbers.begin(),numbers.end(),print<int>);
	cout<<endl;
	
	list<int> seq(numbers.size());
	transform(numbers.begin(),numbers.end(),seq.begin(),[](int n){return n + 1;});
	for_each(seq.begin(),seq.end(),Show<int>());
	cout<<endl;
	
	for_each(seq.begin(),seq.end(),[](int& n){n *= 2;});
	for_each(seq.begin(),seq.end(),[](int n){cout<<n<<" ";});
	cout<<endl<<endl;
	
	//Scala�����е�filter()���˺�������ӦC++�е�std::remove_if��std::copy_if()��
	list<int> arr(numbers.size());
#ifndef _CHANGE_WAY_
	list<int>::iterator iter = copy_if(numbers.begin(),numbers.end(),arr.begin(),IsOdd());
#else
	list<int>::iterator iter = copy_if(numbers.begin(),numbers.end(),arr.begin(),not1(IsOdd()));
#endif
	arr.resize(distance(arr.begin(),iter));
	for_each(arr.begin(),arr.end(),print<int>);
	cout<<endl;

#ifndef _CHANGE_WAY_
	iter = remove_if(arr.begin(),arr.end(),bind2nd(less<int>(),5));
#else
	iter = remove_if(arr.begin(),arr.end(),[](int n){return n < 5;});
#endif
	arr.resize(distance(arr.begin(),iter));
	for_each(arr.begin(),arr.end(),Show<int>());
	cout<<endl<<endl;
	
	//Scala�����е�fold()�۵���������ӦC++�е�std::accumulate()��
#ifndef _CHANGE_WAY_
	int sum = accumulate(numbers.begin(),numbers.end(),0);
#else
	int sum = accumulate(numbers.begin(),numbers.end(),100);
#endif
	cout<<"sum ="<<sum<<endl<<endl;
	
	//Scala�����е�compose()��Ϻ�������ӦC++�е�compose1()��compose2()��
	Foo f;
	Bar g;
	
	double ret = compose1(f,g)(5);
	cout<<"Foo(Bar(x)) = (x * x)*2 + 1 : (5 * 5) * 2 + 1 ="<<ret<<endl;

#ifndef _CHANGE_WAY_
	std::function<double(double)> h = compose1(g,f);
#else
	auto h = compose1(Bar(),Foo());
#endif
	cout<<"Bar(Foo(x)) = (x*2 + 1)^2 : (5 * 2 + 1)^2 ="<<h(5)<<endl;
	
	Qux z;
	ret = compose2(z,f,g)(3.14);
	cout<<"x*2 + 1 + x^2 : 3.14*2 + 1 + 3.14^2 ="<<ret<<endl;

#ifndef _CHANGE_WAY_
	std::function<double(double)> t = compose2(z,g,f);
#else
	auto t = compose2(Qux(),Bar(),Foo());
#endif
	cout<<"Qux(Bar(x),Foo(x)) = x^2 + x*2 + 1 : 2.618^2 + 2.618*2 + 1 ="<<t(2.618)<<endl;

	return 0;
}
