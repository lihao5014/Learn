/*1.C++11�е�Lambda���ʽ�����ⲿ������Ҫ��ʽ��
 *��1��[] ���������κ��ⲿ������
 *��2��[������, ��] ��Ĭ����ֵ����ʽ����ָ���Ķ���ⲿ�������ö��ŷָ�����������ò�����Ҫʹ��&˵������ʾ������
 *��3��[this] ����ֵ����ʽ����thisָ�롣
 *��4��[=] ����ֵ����ʽ���������ⲿ������
 *��5��[&] ����������ʽ���������ⲿ������
 *��6��[=, &x] ������x��������ʽ������������Դ�ֵ��ʽ����
 *��7��[&, x] ������x��ֵ����ʽ�������������������ʽ����
 */

#include <iostream>

using namespace std;

namespace math
{
	int add(int x,int y)
	{
		return x+y;
	}
	
	int multiply(int x,int y)
	{
		return x*y;
	}
}

int main()
{
	int x = 0;
	auto add = [](int a, int b) -> int { return a + b; };
	auto multiply = [&x](int a, int b) { x = a * b;return x;};
	auto sub = [&](int a, int b) { x = a - b;return x;};
	
	cout<<" x =" <<x<<endl;
	int y = 2;
	auto division = [=](int a)->int{return a/y;};
	
	cout<<"add ="<<add(1,2)<<endl;
	cout<<"x ="<<multiply(3,4)<<endl;
	cout<<"sub ="<<sub(8,4)<<endl;
	cout<<"division ="<<division(8)<<endl;

	cout<<"math::add ="<<math::add(1,2)<<endl;
	cout<<"math::multiply ="<<math::multiply(3,4)<<endl;	
	
	return 0;
}