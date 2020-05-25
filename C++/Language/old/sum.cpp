#include<iostream>

using namespace std;

int main()
{
	int a,b;
	
	cout<<"请输入a与b的值："<<endl;
	while(cin>>a>>b){
		cout<<a<<"+"<<b<<"="<<a+b<<endl;
		cout<<"请输入a与b的值：(输入q退出)"<<endl;
	}
	return 0;
}