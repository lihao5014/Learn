#include <iostream>
#include <string>

using namespace std;

template<typename T>
void check(const T n);

int main()
{
	try{
		check(2);
		check(1);
		check('a');
		check(3.14);
	}catch(int e){
		cout<<"捕获整型类型："<<e<<endl;
		return false;
	}catch(char e){
		cout<<"捕获字符型类型："<<e<<endl;
		return false;
	}catch(double e){
		cout<<"捕获浮点型类型："<<e<<endl;
		return false;
	}catch(...){
		cout<<"默认捕获："<<endl;
		return false;		
	}
	
	return 0;
}

template<typename T>
void check(const T n)
{
	if(n == 1) throw n;
	if(n == 'a') throw 'q';
	if(n == 3.14) throw 3.14;
	
	cout<<"无异常"<<endl;
}