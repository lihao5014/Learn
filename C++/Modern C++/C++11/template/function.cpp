#include <iostream>
#include <string>

using namespace std;

template <typename T,typename U>
void foo(T x,U y)
{
	cout<<"foo() function template: x ="<<x<<" ,y ="<<y<<endl;
}

//完全特化，全特化
template <>
void foo(string x,string y)
{
	cout<<"foo() full specialization: x ="<<x<<" ,y ="<<y<<endl;
}

//局部特例化，部分特例化，偏特化
template <typename T>
void foo(T x,const char* y)
{
	cout<<"foo() partial specialization: x ="<<x<<" ,y ="<<y<<endl;
}

class Sample
{
public:
	Sample(int n){this->n = n;}
	void setNum(const int n){this->n = n;}
	int& getNum(){return n;}
	void display()const{cout << "n ="<<n<<endl;}
	
	bool operator <(const Sample& s){return n < s.n;}
	bool operator >(const Sample& s){return n > s.n;}
	bool operator ==(const Sample& s){return n == s.n;}
	
	friend ostream& operator <<(ostream& os,const Sample& s);
	friend istream& operator >>(istream& in,Sample s);
private:
	int n;
};

ostream& operator<<(ostream& os,const Sample& s)
{
	os<<"n="<<s.n<<endl;
	return os;
}

istream& operator >>(istream& in,Sample s)
{
	in>>s.n;
	return in;
}

template <typename T>
void swap(T& x,T& y)
{
	T temp = x;
	x = y;
	y = temp;
}

template <typename T>
T& min(T& x,T& y);

template <class T>
T& max(T& x,T& y);

int main()
{
	foo(3,4);                        //函数模板隐式具体化或隐式实例化
	foo<double,double>(2.718,3.14);  //函数模板显式具体化或显式实例化
	
	string str1 = "hello";
	string str2 = "world";
	foo(str1,str2);               //全特化
	
	foo('a',"C++");               //隐私偏特化
	foo<int>(10,"Qt");            //显示偏特化
	
	cout<<"2.3 and 3.12: min="<<min(2.3,3.12)<<endl;
	cout<<"3 and 4: max="<<max(3,4)<<endl;
	cout<<"s(3) == s(4): "<<(Sample(3) == Sample(4))<<endl;
	cout<<"s(3) < s(4): "<<(Sample(3) < Sample(4))<<endl;
	
	return 0;
}

template <typename T>
T& min(T& x,T& y)
{
	return x < y ? x : y;
}

template <class T>
T& max(T& x,T& y)
{
	return x > y ? x : y;
}