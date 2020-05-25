#include <iostream>

using namespace std;

//声明交换两个数函数
static inline void swap(double &a,double &b);
static inline void swap(double* const a,double* const b);

static inline void swap(int &a,int &b);
static inline void swap(int* const a,int* const b);

int main()
{
	int a=0,b=0;
//提示输入两个数
	cout<<"请输入两个整数："<<endl;
//输入两个数
	cin>>a>>b;
//打印输入的两个数
	cout<<"a = "<<a<<" , "<<"b = "<<b<<endl;
//交换输入的两个数
	swap(a,b);
//打印交换后的结果
	cout<<"a = "<<a<<" , "<<"b = "<<b<<endl;
	
	double x=0,y=0;
	cout<<"请输入两个浮点数："<<endl;
	cin>>x>>y;
	cout<<"x = "<<x<<" , "<<"y = "<<y<<endl;
	swap(x,y);
	cout<<"x = "<<x<<" , "<<"y = "<<y<<endl;
	
	return 0;
}

void swap(double &a,double &b)
{
	double temp = a;
	a = b;
	b = temp;
}

static void swap(double* const a,double* const b)
{
	double temp = *a;
	*a = *b;
	*b = temp;	
}

inline void swap(int &a,int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

static inline void swap(int* const a,int* const b)
{
	int temp = *a;
	*a = *b;
	*b = temp;		
}