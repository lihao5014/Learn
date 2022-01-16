#include <iostream>
#include "mymath.h"

using namespace std;

int main(void)
{
	//虽然mymath.h头文件中没有说明add()是一个C函数，但是只要C++代码中不调用方法，编译器就不会报错。
	// cout<<"3 + 4 ="<<add(3,4)<<endl;
	
	cout<<"8 - 5 ="<<sub(8,5)<<endl;
	cout<<"6 * 7 ="<<mult(6,7)<<endl;
	cout<<"9 / 2 ="<<divi(9,2)<<endl;
	
	cout<<"max(3.14159,2.17828) ="<<max(3.14159,2.17828)<<endl;
	cout<<"min(0.618,1.144) ="<<min(0.618,1.144)<<endl;
	
	cout<<"C++ version: "<<__cplusplus<<endl;
	
	return 0;
}