#include "dog.h"

int main(void)
{
	Dog dog1("curly","red",5);
	dog1.detail();
	cout<<endl;
	
	Dog dog2 = dog1;        //调用Dog的拷贝构造函数
	dog2.detail();
	
	return 0;
}