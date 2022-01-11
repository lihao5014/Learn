#include <iostream>
#include <string>
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
struct Person
{
	std::string m_name;    //std::string不是字面值类型，所以不能定义为constexpr
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
	
	//show()方法必须添加const修饰，否则const Point/constexpr Point常量不能调用non-const方法。
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
	int arr[len] = {0};        //g++可以使用变量作为数组的大小
	cout<<"arr len ="<<sizeof(arr)/sizeof(arr[0])<<endl;
	
	constexpr Sample sample(10);
	constN<sample.getValue()> out;
	
#ifdef _ERROR_
	sample.setValue(20);     //constexpr常量不能调用非const方法
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