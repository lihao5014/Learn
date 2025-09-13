/**
 *1.手动编译cmake项目：
 *（1）cmake -S . -B build
 *（2）cmake --build build
 *
 *2.Batch脚本编译cmake项目：
 *（1）mkdir build && cd build
 *（2）cmake ..
 *（3）cmake --build
 */

#include <iostream>

using namespace std;

int main(int argc,char* argv[])
{
	cout<<"hello cmake!"<<endl;
	return 0;
}