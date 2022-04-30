#include "stdafx.h"    //使用预编译头后，每一个.cpp文件的开头都要包含预编译头文件#include "stdafx.h"
#include "util.h"

using namespace std;

int main(void)
{
	vector<int> vec = {1,2,3,4,5};
	for(int n : twice(vec))
	{
		cout<<n<<" ";
	}
	cout<<endl;
	
	for(int n : square(vec))
	{
		cout<<n<<" ";
	}
	cout<<endl;
	
	int ret = summate(vec);
	cout<<"summate: "<<ret<<endl;
	
	int result = product(vec);
	cout<<"product: "<<result<<endl;
	
	vector<string> seq = {"hello"," ","world"," ","C","/","C++"};
	string str = concat(seq);
	cout<<"concat: "<<str<<endl;
	
	return 0;
}