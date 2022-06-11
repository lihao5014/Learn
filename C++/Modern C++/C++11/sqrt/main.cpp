#include <iostream>
#include "sqrt.hpp"

#define EPSINON 0.000001

using namespace std;

//运行期使用二分法查找算法，求一个数的平方根
double sqrt(double num)
{
	if(num < EPSINON)
	{
		cout<<"sqrt() error: num is negative"<<endl;
		return -1;
	}
	
	double low = 0;
	double high = num;
	double mid = (low + high)/2;
	while((high - low) > EPSINON)
	{
		if(mid * mid > num)
		{
			high = mid;
		}
		else
		{
			low = mid;
		}
		
		mid = (low + high)/2;
	}
	
	return mid;
}

//模板输出要求编译期常量的元函数，用于测试一个表达式是否为常量表达式。
template <int N>
struct constN
{
	constN(){cout<<"constN: "<<N<<endl;}
};

int main(void)
{
	cout<<"sqrt(4) ="<<sqrt(4)<<endl;
	cout<<"sqrt(8) ="<<sqrt(8)<<endl;
	
	constexpr int ret = Sqrt<9>::result;
	cout<<"sqrt(9) ="<<ret<<endl;
	
	constN<Sqrt<16>::result>();
	
	return 0;
}