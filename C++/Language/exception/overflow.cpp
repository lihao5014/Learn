#include <iostream>

using namespace std;

const int N = 5;

static int a[N] = {1,2,3,4,5};      //gcc允许使用变量来定义数组的大小

int check(int n)throw(int);			//C++11已经移除了在函数头后写throw的用法

int main()
{
	try{
		cout<<"a[1] ="<<check(1)<<endl;		
		cout<<"a[10] ="<<check(10)<<endl;		
		cout<<"a[3] ="<<check(3)<<endl;		
	}catch(int n){
		cout<<n<<" 数组下标越界"<<endl;
	}
	
	return 0;
}

int check(int n)throw(int)
{
	if(n<0 || n >= N)throw n;
	return a[n];
}
