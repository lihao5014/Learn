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
	Data<const T>(const Data<T>& other):m_value(other.m_value),m_pinfo("const type"){}          //�����ڿ������캯������const����ת��Ϊconst���͵Ĺ��캯��
	Data<const T>(const Data<const T>& other):m_value(other.m_value),m_pinfo(other.m_pinfo){}   //�����������캯��
	
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
	//���Է�const�汾Data
	Data<int> data1(5);
	data1.print();
	
	data1.m_value = 7;
	displayData(data1);
	
	Data<int> data2(data1);
	data2.print();
	
	//����const�汾Data
	Data<const int> cdata1(11);
	cdata1.print();
	
#ifdef _ERROR_
	cdata1.m_value = 13;
#endif
	displayData(cdata1);
	
	Data<const int> cdata2(cdata1);
	cdata2.print();
	
	/*Data<int>��Data<const int>������ת����ֻ��ͨ��Data<const int>�Ĺ��캯���͸�ֵ�����"="��
	 *��Data<int>�ĳ�Ա������ɡ����޷�ͨ��const_cast()��std::const_pointer_cast()����ǿ��ת��ʵ�֡�
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