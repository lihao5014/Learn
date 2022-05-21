/*1.C/C++�������˽�����Ժͷ����ķ�ʽ:
 *��1��C���Կ���ͨ�����������struct�ṹ���ʵ��ϸ�ڡ�
 *��2��C++���Կ���ʹ��Pimpl�������ǽ������class���ʵ��ϸ�ڡ�
 *��3��C++���Կ���ʹ�ù�������ģʽ������class���ʵ��ϸ�ڡ�
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