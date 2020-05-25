#include <iostream>

using namespace std;

class Sample
{
public:
	Sample(){
		cout<<"Sample constructor"<<endl;
//		throw 1;							//因为在构造函数中抛出异常，所以Sample对象不会构造成功
	}
	
	~Sample(){
		cout<<"Sample destructor"<<endl;
	}
};

int main()
{
	try{
		Sample s;
		throw 1;
	}catch(int){
		cout<<"出现异常"<<endl;
	}
	
	return 0;
}