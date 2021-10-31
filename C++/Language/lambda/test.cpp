/*1.C++11中的Lambda表达式捕获外部变量主要形式：
 *（1）[] ：不捕获任何外部变量。
 *（2）[变量名, …] ：默认以值得形式捕获指定的多个外部变量（用逗号分隔），如果引用捕获，需要使用&说明符显示声明。
 *（3）[this] ：以值的形式捕获this指针。
 *（4）[=] ：以值的形式捕获所有外部变量。
 *（5）[&] ：以引用形式捕获所有外部变量。
 *（6）[=, &x] ：变量x以引用形式捕获，其余变量以传值形式捕获。
 *（7）[&, x] ：变量x以值的形式捕获，其余变量以引用形式捕获。
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