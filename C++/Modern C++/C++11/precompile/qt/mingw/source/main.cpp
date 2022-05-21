/*1.C/C++类库隐藏私有属性和方法的方式:
 *（1）C语言可以通过句柄，隐藏struct结构体的实现细节。
 *（2）C++语言可以使用Pimpl编译防火墙，隐藏class类的实现细节。
 *（3）C++语言可以使用工厂方法模式，隐藏class类的实现细节。
 */

#include "stable.h"

#define UNUSED(x) (void)x

using namespace std;

int main(int argc,char* argv[])
{
	UNUSED(argc);
	UNUSED(argv);
	
	unique_ptr<IFactory> pfactory(new DataAcquirerFactory);
	shared_ptr<DataAcquirerAbstract> pdataAcquirer = pfactory->createDataAcquirer("../bin/file/test.txt");
	string text = pdataAcquirer->getData();
	
	cout<<"file context:"<<endl;
	cout<<text<<endl;

	return 0;
}