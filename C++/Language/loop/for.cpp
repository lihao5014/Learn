#include <iostream>
#include <utility>   //pair��C++98���Ѿ������׼����

#ifdef HAS_CPP_11
#include <tuple>     //tuple����C++11�������׼��ġ�
#endif

#define _ERROR_
#undef _ERROR_

using namespace std;

/*C++��forѭ���ڳ�ʼ��ʱ������ֱ�Ӷ��岢��ʼ�������ͬ���͵ı��������Ƕ��ڲ�ͬ���͵ı���
 *�ǲ�����ֱ�ӳ�ʼ���ġ�����ﵽ��forѭ���ж���������͵�ѭ������Ч��������Ҫʹ��C++����
 *�����ݽṹ���������͵ı�����װΪ�����������е�����
 */
int main(void)
{
#ifdef _ERROR_
	for(int i=0,double j = 3.14;i<5;++i,++j)
	{
		cout<<"i="<<i<<" ,j="<<j<<endl;
	}
#endif
	
	//forѭ���п���ֱ�Ӷ��岢��ʼ������������ͬ���͵ı�����
	for(int i=0,j = 10;i<5;++i,++j)
	{
		cout<<"C++98 variables type is same: i="<<i<<" ,j="<<j<<endl;
	}
	
	int a;
	double b;
	for(a = 20,b = 2.718;a<25;a++,b++)    //forѭ���ĳ�ʼ�������������Ϊ������ͬ���͵ı�����ֵ��
	{
		cout<<"C++98 variables is defined outside of loop: a="<<a<<" ,b="<<b<<endl;
	}
	
	//forѭ����ʹ�ýṹ���ʼ����ͬ���͵�����������
	for(struct {int m;double n;} s = {30,1.414};s.m<35;s.m++,s.n++)
	{
		cout<<"C++98 struct: s.m="<<s.m<<" ,s.n="<<s.n<<endl;
	}
	
	//ʹ��std::pair��ʼ��������ͬ���͵ı������Ͻṹ�巽������ֱ�ӳ�ʼ�������������͵ı�����
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
	//C++17�еĽṹ������䣬���Լ�pair��tuple�����͵Ĳ��������
	for(auto [u,w] = make_tuple(60,1.732);u<65;u++,w++)
	{
		cout<<"C++17 Structured binding: u="<<u<<" ,w="<<w<<endl;
	}
#endif
	
	return	0;
}