#include <iostream>

using namespace std;

const int N = 5;

static int a[N] = {1,2,3,4,5};      //gcc����ʹ�ñ�������������Ĵ�С

int check(int n)throw(int);			//C++11�Ѿ��Ƴ����ں���ͷ��дthrow���÷�

int main()
{
	try{
		cout<<"a[1] ="<<check(1)<<endl;		
		cout<<"a[10] ="<<check(10)<<endl;		
		cout<<"a[3] ="<<check(3)<<endl;		
	}catch(int n){
		cout<<n<<" �����±�Խ��"<<endl;
	}
	
	return 0;
}

int check(int n)throw(int)
{
	if(n<0 || n >= N)throw n;
	return a[n];
}
