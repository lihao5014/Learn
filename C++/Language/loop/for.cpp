#include <iostream>
#include <utility>   //pair在C++98就已经引入标准库了

#ifdef HAS_CPP_11
#include <tuple>     //tuple是在C++11才引入标准库的。
#endif

#define _ERROR_
#undef _ERROR_

using namespace std;

/*C++的for循环在初始化时，可以直接定义并初始化多个相同类型的变量，但是对于不同类型的变量
 *是不可以直接初始化的。若想达到在for循环中定义多种类型的循环变量效果，则需要使用C++特有
 *的数据结构将多种类型的变量包装为单个变量进行迭代。
 */
int main(void)
{
#ifdef _ERROR_
	for(int i=0,double j = 3.14;i<5;++i,++j)
	{
		cout<<"i="<<i<<" ,j="<<j<<endl;
	}
#endif
	
	//for循环中可以直接定义并初始化两个变量相同类型的变量。
	for(int i=0,j = 10;i<5;++i,++j)
	{
		cout<<"C++98 variables type is same: i="<<i<<" ,j="<<j<<endl;
	}
	
	int a;
	double b;
	for(a = 20,b = 2.718;a<25;a++,b++)    //for循环的初始化语句区，可以为两个不同类型的变量赋值。
	{
		cout<<"C++98 variables is defined outside of loop: a="<<a<<" ,b="<<b<<endl;
	}
	
	//for循环中使用结构体初始化不同类型的两个变量。
	for(struct {int m;double n;} s = {30,1.414};s.m<35;s.m++,s.n++)
	{
		cout<<"C++98 struct: s.m="<<s.m<<" ,s.n="<<s.n<<endl;
	}
	
	//使用std::pair初始化两个不同类型的变量，较结构体方法不能直接初始化两个以上类型的变量。
	for(pair<int,double> pr(40,0.618);pr.first<45;pr.first++,pr.second++)
	{
		cout<<"C++98 pair: pr.first="<<pr.first<<" ,pr.second="<<pr.second<<endl;
	}
	
#ifdef HAS_CPP_11
	for(tuple<int,double> tp(50,9.78);get<0>(tp)<55;get<0>(tp)++,get<1>(tp)++)
	{
		cout<<"C++11 tuple: get<0>(tp)="<<get<0>(tp)<<" ,get<1>(tp)="<<get<1>(tp)<<endl;
	}
#endif
	
#ifdef HAS_CPP_17
	//C++17中的结构化绑定语句，可以简化pair和tuple等类型的拆包工作。
	for(auto [u,w] = make_tuple(60,1.732);u<65;u++,w++)
	{
		cout<<"C++17 Structured binding: u="<<u<<" ,w="<<w<<endl;
	}
#endif
	
	return	0;
}