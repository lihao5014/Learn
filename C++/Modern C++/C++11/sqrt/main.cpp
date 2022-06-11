#include <iostream>
#include "sqrt.hpp"

#define EPSINON 0.000001

using namespace std;

//������ʹ�ö��ַ������㷨����һ������ƽ����
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

//ģ�����Ҫ������ڳ�����Ԫ���������ڲ���һ�����ʽ�Ƿ�Ϊ�������ʽ��
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