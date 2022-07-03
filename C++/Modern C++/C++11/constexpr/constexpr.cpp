/*1.constexpr���κ������������4����������constexpr���ǿ����޸����⺯���ķ���ֵ��ʹ���Ϊ�������ʽ������
 *��1�����������ĺ������У����˿��԰���usingָ�typedef����Լ�static_assert�����⣬
 *     ֻ�ܰ���һ��return������䡣�������ʽ������return����в��ܰ�����ֵ�Ĳ�����
 *     constexpr���κ���ʱ����������֧�ֵݹ�ġ�
 *��2�����������з���ֵ���������ķ���ֵ���Ͳ�����void��������Ϊ����ֵΪ�յĺ���
 *     �����޷����һ��������
 *��3��������ʹ��֮ǰ�������ж�Ӧ�Ķ�����䡣������ʹ�÷�Ϊ���������͡����塱�����֣�
 *     ��ͨ�ĺ�������ֻ��Ҫ��ǰд�øú������������ּ��ɣ������Ķ��岿�ֿ��Է���
 *     ����λ��֮�����������ļ��С����������ʽ������ʹ��ǰ������Ҫ�иú����Ķ��塣
 *��4������return���صı��ʽ�����ǳ������ʽ���������ʽ�����ķ���ֵ�����ǳ���
 *     ���ʽ��ԭ��ܼ򵥣�������ڳ������׶λ��ĳ���������صĳ�������ú���
 *     ��return����оͲ��ܰ����������н׶β���ȷ��ֵ�ı�����
 */

/*constexpr���������κ����������еĳ�Ա������ȫ���Կ����ǡ�λ������������ռ��еĺ�������
 *����constexprҲ�����������еĳ�Ա������ֻ�����˺�����������constexpr������ͨ������4��������
 */

/*2.constexpr���ι��캯����
 *��1������C++�������͵����ݣ�����ֱ����constexpr���Σ��������struct/class�������Զ����������ͣ�
 *     ֱ����constexpr�����ǲ��еġ�
 *��2��������Զ���һ���ɲ�������������ʱ����ȷ���������ڸ����͵��ڲ����һ���������캯����
 *��3��constexpr������Ĺ��캯��ʱ��Ҫ��ù��캯���ĺ��������Ϊ�գ��Ҳ��ó�ʼ���б�ķ�ʽΪ
 *     ������Ա��ֵʱ������ʹ�ó������ʽ��
 *��4��C++11��׼�У���֧����constexpr���δ���virtual�ĳ�Ա������
 */

/*3.constexpr����ģ�庯����
 *C++11�﷨�У�constexpr��������ģ�庯����������ģ�������͵Ĳ�ȷ���ԣ����ģ�庯��ʵ������ĺ���
 *�Ƿ���ϳ������ʽ������Ҫ��Ҳ�ǲ�ȷ���ġ�C++11��׼�涨�����constexpr���ε�ģ�庯��ʵ�������
 *�����㳣�����ʽ������Ҫ����constexpr�ᱻ�Զ����ԣ����ú����͵�ͬ��һ����ͨ������
 */

/*4.constexpr��const������
 *��1��constexpr��C++11��׼����ӵĹؼ��֣��ڴ�֮ǰ��C++98/03��׼��ֻ��const�ؼ��֡�
 *     ��const�ؼ�����ʹ�ù����о�������ֳ����������͡�ֻ�������ֲ�ͬ�����塣
 *��2��C++11��׼�У�Ϊ�˽��const�ؼ��ֵ�˫���������⣬������const��ʾ��ֻ���������壬
 *     �����������������廮�ָ�������ӵ�constexpr�ؼ��֡����C++11��׼�У����齫const
 *     ��constexpr�Ĺ������ֿ��������Ǳ�ֻ��������ĳ�����ʹ��const��������������
 *     �ĳ�����ʹ��constexpr��
 *��3���ڴ󲿷�ʵ�ʳ����У�const��constexpr�ǿ��Ի��õģ���������ȫ�ȼ۵ģ���������
 *     ����ı���׶μ�������������ĳЩ�����У�������ȷʹ��constexpr��
 *��4��C++11��׼�У�const����Ϊ���εı�����ӡ�ֻ�������ԣ���constexpr�ؼ���������ָ��
 *     �����һ�������������ʽ���������ڱ������ʱ����˳�����������������������
 *     �ȵ��������н׶Σ��������Ż����������˳����ִ��Ч�ʡ�
 */

#include <iostream>
#include <string>
#include <array>
#include <list>

#define _ERROR_
#undef _ERROR_

#define _CHANGE_WAY_
// #undef _CHANGE_WAY_

#ifndef _ERROR_
#define ConstExpr constexpr
#else
#define ConstExpr
#endif

#define ToString(x) #x
#define TOSTRING(x) ToString(x)

using namespace std;

#ifdef _ERROR_
const int square(int num)       //��ͨ�����ķ���ֵ�������ٴ�������ھͼ��������
{
	return num * num;
}
#else
constexpr int square(int num)    //�������ʽ�����ķ���ֵ�������ڴ������׶ξͼ��������
{
	return num * num;
}	
#endif

#ifdef _ERROR_
struct Person
{
	std::string m_name;    //std::string��������ֵ���ͣ����Բ��ܶ���Ϊconstexpr
	int m_age;
};
#else
struct Person
{
	const char* m_name;
	int m_age;
};
#endif

#ifndef _CHANGE_WAY_
struct Point
{
	int x;
	int y;
};
#else
class Point
{
public:
	ConstExpr Point():x(0),y(0){}
	ConstExpr Point(int x,int y):x(x),y(y){}
	
	void setX(int x){this->x = x;}
	ConstExpr int getX()const{return x;}
	
	void setY(int y){this->y = y;}
	ConstExpr int getY()const{return y;}
	
	//show()�����������const���Σ�����const Point/constexpr Point�������ܵ���non-const������
	void show()const{cout<<"("<<x<<","<<y<<")"<<endl;}
private:
	int x;
	int y;
};
#endif

class Sample
{
public:
	constexpr Sample():m_value(0){}
	constexpr Sample(int value):m_value(value){}
	
	void setValue(int value){m_value = value;}
	constexpr int getValue()const{return m_value;}
	
	void display()const{cout<<"m_value ="<<m_value<<endl;}
private:
	int m_value;
};

template <int N>
struct constN
{
	constN(){cout<<"constN: N ="<<N<<endl;}
};

template <int num>
int func()
{
	cout<<"func: num ="<<num<<endl;
	return num;
}

int main(int argc,char** argv)
{
	cout<<"C++ version: "<<endl;

#ifdef _ERROR_
	constexpr std::string str = "constexpr std::string , error";
#else
	constexpr const char* str = "constexpr const char* , right";
#endif
	cout<<"str ="<<str<<endl;

	std::array<int,square(3)> myarray;    //����ʹ�÷���ֵΪconstexpr�ĺ�����������ʹ�÷���ֵΪconst�ĺ�����
	cout<<"myarray.size() ="<<myarray.size()<<endl;

#ifdef _ERROR_
	constexpr list<int> seq = {1,2,3,4,5};
#else
	constexpr int seq[] = {1,2,3,4,5};

	enum {
		A = seq[0],
		B = seq[1],
		C = seq[2]
	};
	
	cout<<"A ="<<A<<" , B ="<<B<<" , C ="<<C<<endl;
#endif
	
	constexpr Person person = {"amy",25};
	cout<<"name ="<<person.m_name<<" , age ="<<person.m_age<<endl;

	constexpr Point point = {3,4};
#ifndef _CHANGE_WAY_
	cout<<"x ="<<point.x<<" , y ="<<point.y<<endl;
	constexpr int len = point.x + point.y;
#else
	point.show();
	constexpr int len = point.getX() + point.getY();
#endif
	int arr[len] = {0};        //g++����ʹ�ñ�����Ϊ����Ĵ�С
	cout<<"arr len ="<<sizeof(arr)/sizeof(arr[0])<<endl;
	
	constexpr Sample sample(10);
	constN<sample.getValue()> out;
	
#ifdef _ERROR_
	sample.setValue(20);     //constexpr�������ܵ��÷�const����
#endif
	sample.display();
	
	int num = 15;
	Sample sample1(num);
	sample1.display();
#ifdef _ERROR_
	func<sample1.getValue()>();
#endif
	sample1.setValue(25);
	cout<<"sample1.getValue() ="<<sample1.getValue()<<endl;
	
	return 0;
}