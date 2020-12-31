#include <iostream>
#include <string>

using namespace std;

template <class T>
T add(const T& x,const T& y)
{
	cout <<"函数模板"<<endl;
	return x+y;
}

template <>
string add(const string& x,const string& y)      //函数模板特例化时，可以更改其函数实现，使其行为与通用模板不一致。
{
	cout<<"Specialized template for string type"<<endl;
	return x + y;
}

int main()
{
	int i=3,j=4;
	double m=2.12,n=3.34;
	string x="hello",y="world";
	
	cout<<i<<" + "<<j<<" ="<<add(i,j)<<endl;
	cout<<m<<" + "<<n<<" ="<<add(m,n)<<endl;            //函数模板隐式具体化
	
	cout<<m<<" + "<<n<<" ="<<add<double>(m,n)<<endl;    //函数模板显示具体化
	
	string z = add(x,y);
	cout<<x<<" + "<<y<<" ="<<z<<endl;                    //函数模板对string类型特例化
	
	return 0;
}