#include <iostream>

using namespace std;

template <class T>
T add(const T& x,const T& y)
{
	cout <<"º¯ÊýÄ£°å"<<endl;
	return x+y;
}

int main()
{
	int i=3,j=4;
	double m=2.12,n=3.34;
	
	cout <<i<<"+"<<j<<" ="<<add(i,j)<<endl;
	cout <<m<<"+"<<n<<" ="<<add(m,n)<<endl;
	return 0;
}