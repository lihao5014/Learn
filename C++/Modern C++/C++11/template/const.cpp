#include <iostream>
#include <memory>

#define _ERROR_
#undef _ERROR_

using namespace std;

template <typename T>
struct Data
{
	const char* m_pinfo;
	T m_value;
	
	Data(const T& val = 0):m_value(val),m_pinfo("non-const type"){}
	Data(const Data& other):m_value(other.m_value),m_pinfo(other.m_pinfo){}
	
	Data<const T> to_const(){return Data<const T>(m_value);}
	
	void print()
	{
		cout<<"print(): "<<m_pinfo<<": "<<m_value<<endl;
	}
};

template <typename T>
struct Data<const T>
{
	const char* m_pinfo;
	const T m_value;
	
	Data<const T>(const T& val = 0):m_value(val),m_pinfo("const type"){}
	Data<const T>(const Data<T>& other):m_value(other.m_value),m_pinfo("const type"){}          //不属于拷贝构造函数，非const类型转换为const类型的构造函数
	Data<const T>(const Data<const T>& other):m_value(other.m_value),m_pinfo(other.m_pinfo){}   //真正拷贝构造函数
	
	void print()
	{
		cout<<"print(): "<<m_pinfo<<": "<<m_value<<endl;
	}
};

template <class T>
void displayData(const T& data)
{
	cout<<"displayData(): "<<data.m_pinfo<<": "<<data.m_value<<endl;
}

auto main(void) -> int
{
	//测试非const版本Data
	Data<int> data1(5);
	data1.print();
	
	data1.m_value = 7;
	displayData(data1);
	
	Data<int> data2(data1);
	data2.print();
	
	//测试const版本Data
	Data<const int> cdata1(11);
	cdata1.print();
	
#ifdef _ERROR_
	cdata1.m_value = 13;
#endif
	displayData(cdata1);
	
	Data<const int> cdata2(cdata1);
	cdata2.print();
	
	/*Data<int>到Data<const int>的类型转换，只能通过Data<const int>的构造函数和赋值运算符"="，
	 *或Data<int>的成员方法完成。而无法通过const_cast()或std::const_pointer_cast()类型强制转换实现。
	 */
	Data<const int> cdata3(data1);
	displayData(cdata3);
	
	Data<const int> cdata4 = data1.to_const();
	cdata4.print();
	
	shared_ptr<Data<int>> dataPtr = make_shared<Data<int>>(17);
	dataPtr->print();
	
	shared_ptr<Data<const int>> cdataPtr(new Data<const int>(*dataPtr));
	displayData(*cdataPtr);
	
	return 0;
}