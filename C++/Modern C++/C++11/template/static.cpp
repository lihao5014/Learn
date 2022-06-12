//模板类的声明和实现都只能在一个头文件或源文件中完成

#include <iostream>

#define _CHANGE_WAY_
#undef _CHANGE_WAY_

using namespace std;

template <typename T>
class Sample
{
public:
	Sample(T x=0,T y=0):x(x),y(y){};
	~Sample(){}
	
	void setX(const T x);
	T& getX()const;
	
	void setY(const T x);
	T& getY()const;
	
	void display()const;
private:
	static T x;
	static int y;
};

#ifndef _CHANGE_WAY_
template <typename T>
T Sample<T>::x = 0;

template <typename T>
int Sample<T>::y = 0;
#else
template<>
int Sample<int>::x = 0;

template<>
double Sample<double>::x = 0.0;

template<>
int Sample<int>::y = 0;

template<>
int Sample<double>::y = 0;
#endif

template <typename T>
void Sample<T>::setX(const T x)
{
	this->x = x;
}

template <typename T>
T& Sample<T>::getX()const
{
	return x;
}

template <typename T>
void Sample<T>::setY(const T y)
{
	this->y = y;
}

template <typename T>
T& Sample<T>::getY()const
{
	return y;
}

template <typename T>
void Sample<T>::display()const
{
	cout << "x ="<<x<<" , y ="<<y<<endl;
}

int main()
{
	Sample<int> s1(10);
	s1.display();
	
	Sample<double> s2(3.14);
	s2.display();
	
	return 0;
}