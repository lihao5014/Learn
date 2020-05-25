#include <iostream>

using namespace std;

bool isZero(int x);
double division(int x,int y);

int main()
{
	try{
		cout<<"7/2 = "<<division(7,2)<<endl;
		cout<<"7/0 = "<<division(7,0)<<endl;
		cout<<"7/3 = "<<division(7,3)<<endl;
	}catch(int x){
		cout<<"x="<<x<<endl;
	}catch(...){
		cout<<"main other exception"<<endl;
	}
	
	return 0;
}

bool isZero(int x)
{
	if(x == 0){
		cout<<"isZero throw exception"<<endl;
		throw x;
	}
	
	return false;
}

double division(int x,int y)
{
	try{
		isZero(y);
		return (double)x/y;
	}catch(int x){
		cout<<"division throw exception"<<endl;
		throw x;
	}catch(...){
		cout<<"division other exception"<<endl;
		throw "exceptions";
	}
}