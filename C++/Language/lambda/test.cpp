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