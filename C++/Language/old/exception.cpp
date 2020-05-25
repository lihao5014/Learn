#include <iostream>

using namespace std;

void f(int n)
{
	cout <<"f("<<n<<")"<<endl;
	if(1==n) throw 1;
	if(2==n) throw 'a';
	if(3==n) throw 3.14;
}

int main()
{
	try{
//		f(1);
//		f(2);
		f(3);		
	}catch(int x){
		cout << "int x ="<<x<<endl;
	}catch(char x){
		cout <<"char x ="<<x<<endl;
	}catch(double x){
		cout <<"double x ="<<x<<endl;
	}
	
	cout <<"程序运行结束"<<endl;
	return 0;
}